import java.util.Collections;
import java.io.FileNotFoundException;

public class JGeoIpDb {
  public static final boolean USE_CACHE = false;  // no cache support for now
  private static final int MAX_ISP_COUNT = 65535;
  private static final int MAX_CITY_COUNT = 1000000;
  private static final int MAX_RANGE_COUNT = 1000;

  String cache_file_name;

  HashMap<Integer, City> cities;
  ArrayList<String> isps;
  ArrayList<IpRange> ranges;

  public JGeoIpDb(String cities_file_name, String ranges_file_name, String cache_file_name) throws FileNotFoundException {
    cities = new HashMap<Integer, City>();
    isps = new ArrayList<String>();
    ranges = new ArrayList<IpRange>();

    if (USE_CACHE && read_cache_file()) {
      System.out.format("Loaded DB from Cache-File with %d");
    } else {
      read_cities_csv(cities_file_name);
      read_ranges_csv(ranges_file_name);
      if (USE_CACHE)
        write_cache_file();
    }
  }

  public IpRange find_range_for_ip(String ip) {
    if (ranges.length == 0) {
      System.out.println("ERROR: DB has no ranges data. Can not search!");
      return null;
    }

    int index = 0;
    IpRange search = new IpRange(ip, "0", 0, 0, false);
    index = Collections.binarySearch(ranges, search);

    return ranges[index];
  }

  public City find_city_for_ip_range(IpRange range) {
    if (cities.length == 0) {
      System.out.println("ERROR: DB has no city data. Can not search!");
      return null;
    }

    if (range.city_code == 0) {
      System.out.format("ERROR: Could not find city with index: %d\n", range.city_code);
      return null;
    }

    return cities.get(range.city_code);
  }

  private boolean read_cache_file() {
    // TODO
    return false;
  }

  private void write_cache_file() {
    // TODO
  }

  private void read_cities_csv(String file_name) throws FileNotFoundException {
    CsvReader reader = new CsvReader(file_name);
    String[] line = null;
    City city = null;

    reader.readLine(); // skip first line

    while ((line = reader.readLine()) != null) {
      if (cities.length >= MAX_CITY_COUNT){
        System.out.format("ERROR: MAX_CITY_COUNT = %d limit reached - mek it bigger  :-(\n", MAX_CITY_COUNT);
        return;
      }
      city = new City(line);
      cities.put(city.city_code, city);
    }
  }

  private void read_ranges_csv(String file_name) throws FileNotFoundException {
    CsvReader reader = new CsvReader(file_name);
    String[] line = null;
    int isp_index;

    reader.readLine(); // skip first line

    while ((line = reader.readLine()) != null) {
      if (line.length < 5)
        continue;

      if (range_count >= MAX_RANGE_COUNT){
        System.out.format("ERROR: MAX_RANGE_COUNT = %d limit reached - mek it bigger  :-(\n", MAX_RANGE_COUNT);
        return;
      }

      isp_index = isp_index_by_name(line[4]);
      ranges.add(new IpRange(line, isp_index));
    }
  }

  private int isp_index_by_name(String isp_name) {
    if ((isp_name == null) || isp_name.equals(""))
      return -1;

    if (isp_count != 0) {
      for (int index = 0; index < isp_count; index++) {
        if (isps[index].equals(isp_name))
          return index;
      }
    }

    if (isp_count < MAX_ISP_COUNT) {
      isps[isp_count++] = isp_name;
      return isp_count - 1;
    } else {
      System.out.format("ERROR: MAX_ISP_COUNT = %d limit reached - mek it bigger  :-(\n", MAX_ISP_COUNT);
      return -1;
    }
  }
}
