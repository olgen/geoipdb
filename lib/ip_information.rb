class IpInformation

  ATTRIBS = [
    :country_iso_code,
    :city_code,
    :city_name,
    :lat,
    :lng,
    :is_mobile,
    :isp_name,
  ]

  ATTRIBS.each do |attrib|
    attr_accessor attrib
  end

  def mobile?
    @is_mobile
  end

  def to_h
    Hash[ATTRIBS.map do |attrib|
      [attrib, send(attrib)]
    end]
  end

end
