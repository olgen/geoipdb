# geoipdb: fast (in memory!) geo location db.

Fast (>3 Mio queries/sec!!!) GeoIpDb implementation for Ruby using C-Extensions. 

  * Returns a GeoLocation to a given IP. 
  * Reads Data from CSV-Files and uses internal binary caching.

## Usage

  db = GeoIpDb.init "city_codes.csv", "ip_city.txt", "ip_city.cache"
  location_hash = db.city_by_ip("178.0.0.1")
  # => {"name"=>"eschborn", "country"=>"deu", "lng"=>8.55, "lat"=>50.133333} 

== Copyright

Copyright (c) 2010 Eugen Martin. See LICENSE.txt for
further details.

