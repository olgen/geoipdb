return if defined?(JRUBY_VERSION)
require "mkmf"

create_makefile("geoipdb/geoipdb")
