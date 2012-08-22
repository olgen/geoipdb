
public class IpRange implements Comparable<IpRange>{
  int from;
  int to;
  boolean is_mobile;
  int city_code;
  int isp_index;

  public IpRange(String[] range_vals, int isp_index) {
    this.from = ip_to_int(range_vals[0]);
    this.to = ip_to_int(range_vals[1]);
    this.is_mobile = con_type_to_bool(range_vals[2]);
    this.city_code = ip_to_int(range_vals[3]);
    this.isp_index = isp_index;
  }

  public IpRange(String from, String to) {
    this.from = ip_to_int(from);
    this.to = ip_to_int(to);
    this.city_code = city_code;
    this.isp_index = isp_index;
    this.is_mobile = is_mobile;
  }

  private boolean con_type_to_bool(String con_type) {
    return (con_type.length() > 0) && (con_type.charAt(0) == 'm');
  }

  private int ip_to_int(String ip) {
    int result = 0;
    byte octet;

    if (!(ip == null || ip.equals(""))) {
      for(String ip_part : ip.split(".")) {
        octet = Byte.parseByte(ip_part);
        result = result << 8 | (octet & 0xFF);
      }
    }

    return result;
  }

  @Override
  public int compareTo(IpRange other) {
    if (other == null)
      return 0;

    if (this.from > 0 && this.to > 0 && other.from > 0 && other.to > 0) {
      if (this.from < other.from)
        return -1;
      else if (this.from > other.to)
        return 1;
      else
        return 0;
    } else if (this.to == 0 && other.to > 0) {
      if (this.from < other.from)
        return -1;
      else if (this.from > other.to)
        return 1;
      else
        return 0;
    } else if (other.to == 0 && this.to > 0) {
      if (other.from < this.from)
        return -1;
      else if (other.from > this.from)
        return 1;
      else
        return 0;
    } else if (this.to == 0 && other.to == 0)
      return this.from - other.from;
    return 0;
  }
}
