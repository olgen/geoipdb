public class City implements Comparable<City> {
  int city_code;
  String name;
  double lat;
  double lng;
  String country_iso3;
  String country_iso2;


public static final String[] country_iso2_codes = { "--","ap","eu","ad","ae","af","ag","ai","al","am","an",
                            "ao","aq","ar","as","at","au","aw","az","ba","bb",
                            "bd","be","bf","bg","bh","bi","bj","bm","bn","bo",
                            "br","bs","bt","bv","bw","by","bz","ca","cc","cd",
                            "cf","cg","ch","ci","ck","cl","cm","cn","co","cr",
                            "cu","cv","cx","cy","cz","de","dj","dk","dm","do",
                            "dz","ec","ee","eg","eh","er","es","et","fi","fj",
                            "fk","fm","fo","fr","fx","ga","gb","gd","ge","gf",
                            "gh","gi","gl","gm","gn","gp","gq","gr","gs","gt",
                            "gu","gw","gy","hk","hm","hn","hr","ht","hu","id",
                            "ie","il","in","io","iq","ir","is","it","jm","jo",
                            "jp","ke","kg","kh","ki","km","kn","kp","kr","kw",
                            "ky","kz","la","lb","lc","li","lk","lr","ls","lt",
                            "lu","lv","ly","ma","mc","md","mg","mh","mk","ml",
                            "mm","mn","mo","mp","mq","mr","ms","mt","mu","mv",
                            "mw","mx","my","mz","na","nc","ne","nf","ng","ni",
                            "nl","no","np","nr","nu","nz","om","pa","pe","pf",
                            "pg","ph","pk","pl","pm","pn","pr","ps","pt","pw",
                            "py","qa","re","ro","ru","rw","sa","sb","sc","sd",
                            "se","sg","sh","si","sj","sk","sl","sm","sn","so",
                            "sr","st","sv","sy","sz","tc","td","tf","tg","th",
                            "tj","tk","tm","tn","to","tl","tr","tt","tv","tw",
                            "tz","ua","ug","um","us","uy","uz","va","vc","ve",
                            "vg","vi","vn","vu","wf","ws","ye","yt","rs","za",
                            "zm","me","zw","a1","a2","o1","ax","gg","im","je",
                            "bl","mf"};

  public static final String[] country_iso3_codes = { "--","ap","eu","and","are","afg","atg","aia","alb","arm","ant",
                            "ago","aq","arg","asm","aut","aus","abw","aze","bih","brb",
                            "bgd","bel","bfa","bgr","bhr","bdi","ben","bmu","brn","bol",
                            "bra","bhs","btn","bv","bwa","blr","blz","can","cc","cod",
                            "caf","cog","che","civ","cok","chl","cmr","chn","col","cri",
                            "cub","cpv","cx","cyp","cze","deu","dji","dnk","dma","dom",
                            "dza","ecu","est","egy","esh","eri","esp","eth","fin","fji",
                            "flk","fsm","fro","fra","fx","gab","gbr","grd","geo","guf",
                            "gha","gib","grl","gmb","gin","glp","gnq","grc","gs","gtm",
                            "gum","gnb","guy","hkg","hm","hnd","hrv","hti","hun","idn",
                            "irl","isr","ind","io","irq","irn","isl","ita","jam","jor",
                            "jpn","ken","kgz","khm","kir","com","kna","prk","kor","kwt",
                            "cym","kaz","lao","lbn","lca","lie","lka","lbr","lso","ltu",
                            "lux","lva","lby","mar","mco","mda","mdg","mhl","mkd","mli",
                            "mmr","mng","mac","mnp","mtq","mrt","msr","mlt","mus","mdv",
                            "mwi","mex","mys","moz","nam","ncl","ner","nfk","nga","nic",
                            "nld","nor","npl","nru","niu","nzl","omn","pan","per","pyf",
                            "png","phl","pak","pol","spm","pcn","pri","pse","prt","plw",
                            "pry","qat","reu","rou","rus","rwa","sau","slb","syc","sdn",
                            "swe","sgp","shn","svn","sjm","svk","sle","smr","sen","som",
                            "sur","stp","slv","syr","swz","tca","tcd","tf","tgo","tha",
                            "tjk","tkl","tkm","tun","ton","tls","tur","tto","tuv","twn",
                            "tza","ukr","uga","um","usa","ury","uzb","vat","vct","ven",
                            "vgb","vir","vnm","vut","wlf","wsm","yem","yt","srb","zaf",
                            "zmb","mne","zwe","a1","a2","o1","ala","ggy","imn","jey",
                            "blm","maf"};

  public City(String[] city_vals) {
    this.city_code = Integer.parseInt(city_vals[4]);
    this.name = city_vals[2];
    this.country_iso2 = iso2_code(city_vals[0]);
    this.country_iso3 = city_vals[0];
    this.lat = Double.parseDouble(city_vals[5]);
    this.lng = Double.parseDouble(city_vals[6]);
  }

  private String iso2_code(String iso3_code) {
    int index = 0;
    for (index = 0; index < country_iso3_codes.length; index++) {
      if (country_iso3_codes[index].equals(iso3_code)) {
        return country_iso2_codes[index];
      }
    }
    return country_iso2_codes[0];
  }

  @Override
  public int compareTo(City other) {
    return this.city_code - other.city_code;
  }
  public int getCity_code() {
		return city_code;
	}

	public String getName() {
		return name;
	}

	public double getLat() {
		return lat;
	}

	public double getLng() {
		return lng;
	}

	public String getCountry_iso3() {
		return country_iso3;
	}

	public String getCountry_iso2() {
		return country_iso2;
	}
}
