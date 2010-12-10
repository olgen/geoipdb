#include "ipdb.h"

#include "ruby.h"

/** 
Ruby Wrapper
*/



typedef struct geipdb {
  IPDB *db;
} geoipdb;


static VALUE cGeoIpDb;
// 
VALUE method_hello_world(VALUE self);

// free the memory used by the db, called by the Ruby-GC
void geoipdb_free(geoipdb *gi) {
  printf("Freeing memory for geoipdb var: \n");
  if (gi->db != NULL)
    if(gi->db->cities != NULL){
      printf("..freeing cities \n");
      free(gi->db->cities);
      gi->db->cities = NULL;
    }
    if(gi->db->ranges != NULL){
      printf("..freeing ranges \n");      
      free(gi->db->ranges);
      gi->db->ranges = NULL;
    }
  free(gi);
}


// VALUE init(int argc, VALUE *argv, VALUE class) {
//   geoipdb *gi;
//   VALUE cities_csv_file, ranges_csv_file, cache_file;
// 
//   if (argc == 3) {
//     rb_scan_args(argc, argv, "03", &cities_csv_file, &ranges_csv_file, &cache_file);
//     Check_Type(cities_csv_file, T_STRING);
//     Check_Type(ranges_csv_file, T_STRING);    
//     Check_Type(cache_file, T_STRING);    
//   } else
//     rb_raise(rb_eArgError, "wrong number of arguments (needs 3 : cities_csv_file, ranges_csv_file, cache_file)");
//     
//   // gi = ALLOC(geoipdb);
//   // gi = malloc(sizeof(geoipdb));  
//   // gi->db = init_db(StringValuePtr(cities_csv_file), StringValuePtr(ranges_csv_file), StringValuePtr(cache_file));
//   
//   init_db(StringValuePtr(cities_csv_file), StringValuePtr(ranges_csv_file), StringValuePtr(cache_file));
//   
//   printf("DB Init complete!");
//   
//   return NULL;
//   // return(Data_Wrap_Struct(class, 0, geoipdb_free, gi));
// }

VALUE ipdb_init(VALUE self, VALUE cities_file_name, VALUE ranges_file_name, VALUE cache_file_name) {
  geoipdb *gi;
  char *cities_csv_file = RSTRING(cities_file_name)->ptr;
  char *ranges_csv_file = RSTRING(ranges_file_name)->ptr;
  char *cache_file =      RSTRING(cache_file_name)->ptr;  
  
    
  // gi = ALLOC(geoipdb);
  
  gi = malloc(sizeof(geoipdb));
  
  gi->db= init_db(cities_csv_file, ranges_csv_file, cache_file);
  
  printf("\nDB Init completed!\n");
  
  // return gi;
  return(Data_Wrap_Struct(cGeoIpDb, 0, geoipdb_free, gi));
}


VALUE city_to_hash(City * city){
  VALUE hash = rb_hash_new();       
  rb_hash_aset(hash, rb_str_new2("name"), rb_str_new2(city->name));  
  // TODO: we should convert this to iso2
  rb_hash_aset(hash, rb_str_new2("country"), rb_str_new2(city->country_iso3));      
  
  rb_hash_aset(hash, rb_str_new2("lat"), rb_float_new(city->lat));  
  rb_hash_aset(hash, rb_str_new2("lng"), rb_float_new(city->lng));      
  return hash;
}

VALUE ipdb_city_by_ip(VALUE self, VALUE ip_string){
  char *ip = RSTRING(ip_string)->ptr;
  geoipdb *gi;
  
  Data_Get_Struct(self, geoipdb, gi);
  // City * city = (City *) city_by_ip(gi->db, ip);
  City * city = city_by_ip(gi->db, ip);  
  if(city == NULL)
  {
    printf("Could not find city for ip: %s\n", ip);
    return Qnil;
  }else{
    printf("Found city for ip: %s\n", ip);
    print_city(city);
    return city_to_hash(city);
    // create a hash to return to ruby:
  }
}



void Init_geoipdb(void)
{
  //Erstelle die Klasse cGeoIpDb als Subklasse von Object
  cGeoIpDb = rb_define_class( "GeoIpDb", rb_cObject);
  rb_define_singleton_method( cGeoIpDb, "init",        ipdb_init, 3); 
  rb_define_method(           cGeoIpDb, "city_by_ip",  ipdb_city_by_ip, 1);  
}