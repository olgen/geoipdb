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
  printf("Freeing memory for the GeoIpDb.. \n");
  if(gi == NULL)
    return;
  if (gi->db != NULL){
    if(gi->db->cities != NULL ){
      printf("..freeing cities \n");
      free(gi->db->cities);
      gi->db->cities = NULL;
    }
    if(gi->db->ranges != NULL ){
      printf("..freeing ranges \n");
      free(gi->db->ranges);
      gi->db->ranges = NULL;
    }
    if(gi->db != NULL){
      printf("..freeing ipdb \n");      
      free(gi->db);      
    }
  }
}


VALUE ipdb_init(VALUE self, VALUE cities_file_name, VALUE ranges_file_name, VALUE cache_file_name) {
  geoipdb *gi;
  
  Check_Type(cities_file_name, T_STRING);
  Check_Type(ranges_file_name, T_STRING);
  Check_Type(cache_file_name, T_STRING);
  
  char *cities_csv_file = RSTRING(cities_file_name)->ptr;
  char *ranges_csv_file = RSTRING(ranges_file_name)->ptr;
  char *cache_file =      RSTRING(cache_file_name)->ptr;  
  
  gi = malloc(sizeof(geoipdb));
  
  gi->db= init_db(cities_csv_file, ranges_csv_file, cache_file);
  
  if(gi->db == NULL)
  {
    if(DEBUG)
      printf("Could not init DB!\n");
    return Qnil;
  }else{
    if(DEBUG)
      printf("\nDB Init completed!\n");
    return(Data_Wrap_Struct(cGeoIpDb, 0, geoipdb_free, gi));    
  }
}


VALUE city_to_hash(City * city){
  VALUE hash = rb_hash_new();       
  // return a ruby-hash with the needed data
  rb_hash_aset(hash, rb_str_new2("name"), rb_str_new2(city->name));  
  rb_hash_aset(hash, rb_str_new2("country"), rb_str_new2(city->country_iso2));      
  rb_hash_aset(hash, rb_str_new2("lat"), rb_float_new(city->lat));  
  rb_hash_aset(hash, rb_str_new2("lng"), rb_float_new(city->lng));      
  rb_hash_aset(hash, rb_str_new2("city_code"), INT2FIX(city->city_code));        
  return hash;
}

VALUE ipdb_city_by_ip(VALUE self, VALUE ip_string){
  char *ip = RSTRING(ip_string)->ptr;
  geoipdb *gi;
  
  Data_Get_Struct(self, geoipdb, gi);
  City * city = city_by_ip(gi->db, ip);  
  if(city == NULL)
  {
    // printf("Could not find city for ip: %s\n", ip);
    return Qnil;
  }else{
    // printf("Found city for ip: %s\n", ip);
    // print_city(city);
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