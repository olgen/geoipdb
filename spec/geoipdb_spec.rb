require File.expand_path(File.dirname(__FILE__)+'/spec_helper')


describe "Geoipdb" do
  def init_db
    @db = GeoIpDb.init './sample_data/cities.csv', './sample_data/ip_ranges.csv', @cache_file
  end
  
  before :each do
    @cache_file = 'sample_data/ipdb.cache'
  end
  
  it "should init correctly with sample data and create the cache-file" do
    init_db
    @db.should_not be_nil
    File.exist?(@cache_file).should be_true
  end
  
  it "sould find the sample cities correcty" do 
    init_db
    #afg,no region,kabul,-1,3,34.5167,69.1833
    @db.city_by_ip("1.1.0.254").should == {'city_code'=>3, 'name'=>'kabul', 'country'=>'af', 'lat'=>34.5167, 'lng'=>69.1833}
  end
  
  it "should not throw an exception fault if data is corrupt" do
    @db = GeoIpDb.init './sample_data/cities_corrupt.csv', './sample_data/ip_ranges_corrupt.csv', @cache_file    
  end

  it "should not init a db object if data files are missing" do
    GeoIpDb.init( './sample_data/bla.csv', './sample_data/blubb.csv', @cache_file    ).should be_nil
  end

  
  after :each do
    File.unlink @cache_file if File.exist? @cache_file
  end
end
