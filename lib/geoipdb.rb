require 'rbconfig'

require 'geoipdb/geoipdb'

class IpInformation
  attr_accessor :country_iso_code
  attr_accessor :city_code
  attr_accessor :city_name
  attr_accessor :lat
  attr_accessor :lng
  attr_accessor :is_mobile
  attr_accessor :isp_name
  
  def mobile?
    @is_mobile
  end
end
