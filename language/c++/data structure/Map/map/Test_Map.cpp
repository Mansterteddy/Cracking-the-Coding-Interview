/** Simple program to test map */

#include <iostream>
#include <string>
#ifdef USESTD
#include <map>
typedef std::map<std::string, int > map_type;
#elif KWSTD
#include "map.h"
typedef KW::map<std::string, int> map_type;
#elif KWCHAIN
#include "Hash_Table_Chain.h"
typedef KW::hash_map<std::string, int> map_type;
#elif KWCHAINSLL
#include "Hash_Table_Chain_SLL.h"
typedef KW::hash_map<std::string, int> map_type;
#elif KWOPEN
#include "Hash_Table_Open.h"
typedef KW::hash_map<std::string, int> map_type;
#endif

#define echo(x) #x <<": " << x

using std::string;
using std::cout;
using std::endl;

int main()
{
  // Test map insert and indexing operations
  map_type map;
  map["Hello"] = 1;
  cout << echo(map["Hello"]) << endl;
  map["Good bye"] = 100;
  cout << echo(map["Good bye"]) << endl;
  map["Hello"] = map["Hello"] + 1;
  cout << echo(map["Hello"]) << endl;
  cout << map["Hello"] << endl;
  cout << "Map contents\n";
  for (map_type::const_iterator itr = map.begin();
       itr != map.end(); ++itr) {
    cout << itr->first << ": " << itr->second << endl;
  }
  // Test erase
  map.erase("Hello");
  cout << "Map contents\n";
  for (map_type::const_iterator itr = map.begin();
       itr != map.end(); ++itr) {
    cout << itr->first << ": " << itr->second << endl;
  }
  // Test Copy Constructor
  map_type map2(map);
  cout << "Map2 contents\n";
  map2["Hello"] = 99;
  cout << "Map2 contents after adding Hello back\n";
  for (map_type::const_iterator itr = map2.begin();
       itr != map2.end(); ++itr) {
    cout << itr->first << ": " << itr->second << endl;
  }
  cout << "Original Map contents\n";
  for (map_type::const_iterator itr = map.begin();
       itr != map.end(); ++itr) {
    cout << itr->first << ": " << itr->second << endl;
  }
  return 0;
}
