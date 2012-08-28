require 'rubygems'
require 'bundler'

begin
  Bundler.setup(:default, :development)
rescue Bundler::BundlerError => e
  $stderr.puts e.message
  $stderr.puts "Run `bundle install` to install missing gems"
  exit e.status_code
end
require 'rake'

require 'jeweler'
Jeweler::Tasks.new do |gem|
  # gem is a Gem::Specification... see http://docs.rubygems.org/read/chapter/20 for more options
  gem.name = "geoipdb"
  gem.homepage = "http://github.com/madvertise/geoipdb"
  gem.license = "MIT"
  gem.summary = %Q{Fast (>3 Mio queries/sec!!!) GeoIpDb implementation for Ruby using C-Extensions.}
  gem.description = %Q{Returns a GeoLocation and additional information for given IP. Reads Data from CSV-Files and uses internal binary caching.}
  gem.email = "eugeniusmartinus@googlemail.com"
  gem.extensions   = ['ext/geoipdb/extconf.rb'] 
  gem.require_paths = ["lib","ext"]
  gem.authors = ["Eugen Martin", "Martin Karlsch", "Thomas Hirsch"]
end
Jeweler::RubygemsDotOrgTasks.new

require 'rake/javaextensiontask'

Rake::JavaExtensionTask.new('geoipdb') do |ext|
  ext.ext_dir = 'ext/java/src'
end

require 'rspec/core'
require 'rspec/core/rake_task'
RSpec::Core::RakeTask.new(:spec) do |spec|
  spec.pattern = FileList['spec/**/*_spec.rb']
end

RSpec::Core::RakeTask.new(:rcov) do |spec|
  spec.pattern = 'spec/**/*_spec.rb'
  spec.rcov = true
end

task :default => :spec

require 'rake/rdoctask'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "geoipdb #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
end
