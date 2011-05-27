
#ifdef INT_2_BYTES
typedef char int8;
typedef int int16;
typedef unsigned int uint16;
typedef long int32;
#else
typedef char int8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
#endif


#define RANGES_DELIM "|"
#define CITIES_DELIM ","
#define MAX_CITIES_COUNT 100000 //Usually we have about 50 000 Cities
#define MAX_RANGES_COUNT 10000000 //Usually we have about 6 Mio IP-Ranges       

#define USE_CACHE 1
#define DEBUG 0

typedef struct{
  unsigned long from;
  unsigned long to;     
  unsigned char is_mobile;
  uint16 city_index; //index of the city in the cities-array
} IpRange;

typedef struct{
  uint16 city_code; //city codes are not larger than 2**16 = 65536
  char name[32];
  double lat;
  double lng;
  
  char country_iso3[4];
  char country_iso2[3];  
} City;

typedef struct{
  char *ranges_csv_file; //the CSV-file with ip-ranges-to-city-code-mappings
  unsigned int max_ranges_count;
  unsigned int ranges_count;

  char *cities_csv_file;
  unsigned int cities_count;  
  unsigned int max_cities_count;

  
  char *cache_file_name; // a binary file to store the whole db.....
  IpRange * ranges;
  City * cities;

} IPDB;


// "publicly" visible functions
IPDB * 
init_db(char * cities_csv_file, char * ranges_csv_file, char * cache_file_name);


void 
print_city(const City * e);

void 
benchmark_search(IPDB * db,int count);        

IpRange* find_range_for_ip(IPDB *db, char *ip);
City * find_city_for_ip_range(IPDB * db, IpRange* range); 