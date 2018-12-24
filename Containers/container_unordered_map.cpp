#include "../prototypes.h"

#include <map>

void container_unordered_map()
{
  // TODO: 12/23/2018
  // Add:
  // 1. try_emplace
  // 2. insert_or_assign

  // Iterator variation
  std::unordered_map<std::string, int> iterator_test_map;
  iterator_test_map[ "one" ] = 1;
  iterator_test_map[ "two" ] = 2;
  iterator_test_map[ "three" ] = 3;
  iterator_test_map[ "four" ] = 4;

  for( auto const&[ key, val ] : iterator_test_map )
  {
    std::cout << "Key = " << key << ", Value = " << val << '\n';
  }
}