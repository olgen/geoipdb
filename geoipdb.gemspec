# Generated by jeweler
# DO NOT EDIT THIS FILE DIRECTLY
# Instead, edit Jeweler::Tasks in Rakefile, and run 'rake gemspec'
# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{geoipdb}
  s.version = "0.1.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Eugen Martin"]
  s.date = %q{2010-12-10}
  s.description = %q{Returns a GeoLocation to a given IP. Reads Data from CSV-Files and uses internal binary caching.}
  s.email = %q{eugeniusmartinus@googlemail.com}
  s.extensions = ["ext/extconf.rb"]
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
    "ext/build.sh",
    "ext/extconf.rb",
    "ext/geoipdb.c",
    "ext/ipdb.c",
    "ext/ipdb.h",
    "ext/test.c",
    "geoipdb.gemspec",
    "lib/geoipdb.rb",
    "spec/geoipdb_spec.rb",
    "spec/spec_helper.rb"
  ]
  s.homepage = %q{http://github.com/olgen/geoipdb}
  s.licenses = ["MIT"]
  s.require_paths = ["ext"]
  s.rubygems_version = %q{1.3.7}
  s.summary = %q{Fast (>3 Mio queries/sec!!!) GeoIpDb implementation for Ruby using C-Extensions.}
  s.test_files = [
    "spec/geoipdb_spec.rb",
    "spec/spec_helper.rb"
  ]

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
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

