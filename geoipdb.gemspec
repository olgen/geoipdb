# Generated by jeweler
# DO NOT EDIT THIS FILE DIRECTLY
# Instead, edit Jeweler::Tasks in Rakefile, and run 'rake gemspec'
# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{geoipdb}
  s.version = "0.2.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Eugen Martin", "Martin Karlsch"]
  s.date = %q{2011-03-13}
  s.description = %q{Returns a GeoLocation and additional information for given IP. Reads Data from CSV-Files and uses internal binary caching.}
  s.email = %q{eugeniusmartinus@googlemail.com}
  s.extensions = ["ext/geoipdb/extconf.rb"]
  s.extra_rdoc_files = [
    "LICENSE.txt",
    "README.markdown"
  ]
  s.files = [
    ".document",
    ".rspec",
    "Gemfile",
    "LICENSE.txt",
    "README.markdown",
    "Rakefile",
    "VERSION",
    "ext/geoipdb/Makefile",
    "ext/geoipdb/build.sh",
    "ext/geoipdb/extconf.rb",
    "ext/geoipdb/geoipdb.c",
    "ext/geoipdb/ipdb.c",
    "ext/geoipdb/ipdb.h",
    "geoipdb.gemspec",
    "lib/geoipdb.rb",
    "sample_data/cities.csv",
    "sample_data/citiess_corrupt.csv",
    "sample_data/ip_ranges.csv",
    "sample_data/ip_ranges_corrupt.csv",
    "spec/geoipdb_spec.rb",
    "spec/spec_helper.rb"
  ]
  s.homepage = %q{http://github.com/madvertise/geoipdb}
  s.licenses = ["MIT"]
  s.require_paths = ["lib", "ext"]
  s.rubygems_version = %q{1.5.2}
  s.summary = %q{Fast (>3 Mio queries/sec!!!) GeoIpDb implementation for Ruby using C-Extensions.}
  s.test_files = [
    "spec/geoipdb_spec.rb",
    "spec/spec_helper.rb"
  ]

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<rspec>, ["~> 2.1.0"])
      s.add_development_dependency(%q<bundler>, ["~> 1.0.0"])
      s.add_development_dependency(%q<jeweler>, ["~> 1.5.1"])
      s.add_development_dependency(%q<rcov>, [">= 0"])
    else
      s.add_dependency(%q<rspec>, ["~> 2.1.0"])
      s.add_dependency(%q<bundler>, ["~> 1.0.0"])
      s.add_dependency(%q<jeweler>, ["~> 1.5.1"])
      s.add_dependency(%q<rcov>, [">= 0"])
    end
  else
    s.add_dependency(%q<rspec>, ["~> 2.1.0"])
    s.add_dependency(%q<bundler>, ["~> 1.0.0"])
    s.add_dependency(%q<jeweler>, ["~> 1.5.1"])
    s.add_dependency(%q<rcov>, [">= 0"])
  end
end

