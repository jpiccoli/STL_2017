#include "../prototypes.h"

#include <map>

void container_map()
{
  // Iterator variation
  std::cout << "-------------------------\n";
  std::cout << "Iterator variation 1\n";
  std::cout << "-------------------------\n";
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

  std::cout << "-------------------------\n";
  std::cout << "Iterator variation 2\n";
  std::cout << "-------------------------\n";
  iterator_test_map2.insert( std::pair( "Mercury", 1967 ) );
  iterator_test_map2.insert( std::pair( "Plymouth", 1974 ) );
  iterator_test_map2.insert( std::pair( "Dodge", 1982 ) );
  iterator_test_map2.insert( std::pair( "Chrysler", 1986 ) );
  for( auto const&[ key, val ] : iterator_test_map2 )
  {
    std::cout << "Key = " << key << ", Value = " << val << '\n';
  }

  // at()

  // operator[]

  ////////////
  // Iterators
  ////////////

  // begin(), cbegin()

  // end(), cend()

  // rend(), rcend()

  ///////////
  // Capacity
  ///////////
  // empty()

  // size()

  // max_size()
  // Implementation-dependent

  ////////////
  // Modifiers
  ////////////
  // clear()

  // insert()

  // insert_or_assign()

  // emplace()

  // emplace_hint()

  // try_emplace()

  // erase()

  // swap()

  // extract()

  // merge()

  // count()

  // find()

  // equal_range()

  // lower_bound()

  // upper_bound()

  ////////////
  // Observers
  ////////////
  // key_comp()

  // value_comp()

}
