# geoipdb: fast (in memory!) geo location db.

Fast (>3 Mio queries/sec!!!) GeoIpDb implementation for Ruby using C/Java-Extensions.

  * Returns a GeoLocation and additional information for a given IP. 
  * Reads Data from CSV-Files and uses internal binary caching.

## Usage

    db = IpDb.init "city_codes.csv", "ip_city.txt", "ip_city.cache"
    ip_info = db.information_for_ip("178.0.0.1")
    ip_info.inspect
    => #<IpInformation:0x101385c78 @city_name="eschborn", @city_code="ax5", @lng=8.55, @country_iso_code="de", @lat=50.133333, @is_mobile=true> 

== Copyright

Copyright (c) 2010 madvertise GmbH. See LICENSE.txt for
further details.
