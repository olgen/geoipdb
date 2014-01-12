require 'bundler/setup'
require 'bundler/gem_tasks'

Dir['tasks/**/*.rake'].each { |t| load t }

task :default => [:spec]
task :build => :compile
task :spec => :compile
