#include "../prototypes.h"

#include <map>

static std::map<std::string, int> cars = {
{ "Horizon", 1988 },
{ "Cavalier", 1989 },
{ "Corsica", 1990 },
{ "Corvette", 1990 },
{ "Saturn SL1", 1991 },
{ "Saturn SW", 1995 },
{ "Saturn SW", 1995 },
{ "Malibu", 1997 },
{ "Metro", 1998 },
{ "Prizm", 1999 },
{ "Civic", 2002 },
{ "Accord", 2003 },
{ "Corolla LE", 2004 },
{ "RAV4 LE AWD", 2010 },
{ "RAV4 LE FWD", 2010 },
{ "Chrysler", 1986 },
};

void container_map()
{
  ////////////
  // Iterators
  ////////////
  // begin(), cbegin()

  // end(), cend()

  // rend(), rcend()

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
  std::cout << '\n';

  /////////////////
  // Element Access
  /////////////////
  // at()
  auto at_val = iterator_test_map2.at( "Chrysler" );
  if( at_val == 1986 )
    std::cout << "std::map::at() passed\n";
  else
    std::cout << "std::map::at() failed\n";

  // operator[]
  at_val = iterator_test_map2[ "Chrysler" ];
  if( at_val == 1986 )
    std::cout << "std::map::operator[] passed\n";
  else
    std::cout << "std::map::operator[] failed\n";

  ///////////
  // Capacity
  ///////////
  // empty()
  if( !iterator_test_map2.empty() )
    std::cout << "std::map::empty() passed\n";
  else
    std::cout << "std::map::empty() failed\n";

  // size()
  if( iterator_test_map2.size() == 4 )
    std::cout << "std::map::size() passed\n";
  else
    std::cout << "std::map::size() failed\n";

  // max_size()
  // Implementation-dependent

  ////////////
  // Modifiers
  ////////////
  // clear()
  static std::map<int, int> map_to_clear = { { 1, 100 }, { 2, 200 } };
  if( map_to_clear.size() == 2 )
  {
    std::cout << "std::map::clear() #1  passed()\n";
    map_to_clear.clear();
    if( !map_to_clear.size() )
      std::cout << "std::map::clear() #2 passed()\n";
    else
      std::cout << "std::map::clear() #2 failed()\n";
  }
  else
  {
    std::cout << "std::map::clear() #1 failed()\n";
  }

  // insert()
  cars.insert( { "Corvair", 1964 } );
  auto itr1 = cars.find( "Corvair" );
  if( itr1 != cars.end() )
    std::cout << "std::map::insert() passed()\n";
  else
    std::cout << "std::map::insert() failed()\n";

  // insert_or_assign()
  cars.insert_or_assign( "Z24", 1987 );
  auto itr2 = cars.find( "Z24" );
  if( itr2 != cars.end() && itr2->second == 1987 )
    std::cout << "std::map::insert_or_assign() #1 passed()\n";
  else
    std::cout << "std::map::insert_or_assign() #1 failed()\n";

  cars.insert_or_assign( "Malibu", 2004 );
  auto itr3 = cars.find( "Malibu" );
  if( itr3 != cars.end() && itr3->second == 2004 )
    std::cout << "std::map::insert_or_assign() #2 passed()\n";
  else
    std::cout << "std::map::insert_or_assign() #2 failed()\n";

  // emplace()
  cars.emplace( std::make_pair( "Duster", 1987 ) );
  auto itr4 = cars.find( "Duster" );
  if( itr4 != cars.end() && itr4->second == 1987 )
    std::cout << "std::map::emplace() passed()\n";
  else
    std::cout << "std::map::emplace() failed()\n";

  // emplace_hint()
  // TODO: 05/31/2020

  // try_emplace()
  cars.try_emplace( "Cavaliar LV", 1988 );
  auto itr5 = cars.find( "Cavaliar LV" );
  if( itr5 != cars.end() && itr5->second == 1988 )
    std::cout << "std::map::try_emplace() #1 passed()\n";
  else
    std::cout << "std::map::try_emplace() #1 failed()\n";

  cars.try_emplace( "Fiero", 1983 );
  auto itr6 = cars.find( "Fiero" );
  if( itr6 != cars.end() && itr6->second == 1983 )
    std::cout << "std::map::try_emplace() #2 passed()\n";
  else
    std::cout << "std::map::try_emplace() #2 failed()\n";

  // erase()
  for( auto itr7 = cars.begin(); itr7 != cars.end(); )
  {
    if( itr7->first == "Cavalier LV" )
      cars.erase( itr7 );
    else
      ++itr7;
  }
  auto itr8 = cars.find( "Cavalier LV" );
  if( itr8 == cars.end() )
    std::cout << "std::map::erase() passed()\n";
  else
    std::cout << "std::map::erase() failed()\n";

  // swap()
  std::map<std::string, int> test_map1 = {
    { "21", 21 },
    { "23", 23 },
    { "27", 27 },
    { "29", 29 }
  };
  std::map<std::string, int> test_map2 = {
    { "31", 31 },
    { "33", 33 },
    { "37", 37 },
    { "39", 39 },
    { "41", 41 }
  };

  test_map1.swap( test_map2 );
  auto itr11 = test_map1.find( "31" );
  auto itr12 = test_map2.find( "27" );
  if( itr11 != test_map1.end() && itr12 != test_map2.end() )
    std::cout << "std::map::swap() passed()\n";
  else
    std::cout << "std::map::swap() failed()\n";

  // extract()
  auto nh = cars.extract( "Chrysler" );
  nh.key() = "Turismo 2.2";
  cars.insert( std::move( nh ) );
  auto itr14 = cars.find( "Turismo 2.2" );
  if( itr14 != cars.end() )
    std::cout << "std::map::extract() passed()\n";
  else
    std::cout << "std::map::extract() failed()\n";

  // merge()
  std::map<std::string, int> test_map3;
  test_map3.merge( test_map1 );
  test_map3.merge( test_map2 );
  auto itr15 = test_map3.find( "31" );
  auto itr16 = test_map3.find( "27" );
  if( itr16 != test_map3.end() && itr16 != test_map3.end() )
    std::cout << "std::map::merge() passed()\n";
  else
    std::cout << "std::map::merge() failed()\n";

  /////////
  // Lookup
  /////////
  // count()
  auto element_count = cars.count( "Cavalier LV" );
  if( !element_count )
    std::cout << "std::map::count() #1 passed()\n";
  else
    std::cout << "std::map::count() #1 failed()\n";

  element_count = cars.count( "Horizon" );
  if( element_count )
    std::cout << "std::map::count() #2 passed()\n";
  else
    std::cout << "std::map::count() #2 failed()\n";

  // find()
  // Covered above

  // equal_range()
  static std::map<int, std::string> eq_range_map1 = { 
    { 0, "000" },
    { 2, "100" },
    { 4, "200" }, 
    { 6, "300" },
    { 8, "400" },
    { 12, "500" },
    { 14, "550" },
    { 16, "570" },
    { 18, "590" }
  };

  static std::map<std::string, int> eq_range_map2 = {
    { "000", 0 },
    { "100", 2 },
    { "200", 4 },
    { "300", 6 },
    { "400", 8 },
    { "500", 12 },
    { "550", 14 },
    { "570", 16 },
    { "590", 18 }
  };

  auto p1 = eq_range_map1.equal_range( 2 );
  auto q1 = p1.first;
  auto q2 = p1.second;
  if( q1->first == 2 && q2->first == 4 )
    std::cout << "std::map::equal_range() #1 passed()\n";
  else
    std::cout << "std::map::equal_range() #1 failed()\n";

  auto p2 = eq_range_map1.equal_range( 3 );
  auto q3 = p2.first;
  auto q4 = p2.second;
  if( q3->first == 4 && q4->first == 4 )
    std::cout << "std::map::equal_range() #2 passed()\n";
  else
    std::cout << "std::map::equal_range() #2 failed()\n";

  auto p3 = eq_range_map1.equal_range( -1 );
  auto q5 = p3.first;
  auto q6 = p3.second;
  if( q5->first == 0 && q6->first == 0 )
    std::cout << "std::map::equal_range() #3 passed()\n";
  else
    std::cout << "std::map::equal_range() #3 failed()\n";

  auto p4 = eq_range_map1.equal_range( 12 );
  auto q7 = p4.first;
  auto q8 = p4.second;
  if( q7->first == 12 && q8->first == 14 )
    std::cout << "std::map::equal_range() #4 passed()\n";
  else
    std::cout << "std::map::equal_range() #4 failed()\n";

  // lower_bound()
  auto itr20 = eq_range_map1.lower_bound( 1 );
  if( itr20->first == 2 )
    std::cout << "std::map::lower_bound() passed()\n";
  else
    std::cout << "std::map::lower_bound() failed()\n";

  // upper_bound()
  auto itr21 = eq_range_map1.upper_bound( 5 );
  if( itr21->first == 6 )
    std::cout << "std::map::upper_bound() passed()\n";
  else
    std::cout << "std::map::upper_bound() failed()\n";

  ////////////
  // Observers
  ////////////
  // key_comp()
  std::cout << "--------------------------------" << std::endl;
  std::cout << "key_comp()\n";
  std::cout << "--------------------------------" << std::endl;
  std::map<int, std::string>::key_compare key_comp = eq_range_map1.key_comp();
  std::vector<int> key_val_vec;
  auto itr22 = eq_range_map1.begin();
  while( key_comp( ( *itr22++ ).first, 17 ) )
  {
    key_val_vec.push_back( itr22->first );
  }
  if( key_val_vec.size() == 8 )
    std::cout << "std::map::key_comp() passed()\n";
  else
    std::cout << "std::map::key_comp() failed()\n";

  std::cout << '\n';

  // value_comp()
  std::cout << "--------------------------------" << std::endl;
  std::cout << "value_comp()\n";
  std::cout << "--------------------------------" << std::endl;
  std::vector<int> value_val_vec;
  auto itr23 = eq_range_map2.begin();
  auto last = *eq_range_map2.rbegin();
  while( eq_range_map2.value_comp()(*itr23++, last) )
  {
    value_val_vec.push_back( itr23->second );
  }
  if( value_val_vec.size() == 7 )
    std::cout << "std::map::value_comp() passed()\n";
  else
    std::cout << "std::map::value_comp() failed()\n";

  std::cout << '\n';
}
