#include "ipdb.h"

#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>



int main() {
  IPDB * db = init_db("data/cities.csv", "data/ip_ranges.csv", "data/ipdb.cache");
  // IPDB * db = init_db(NULL, NULL, NULL);  
  

  // City * city;
  // 
  // // city = city_by_ip(db, "1.16.0.0");  
  // int i;
  int count = 10000000;
  
  benchmark_search(db, count);
  
  // for(i = 0; i < count; ++i)
  // {
  //   if(i % 100000 == 0)
  //     printf("Working: i= %i \n", i);
  //     
  //   city = city_by_ip(db, "91.44.93.35");
  // }
  



  
 //  
  int * response;
  scanf("%i",response);

  return 0;

}
