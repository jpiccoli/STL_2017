#include "../prototypes.h"

#include <string>
#include <bitset>

using namespace std::string_literals;

#pragma warning(disable:4996)

void std_string_operations()
{
  // TODO: 05/31/2020
  // istream::gcount

  /////////////////
  // Element access
  /////////////////
  // at()
  std::string const ref_str( "abcdefghijklmnopqrstuvwxyz" );
  if( ref_str.at( 25 ) == 'z' )
    std::cout << "std::string::at() passed\n";
  else
    std::cout << "std::string::at() failed\n";

  // operator[]
  if( ref_str[ 25 ] == 'z' )
    std::cout << "std::string::operator[] passed\n";
  else
    std::cout << "std::string::operator[] failed\n";

  // front()
  if( ref_str.front() == 'a' )
    std::cout << "std::string::front() passed\n";
  else
    std::cout << "std::string::front() failed\n";

  // back()
  if( ref_str.back() == 'z' )
    std::cout << "std::string::back() passed\n";
  else
    std::cout << "std::string::back() failed\n";

  // data()
  auto ptr = ref_str.data();
  if( *ptr == 'a')
    std::cout << "std::string::data() passed\n";
  else
    std::cout << "std::string::data() failed\n";

  // c_str()
  auto ptr1 = ref_str.c_str();
  if( std::string(ptr1) == ref_str )
    std::cout << "std::string::c_str() passed\n";
  else
    std::cout << "std::string::c_str() failed\n";

  ///////////
  // Capacity
  ///////////
  // empty()
  std::string empty_str{};
  if( empty_str.empty() )
    std::cout << "std::string::empty() passed\n";
  else
    std::cout << "std::string::empty() failed\n";

  // size()
  if( ref_str.size() == 26 )
    std::cout << "std::string::size() passed\n";
  else
    std::cout << "std::string::size() failed\n";

  // length()
  if( ref_str.length() == 26 )
    std::cout << "std::string::length() passed\n";
  else
    std::cout << "std::string::length() failed\n";

  // max_size()
  // Implementation-dependent

  // reserve()
  std::string reserve_str;
  reserve_str.reserve( 50 );
  if( reserve_str.capacity() >= 50 )
    std::cout << "std::string::reserve() passed\n";
  else
    std::cout << "std::string::reserve() failed\n";

  // capacity()
  std::string const capacity_str = "Exemplar is an example string";
  if( capacity_str.capacity() > capacity_str.size() )
    std::cout << "std::string::capacity() passed\n";
  else
    std::cout << "std::string::capacity() failed\n";

  // shrink_to_fit()
  std::string shrink_str;
  for( int i = 0; i < 42; ++i )
  {
    shrink_str.append( "42" );
  }
  auto capacity1 = shrink_str.capacity();
  shrink_str = shrink_str.substr( 0, 100 );
  auto capacity2 = shrink_str.capacity();
  if( capacity1 > capacity2 )
    std::cout << "std::string::shrink_str() passed\n";
  else
    std::cout << "std::string::shrink_str() failed\n";

  /////////////
  // Operations
  /////////////
  // clear()
  std::string clear_str = "This is a string";
  clear_str.clear();
  if( clear_str == "" )
    std::cout << "std::string::clear() passed\n";
  else
    std::cout << "std::string::clear() failed\n";

  // insert()
  std::string insert_string = "rcuy";
  insert_string.insert( 0, 1, 'M' );
  if( insert_string == "Mrcuy" )
    std::cout << "std::string::insert() #1 passed\n";
  else
    std::cout << "std::string::insert() #1 failed\n";

  insert_string.insert( 1, "e" );
  if( insert_string == "Mercuy" )
    std::cout << "std::string::insert() #2 passed\n";
  else
    std::cout << "std::string::insert() #2 failed\n";

  insert_string.insert( 5, "r"s );
  if( insert_string == "Mercury" )
    std::cout << "std::string::insert() #3 passed\n";
  else
    std::cout << "std::string::insert() #3 failed\n";

  insert_string.insert( 7, " Monarch", 0, 8 );
  if( insert_string == "Mercury Monarch" )
    std::cout << "std::string::insert() #4 passed\n";
  else
    std::cout << "std::string::insert() #4 failed\n";

  // push_back()
  std::string push_pop_str = "Mercury Monarch1976";
  push_pop_str.push_back('*');
  if( push_pop_str == "Mercury Monarch1976*" )
    std::cout << "std::string::push_back() passed\n";
  else
    std::cout << "std::string::push_back() failed\n";

  // pop_back()
  push_pop_str.pop_back();
  if( push_pop_str == "Mercury Monarch1976" )
    std::cout << "std::string::pop_back() passed\n";
  else
    std::cout << "std::string::pop_back() failed\n";

  // append()
  auto append_str = push_pop_str;
  append_str.append( "-1983" );
  if( append_str == "Mercury Monarch1976-1983" )
    std::cout << "std::string::append() passed\n";
  else
    std::cout << "std::string::append() failed\n";

  // operator+=
  std::string concat_str = "Mercury";
  concat_str += " Monterey";
  if( concat_str == "Mercury Monterey" )
    std::cout << "std::string::operator+= passed\n";
  else
    std::cout << "std::string::operator+= failed\n";

  // compare()
  std::string const compare1 = "Compare1";
  std::string const compare2 = "Compare2";
  std::string const compare3 = "Compare1";
  if( compare1.compare( compare2 ) )
    std::cout << "std::string::compare() #1 passed\n";
  else
    std::cout << "std::string::compare() #1 failed\n";

  if( !compare1.compare( compare3 ) )
    std::cout << "std::string::compare() #2 passed\n";
  else
    std::cout << "std::string::compare() #2 failed\n";

  // replace()
  std::string replace_str = "the resulting string will exceed the maximum possible string length of the string";
  replace_str.replace( 21, 4, "may" );
  if( replace_str == "the resulting string may exceed the maximum possible string length of the string" )
    std::cout << "std::string::replace() #1 passed\n";
  else
    std::cout << "std::string::replace() #1 failed\n";

  replace_str.replace( replace_str.begin(), replace_str.begin() + 3, 1, 'A' );
  if( replace_str == "A resulting string may exceed the maximum possible string length of the string" )
    std::cout << "std::string::replace() #2 passed\n";
  else
    std::cout << "std::string::replace() #2 failed\n";

  // substr()
  std::string substr_str = "String1 String2 String3 String4";
  auto substr1 = substr_str.substr( 8 );
  if( substr1 == "String2 String3 String4" )
    std::cout << "std::string::substr() #1 passed\n";
  else
    std::cout << "std::string::substr() #1 failed\n";

  auto substr2 = substr_str.substr( 8, 7 );
  if( substr2 == "String2" )
    std::cout << "std::string::substr() #2 passed\n";
  else
    std::cout << "std::string::substr() #2 failed\n";

  // copy()
  std::string copy_str{ "quuuux" };
  char bar1[ 7 ]{};
  copy_str.copy( bar1, sizeof bar1 );
  if( std::string( bar1 ) == "quuuux" )
    std::cout << "std::string::copy() #1 passed\n";
  else
    std::cout << "std::string::copy() #1 failed\n";

  char bar2[ 7 ]{};
  copy_str.copy( bar2, 5 );
  if( std::string( bar2 ) == "quuuu" )
    std::cout << "std::string::copy() #2 passed\n";
  else
    std::cout << "std::string::copy() #2 failed\n";

  // resize()
  std::string long_string( "This is the end - Doors" );
  std::string short_string( "Go" );
  long_string.resize( 15 );
  if( long_string == "This is the end" )
    std::cout << "std::string::resize() #1 passed\n";
  else
    std::cout << "std::string::resize() #1 failed\n";

  short_string.resize( 7, 'o' );
  if( short_string == "Goooooo" )
    std::cout << "std::string::resize() #2 passed\n";
  else
    std::cout << "std::string::resize() #2 failed\n";

  // swap()
  std::string string1 = "21,23,27,29,31,33";
  std::string string2 = "61,63,67,69,71,73";
  string1.swap( string2 );
  if( string1 == "61,63,67,69,71,73" && string2 == "21,23,27,29,31,33" )
    std::cout << "std::string::swap() passed\n";
  else
    std::cout << "std::string::swap() failed\n";

  /////////
  // Search
  /////////
  // find()
  std::string const find_str( "12341234" );
  auto find_pos1 = find_str.find( "123" );
  if( find_pos1 == 0 )
    std::cout << "std::string::find() #1 passed\n";
  else
    std::cout << "std::string::find() #1 failed\n";

  auto find_pos2 = find_str.find( "123", 1 );
  if( find_pos2 == 4 )
    std::cout << "std::string::find() #1 passed\n";
  else
    std::cout << "std::string::find() #1 failed\n";

  // rfind()
  std::string const rfind_str = "This is a string that is being tested for what it is";
  auto rfind_pos1 = rfind_str.rfind( "is" );
  if( rfind_pos1 == 50 )
    std::cout << "std::string::rfind() #1 passed\n";
  else
    std::cout << "std::string::rfind() #1 failed\n";

  auto rfind_pos2 = rfind_str.rfind( "is", 8 );
  if( rfind_pos2 == 5 )
    std::cout << "std::string::rfind() #2 passed\n";
  else
    std::cout << "std::string::rfind() #2 failed\n";

  // find_first_of()
  auto ffo_pos1 = rfind_str.find_first_of( "is" );
  if( ffo_pos1 == 2 )
    std::cout << "std::string::find_first_of() #1 passed\n";
  else
    std::cout << "std::string::find_first_of() #1 failed\n";

  auto ffo_pos2 = rfind_str.find_first_of( "is", 14 );
  if( ffo_pos2 == 22 )
    std::cout << "std::string::find_first_of() #2 passed\n";
  else
    std::cout << "std::string::find_first_of() #2 failed\n";

  // find_first_not_of()
  std::string const ffon_str1 = "121212129";
  auto ffon_pos1 = ffon_str1.find_first_not_of( "12" );
  if( ffon_pos1 == 8 )
    std::cout << "std::string::find_first_not_of() #1 passed\n";
  else
    std::cout << "std::string::find_first_not_of() #1 failed\n";

  // find_last_of()
  std::string const flo_str = "121212129";
  auto flo_pos1 = flo_str.find_last_of( "12" );
  if( flo_pos1 == 7 ) // position of last '2'
    std::cout << "std::string::find_last_of() #1 passed\n";
  else
    std::cout << "std::string::find_last_of() #1 failed\n";

  auto flo_pos2 = flo_str.find_last_of( "12", 6 );
  if( flo_pos2 == 6 ) // position of last '2'
    std::cout << "std::string::find_last_of() #2 passed\n";
  else
    std::cout << "std::string::find_last_of() #2 failed\n";

  // find_last_not_of()
  std::string const flno_str1{ "JKL_234" };
  std::string const flno_str11{ "345" };
  auto flno_pos1 = flno_str1.find_last_not_of( flno_str11 );
  if( flno_pos1 == 4 )  // finds '2'
    std::cout << "std::string::find_last_not_of() #1 passed\n";
  else
    std::cout << "std::string::find_last_not_of() #1 failed\n";

  std::string const flno_str2{ "XYZ_678" };
  char const* skip_set{ "0123456789" };
  auto flno_pos2 = flno_str2.find_last_not_of( skip_set );
  if( flno_pos2 == 3 )  // finds '_'
    std::cout << "std::string::find_last_not_of() #2 passed\n";
  else
    std::cout << "std::string::find_last_not_of() #2 failed\n";

  std::string const flno_str3{ "123123123123" };
  auto flno_pos3 = flno_str3.find_last_not_of( "12", 4 );
  if( flno_pos3 == 2 )  // finds first '3'
    std::cout << "std::string::find_last_not_of() #3 passed\n";
  else
    std::cout << "std::string::find_last_not_of() #3 failed\n";

  auto flno_pos4 = flno_str3.find_last_not_of( "12", 7 );
  if( flno_pos4 == 5 )  // finds a later '3'
    std::cout << "std::string::find_last_not_of() #4 passed\n";
  else
    std::cout << "std::string::find_last_not_of() #4 failed\n";
}
