
public class IpRange implements Comparable<IpRange>{
  int from;
  int to;
  boolean is_mobile;
  int city_code;
  String isp_name;

  public IpRange(String[] range_vals) {
    this.from = ip_to_int(range_vals[0]);
    this.to = ip_to_int(range_vals[1]);
    this.is_mobile = con_type_to_bool(range_vals[2]);
    this.city_code = Integer.parseInt(range_vals[3]);

    if (!range_vals[4].equals("?"))
        // Use only the first 100 chars to be compliant with the c implementation
        this.isp_name = range_vals[4].length() > 100 ? range_vals[4].substring(0, 100) : range_vals[4];
  }

  public int getCity_code() {
	return city_code;
}

public void setCity_code(int city_code) {
	this.city_code = city_code;
}

public int getFrom() {
	return from;
}

public int getTo() {
	return to;
}

public boolean isIs_mobile() {
	return is_mobile;
}

public String getIsp_name() {
	return isp_name;
}

public IpRange(String from, String to) {
    this.from = ip_to_int(from);
    this.to = ip_to_int(to);
  }

  public int get_from() {
    return from;
  }

  public int get_to() {
    return to;
  }
  public String get_isp_name(){
	  return isp_name;
  }

  private boolean con_type_to_bool(String con_type) {
    return (con_type.length() > 0) && (con_type.charAt(0) == 'm');
  }

  private int ip_to_int(String ip) {
    int result = 0;
    int power;
    int octet_count = 0;
    String[] addr_array;

    if (!(ip == null || ip.equals(""))) {
        addr_array = ip.split("\\.");
          for (octet_count = 0; octet_count < addr_array.length; octet_count++) {
            power = 3 - octet_count;
            result += ((Integer.parseInt(addr_array[octet_count]) % 256 * Math.pow(256, power)));
          }
    }

    return result;
  }

  @Override
  public int compareTo(IpRange other) {
    if (other == null)
      return 0;

    if (other.from > 0 && other.to > 0 && this.from > 0 && this.to > 0) {
      if (other.from < this.from)
        return 1;
      else if (other.from > this.to)
        return -1;
      else
        return 0;
    } else if (other.to == 0 && this.to > 0) {
      if (other.from < this.from)
        return 1;
      else if (other.from > this.to)
        return -1;
      else
        return 0;
    } else if (this.to == 0 && other.to > 0) {
      if (this.from < other.from)
        return 1;
      else if (this.from > other.from)
        return -1;
      else
        return 0;
    } else if (other.to == 0 && this.to == 0) {
      return other.from - this.from;
    }
    return 0;
  }
}
