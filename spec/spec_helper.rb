require 'rubygems'
require 'rspec'

require 'simplecov'
SimpleCov.start

$:.unshift(File.dirname(__FILE__) + '/../lib')
$:.unshift(File.dirname(__FILE__) + '/../ext')
require 'geoipdb'

RSpec.configure do |config|
end
