#include "../prototypes.h"

#include <iomanip>
#include <functional>
#include <chrono>
#include <set>

// Used to test emplace()
struct Dew
{
  int a;
  int b;
  int c;

  Dew() {}

  Dew( int _a, int _b, int _c ) : a( _a ), b( _b ), c( _c ) {}

  bool operator<( Dew const& other ) const
  {
    if( ( a < other.a ) || ( a == other.a && b < other.b ) )
      return true;

    return (a == other.a && b == other.c && c < other.c);
  }
};

struct Comp
{
  bool operator()( int lhs, int rhs )
  {
    return lhs < rhs;
  }
};

void container_set()
{
  ////////////
  // Iterators
  ////////////
  // begin(), cbegin()

  // end(), cend()

  // rend(), rcend()

  ///////////
  // Capacity
  ///////////
  std::set<int> set4{ 26, 23, 24 };
  std::set<int> set5;

  // empty()
  if( !set4.empty() && set5.empty() )
    std::cout << "std::set::empty() passes\n";
  else 
    std::cout << "std::set::empty() fails\n";

  // size()
  if( set4.size() == 3 && !set5.size() )
    std::cout << "std::set::size() passes\n";
  else
    std::cout << "std::set::size() fails\n";

  // max_size()
  if( set4.max_size() > 0 )
    std::cout << "std::set::max_size() passes\n";
  else
    std::cout << "std::set::max_size() fails\n";

  ///////////
  //Modifiers
  ///////////
  std::set<int> set6{ 26, 23, 24 };
  std::set<int> set7{ 26, 23, 24 };

  // clear()
  set6.clear();
  if( set6.size() == 0 )
    std::cout << "std::set::clear() passes\n";
  else
    std::cout << "std::set::clear() fails\n";

  // insert()
  auto result1 = set7.insert( 27 );
  if(*result1.first == 27 && result1.second == true)
    std::cout << "std::set::insert() #1 passes\n";
  else
    std::cout << "std::set::insert() #1 fails\n";

  auto result2 = set7.insert( 27 );
  if( *result2.first == 27 && result2.second == false )
    std::cout << "std::set::insert() #2 passes\n";
  else
    std::cout << "std::set::insert() #2 fails\n";

  // emplace()
  //std::set<Dew> set1;
  //auto start1 = std::chrono::system_clock::now();
  //for( int i = 0; i < 121; ++i )
  //  for( int j = 0; j < 121; ++j )
  //    for( int k = 0; k < 121; ++k )
  //      set1.insert( Dew( i, j, k ) );
  //auto stop1 = std::chrono::system_clock::now();
  //std::chrono::duration<double, std::milli> time1 = stop1 - start1;
  //std::cout << "Insert time = " << std::fixed << std::setprecision( 2 ) << time1.count() << '\n';

  //std::set<Dew> set2;
  //auto start2 = std::chrono::system_clock::now();
  //for( int i = 0; i < 121; ++i )
  //  for( int j = 0; j < 121; ++j )
  //    for( int k = 0; k < 121; ++k )
  //      set2.emplace( i, j, k );
  //auto stop2 = std::chrono::system_clock::now();
  //std::chrono::duration<double, std::milli> time2 = stop2 - start2;
  //std::cout << "Emplace time = " << std::fixed << std::setprecision( 2 ) << time2.count() << '\n';

  //std::cout << '\n';

  // emplace_hint()

  // erase()
  std::set<int> set9 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for( auto it = set9.begin(); it != set9.end(); )
  {
    if( *it % 2 == 1 )
      it = set9.erase( it );
    else
      ++it;
  }
  if( set9.find( 2 ) != set9.end() && set9.find( 4 ) != set9.end() && set9.find( 6 ) != set9.end() && set9.find( 8 ) != set9.end() )
    std::cout << "std::set::erase() passes\n";
  else
    std::cout << "std::set::erase() fails\n";

  // swap()
  std::set<int> set11 = { 20, 21 };
  std::set<int> set12 = { 22, 23 };
  set11.swap( set12 );
  if( set11.find( 22 ) != set11.end() && set11.find( 23 ) != set11.end() && set12.find( 20 ) != set12.end() && set12.find( 21 ) != set12.end() )
    std::cout << "std::set::swap() passes\n";
  else
    std::cout << "std::set::swap() fails\n";

  // extract()
  std::set<int> set14 = { 24, 26, 27, 29 };
  auto node_ref = set14.extract( 24 );
  if( set14.size() == 3 )
    std::cout << "std::set::extract() passes\n";
  else
    std::cout << "std::set::extract() fails\n";

  // merge()
  std::set<int> set15 = { 24, 27, 31, 35 };
  std::set<int> set16 = { 23, 26, 29, 33, 36 };
  set15.merge( set16 );
  if( set15.size() == 9 )
    std::cout << "std::set::merge() passes\n";
  else
    std::cout << "std::set::merge() fails\n";

  /////////
  // Lookup
  /////////
  // count()
  std::set<int> set17 = { 24, 27, 31, 33, 35, 35, 37 };
  if( set17.count(35) == 1 )
    std::cout << "std::set::merge() passes\n";
  else
    std::cout << "std::set::merge() fails\n";

  // find()
  if( set17.find( 24 ) != set17.end() )
    std::cout << "std::set::find() #1 passes\n";
  else
    std::cout << "std::set::find() #1 fails\n";

  if( set17.find( 34 ) == set17.end() )
    std::cout << "std::set::find() #2 passes\n";
  else
    std::cout << "std::set::find() #2 fails\n";

  // equal_range()
  std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
  ret = set17.equal_range( 27 );
  if(*ret.first == 27 && *ret.second == 31 )
    std::cout << "std::set::equal_range() passes\n";
  else
    std::cout << "std::set::equal_range() fails\n";

  // lower_bound()
  auto ret1 = set17.lower_bound( 32 );
  if(*ret1 == 33 )
    std::cout << "std::set::lower_bound() passes\n";
  else
    std::cout << "std::set::lower_bound() fails\n";

  // upper_bound()
  auto ret2 = set17.upper_bound( 29 );
  if( *ret2 == 31 )
    std::cout << "std::set::upper_bound() passes\n";
  else
    std::cout << "std::set::upper_bound() fails\n";

  ////////////
  // Observers
  ////////////
  // key_comp()
  std::set<int, Comp> set18 = { 97, 98, 99, 100, 101, 102, 103 };
  auto comp_func = set18.key_comp();
  std::vector<int> results;
  int index = 0;
  for( int key : set18 )
  {
    bool before = comp_func( key, 100 );
    bool after = comp_func( 100, key );
    if( !before && !after )
      results.push_back( 0 );
    if( before && !after )
      results.push_back( -1 );
    else
      results.push_back( 1 );
  }

  auto status1 = results[ 0 ] == -1 && results[ 1 ] == -1 && results[ 2 ] == -1;
  auto status2 = results[ 3 ] == 0;
  auto status3 = results[ 4 ] == 1 && results[ 5 ] == 1 && results[ 6 ] == 1;
  if( status1 && status2 && status3 )
    std::cout << "std::set::key_comp() passes\n";
  else
    std::cout << "std::set::key_comp() fails\n";

  // value_comp()
  // Same implementation used for key_comp()
}
