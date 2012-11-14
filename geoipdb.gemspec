# -*- encoding: utf-8 -*-

Gem::Specification.new do |gem|
  gem.name = "geoipdb"
  gem.version = "0.4.3"
  gem.licenses = ["MIT"]

  gem.authors = ["Eugen Martin", "Martin Karlsch"]
  gem.email = ["eugeniusmartinus@googlemail.com", "martin.karlsch@madvertise.com"]

  gem.description = "Returns a GeoLocation and additional information for given IP. Reads Data from CSV-Files and uses internal binary caching."
  gem.summary = "Fast (>3 Mio queries/sec!!!) GeoIpDb implementation for Ruby using C-Extensions."
  gem.homepage = "http://github.com/madvertise/geoipdb"

  gem.extensions = ["ext/geoipdb/extconf.rb"]

  gem.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  gem.files         = `git ls-files`.split("\n")
  gem.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  gem.require_paths = ["lib", "ext"]
end
