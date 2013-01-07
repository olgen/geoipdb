case RUBY_PLATFORM
when 'java'
  require 'rake/javaextensiontask'
  Rake::JavaExtensionTask.new('geoipdb')
else
  require 'rake/extensiontask'
  Rake::ExtensionTask.new('geoipdb')
end
