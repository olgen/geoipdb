require 'ip_information'

if defined?(JRUBY_VERSION)
  require 'jgeoipdb'
  require 'rbconfig'
else
  require 'geoipdb/geoipdb'
end

