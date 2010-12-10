#include "ipdb.h"

#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>



int main() {
  IPDB * db = init_db("data/city_codes.csv", "data/ip_city.txt", "data/ip_city.cache");
  // IPDB * db = init_db(NULL, NULL, NULL);  
  
  City * city;
  city = city_by_ip(db, "91.44.93.35");
  // city = city_by_ip(db, "1.16.0.0");  
  
  if(city == NULL)
  {
    printf("Could not find City!");
  } else {
    printf("Found City: \n");  
    print_city(city);
  }
  // benchmark_search(db,1000000);
  
  // char *asdf = "asdf";
  // char *asdf2;
  // cpy(&asdf,&asdf2);
  // asdf2 = malloc(strlen(asdf));
  // strcpy(asdf2,asdf);
  
  // printf("strlen(asdf)= %li, asdf2=%s", strlen(asdf), asdf2);
  
  // uint16 test;
  // test = 65000;
  // printf("Int:%li,Int8:%li,Int16:%li, Int32:%li, %i", sizeof(int), sizeof(int8), sizeof(int16), sizeof(int32), test);
  
  // unsigned long max_ranges_count = 100;
  // unsigned long ranges_count=0;
  // IpRange* ranges; //array of ptrs to IpRange...
  // printf("Allocating: %lu", sizeof(IpRange*)*max_ranges_count);
  // ranges = malloc(sizeof(IpRange*)*max_ranges_count);  
  // 
  // int cache_size = read_cache_file("data/ip_city.cache", ranges, &ranges_count);
  // if( false && cache_size != 0)
  // {
  //   printf("Using db from cachefile of size: %i",cache_size);
  // }else{
  //   read_ranges_csv("data/ip_city.txt", ranges, max_ranges_count, &ranges_count);
  //   write_cache_file("data/ip_city.cache", ranges, ranges_count);
  // }
  
 //  
 // 


  
 //  
  int * response;
  scanf("%i",response);

  return 0;

}
