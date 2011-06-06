$LOAD_PATH.unshift(File.join(File.dirname(__FILE__), 'ext'))
$LOAD_PATH.unshift(File.dirname(__FILE__))

require 'lib/geoipdb'


db = GeoIpDb.init 'ext/data/cities.csv', 'ext/data/ip_ranges.csv', 'ext/data/ipdb.cache'

puts db.information_for_ip("165.193.245.54").inspect