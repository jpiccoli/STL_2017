#include "../prototypes.h"

#include <map>

void container_map()
{
  // TODO: 12/23/2018
  // Add:
  // 1. try_emplace
  // 2. insert_or_assign

  // Iterator variation
  std::map<std::string, int> iterator_test_map1, iterator_test_map2;
  iterator_test_map1[ "one" ] = 1;
  iterator_test_map1[ "two" ] = 2;
  iterator_test_map1[ "three" ] = 3;
  iterator_test_map1[ "four" ] = 4;
  for( auto const&[ key, val ] : iterator_test_map1 )
  {
    std::cout << "Key = " << key << ", Value = " << val << '\n';
  }

  std::cout << "-------------------------\n";

  iterator_test_map2.insert( std::pair( "Mercury", 1967 ) );
  iterator_test_map2.insert( std::pair( "Plymouth", 1974 ) );
  iterator_test_map2.insert( std::pair( "Dodge", 1982 ) );
  iterator_test_map2.insert( std::pair( "Chrysler", 1986 ) );
  for( auto const&[ key, val ] : iterator_test_map2 )
  {
    std::cout << "Key = " << key << ", Value = " << val << '\n';
  }
}
