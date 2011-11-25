
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

#ifdef RSTRING_PTR
#else
# define RSTRING_LEN(x) (RSTRING(x)->len)
# define RSTRING_PTR(x) (RSTRING(x)->ptr)
#endif


#define RANGES_DELIM ",\n"
#define CITIES_DELIM ",\n"

#define MAX_CITIES_COUNT 1000000 //Usually we have about 120 000 Cities
#define MAX_RANGES_COUNT 10000000 //Usually we have about 6 Mio IP-Ranges

#define MAX_ISPS_COUNT 65535
#define MAX_ISP_NAME_LENGTH 100

#define USE_CACHE 1
#define DEBUG 0

typedef struct{
  unsigned long from;
  unsigned long to;
  unsigned char is_mobile;
  int city_index; //index of the city in the cities-array
  int16 isp_index; //index of the isp in the isps-array
} IpRange;

typedef struct{
  int city_code;
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

  char isps[MAX_ISPS_COUNT][MAX_ISP_NAME_LENGTH]; // a fixed size array of strings should be enough here...do not expect the isps to grow dramatically..
  uint16 isps_count;


} IPDB;


// "publicly" visible functions
IPDB *
init_db(char * cities_csv_file, char * ranges_csv_file, char * cache_file_name);


void
print_city(const City * e);

void
benchmark_search(IPDB * db,int count);

IpRange*
find_range_for_ip(IPDB *db, char *ip);

City*
find_city_for_ip_range(IPDB * db, IpRange* range);

char*
find_isp_for_ip_range(IPDB * db, IpRange* range);