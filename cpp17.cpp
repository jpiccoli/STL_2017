#include "cpp17.h"

#include <algorithm>
#include <charconv>
#include <chrono>
#include <execution>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include <any>
#include <variant>

#include <boost/any.hpp>
#include <boost/variant.hpp>

int multiply_values( int a, int b, int c )
{
  return a * b * c;
}

int invoke_test_function( int a, int b )
{
  return a + b;
}

struct MakeFromTuple
{
  MakeFromTuple( int i_, std::string s_ ) : i( i_ ), s( s_ ) {}

  int i;
  std::string s;
};

void show_cpp_17_features()
{
  std::cout << '\n';

  // Selection statements with initializers

  std::cout << "----------------\n";
  std::cout << "Any\n";
  std::cout << "----------------\n\n";

  std::cout << "----------------\n";
  std::cout << "C++ 17 std::any:\n";
  std::cout << "----------------\n";
  auto a = std::any( 42 );
  std::cout << "a #1 = " << std::any_cast<int>(a) << '\n';
  a = true;
  std::cout << "a #2 = " << std::boolalpha << std::any_cast<bool>(a) << '\n';

  std::cout << std::endl;

  std::cout << "----------\n";
  std::cout << "boost::any\n";
  std::cout << "----------\n";
  boost::any b = 1;
  std::cout << "b #1 = " << boost::any_cast<int>(b) << '\n';
  std::cout << "Type = " << b.type().name() << '\n';

  b = 3.14;
  std::cout << "b #2 = " << boost::any_cast<double>(b) << '\n';
  std::cout << "Type = " << b.type().name() << '\n';

  b = true;
  std::cout << "b # = 3 " << std::boolalpha << boost::any_cast<bool>(b) << '\n';
  std::cout << "Type = " << b.type().name() << '\n';
  std::cout << std::endl;

  //https://en.cppreference.com/w/cpp/utility/variant/visit

  std::cout << "------------------------\n";
  std::cout << "Variant\n";
  std::cout << "------------------------\n";


  std::cout << "------------------------\n";
  std::cout << "boost::variant\n";
  std::cout << "------------------------\n";

  std::cout << '\n';

  std::cout << "------------------------\n";
  std::cout << "Structured Binding\n";
  std::cout << "------------------------\n";
  std::pair<int, int> p1( 27, 29 );
  auto [ ip, kp ] = p1;
  if( ip == 27 && kp == 29 )
    std::cout << "Structured binding #1 success\n";
  else
    std::cout << "Structured binding #1 failure\n";

  auto[ asb, isb, bsb ] = std::tuple( "AAA", 123, true );
  if( asb == "AAA" && isb == 123 && bsb == true )
    std::cout << "Structured binding #2 success\n";
  else
    std::cout << "Structured binding #2 failure\n";

  std::cout << '\n';

  std::cout << "--------------\n";
  std::cout << "STL Algorithms\n";
  std::cout << "--------------\n";
  
  // for_each_n
  std::vector<int> v1{ 3, 5, 7, 9, 11, 15, 17 };
  std::for_each_n( v1.begin(), 4, [] ( auto& n ) { n = n * n; } );
  if( v1[ 0 ] != 9  || v1[ 1 ] != 25 || v1[ 2 ] != 49 || v1[ 3 ] != 81 ||
      v1[ 4 ] != 11 || v1[ 5 ] != 15 || v1[ 6 ] != 17 )
    std::cout << "std::for_each_n failure\n\n";
  else
    std::cout << "std::for_each_n success\n\n";

  // sample
  std::vector<int> v2;
  std::sample( v1.begin(), v1.end(), std::back_inserter( v2 ), 2, std::mt19937{ std::random_device{}() } );
  std::cout << "std::sample() output = ";
  for( auto val : v2 )
    std::cout << val << ", ";

  std::cout << "\n\n";

  // clamp
  auto low = 27;
  auto high = 123;
  auto res1 = std::clamp( 23, low, high );
  if( res1 == 27 )
    std::cout << "std::clamp() for below low passed\n";
  else
    std::cout << "std::clamp() for below low failed\n";

  res1 = std::clamp( 124, low, high );
  if( res1 == 123 )
    std::cout << "std::clamp() for above high passed\n";
  else
    std::cout << "std::clamp() for above high failed\n";

  res1 = std::clamp( 77, low, high );
  if( res1 == 77 )
    std::cout << "std::clamp() for in range value passed\n\n";
  else
    std::cout << "std::clamp() for in range value failed\n\n";

  std::cout << "--------------\n";
  std::cout << "STL Numerics\n";
  std::cout << "--------------\n";
  // std::reduce -> compare with std::accumulate
  std::vector<double> v( 100'000, 0.5 );
  auto t1a = std::chrono::high_resolution_clock::now();
  double result1 = std::accumulate( v.begin(), v.end(), 11.0 );
  auto t2a = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms1 = t2a - t1a;
  std::cout << std::fixed << "std::accumulate = " << result1 << " time = " << ms1.count() << " ms\n";

  auto t1r = std::chrono::high_resolution_clock::now();
  double result2 = std::reduce( v.begin(), v.end(), 11.0 );
  auto t2r = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms2 = t2r - t1r;
  std::cout << std::fixed << "std::reduce = " << result2 << " time = " << ms2.count() << " ms\n\n";

  // exclusive_scan
  std::vector<int> scan_input{ 7, 14, 21, 30, 36, 42, 50, 56, 63 };
  std::vector<int> scan_output;
  auto exclusive_it = std::exclusive_scan( scan_input.begin() + 2, scan_input.end() - 2, std::back_inserter( scan_output ), 0 );
  if( scan_output.size() == 5 )
  {
    std::cout << "exclusive_output() #1 passed\n";
    if( scan_output[ 0 ] == 0 && scan_output[ 1 ] == 21 && scan_output[ 2 ] == 51 && scan_output[ 3 ] == 87 && scan_output[ 4 ] == 129 )
      std::cout << "exclusive_output() #2 passed\n";
    else
      std::cout << "exclusive_output() #2 passed\n";
  }
  else
    std::cout << "exclusive_output() #1 failed\n";

  std::cout << '\n';

  scan_output.clear();

  // inclusive_scan
  auto inclusive_it = std::inclusive_scan( scan_input.begin() + 2, scan_input.end() - 2, std::back_inserter( scan_output ) );
  if( scan_output.size() == 5 )
  {
    std::cout << "inclusive_output() #1 passed\n";
    if( scan_output[0] == 21 && scan_output[1]== 51 && scan_output[2] == 87 && scan_output[3] == 129 && scan_output[4] == 179 )
      std::cout << "inclusive_output() #2 passed\n";
    else
      std::cout << "inclusive_output() #2 passed\n";
  }
  else
    std::cout << "inclusive_output() #1 failed\n";

  std::cout << '\n';

  // transform_reduce
  std::vector<double> vtr1( 100'000, 1.0 );
  std::vector<double> vtr2( 100'000, 1.0 );
  std::vector<double> result_transform_only(vtr1.size());
  t1r = std::chrono::high_resolution_clock::now();
  std::transform( vtr1.begin(), vtr1.end(), result_transform_only.begin(), [] ( double const &d ) { return d * 2; } );
  t2r = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms3 = t2r - t1r;
  std::cout << std::fixed << "std::transform() time = " << ms3.count() << " ms\n";

  auto t1tr = std::chrono::high_resolution_clock::now();
  auto v3 = std::transform_reduce( vtr1.begin(), vtr1.end(), vtr2.begin(), 0.0 );
  auto t2tr = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms4 = t2tr - t1tr;
  std::cout << std::fixed << "std::transform_reduce() = " << v3 << " serial time =  " << ms4.count() << " ms\n";

  t1tr = std::chrono::high_resolution_clock::now();
  auto v4 = std::transform_reduce(std::execution::par, vtr1.begin(), vtr1.end(), vtr2.begin(), 0.0 );
  t2tr = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms5 = t2tr - t1tr;
  std::cout << std::fixed << "std::transform_reduce() = " << v4 << " parallel time = " << ms5.count() << " ms\n\n";

  // transform_exclusive_scan
  // transform_inclusive_scan

  // gcd
  auto gcd_value = std::gcd( 42, 70 );
  if( gcd_value == 14 )
    std::cout << "std::gcd() passed\n\n";
  else
    std::cout << "std::gcd() failed\n\n";

  // lcm
  auto lcm_value = std::lcm( 6, 15 );
  if( lcm_value == 30 )
    std::cout << "std::lcm() passed\n\n";
  else
    std::cout << "std::lcm() failed\n\n";

  std::cout << "--------------\n";
  std::cout << "STL Functional\n";
  std::cout << "--------------\n";

  // invoke
  auto result = std::invoke( invoke_test_function, 7, 14 );
  if( result == 21 )
    std::cout << "std::invoke() #1 passed\n";
  else
    std::cout << "std::invoke() #1 failed\n";

  result = std::invoke( [] ()-> int { return invoke_test_function( 9, 17 ); } );
  if( result == 26 )
    std::cout << "std::invoke() #2 passed\n";
  else
    std::cout << "std::invoke() #2 failed\n";

  // not_fn
  typedef std::function<bool(int)> is_odd;
  is_odd const odd_func = []( int x )->bool{ return ( x % 2 ) == 1; };
  auto even_func = std::not_fn( odd_func );
  auto result_not_fn = even_func( 7 );
  if( !result_not_fn )
    std::cout << "std::not_fn() #1 passed" << std::endl;
  else
    std::cout << "std::not_fn() #1 failed" << std::endl;
  
  result_not_fn = even_func( 8 );
  if ( result_not_fn )
    std::cout << "std::not_fn() #2 passed" << std::endl;
  else
    std::cout << "std::not_fn() #2 failed" << std::endl;

  typedef std::function<bool(int, int)> is_equal;
  is_equal const equal_func = [](int x, int y)->bool{ return x == y; };
  auto not_equal_func = std::not_fn( equal_func );
  result_not_fn = not_equal_func( 7, 7 );
  if (!result_not_fn )
    std::cout << "std::not_fn() #3 passed" << std::endl;
  else
    std::cout << "std::not_fn() #3 failed" << std::endl;
  
  result_not_fn = not_equal_func( 7, 8 );
  if ( result_not_fn )
    std::cout << "std::not_fn() #4 passed" << std::endl;
  else
    std::cout << "std::not_fn() #4 failed" << std::endl;

  // default_searcher
  //std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
  //  " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
  //std::string needle = "pisci";
  //auto it = std::search( in.begin(), in.end(),
  //  std::default_searcher(
  //    needle.begin(), needle.end() ) );
  //if( it != in.end() )
  //  std::cout << "The string " << needle << " found at offset "
  //  << it - in.begin() << "\n\n";
  //else
  //  std::cout << "The string " << needle << " not found\n\n";

  // boyer_moore_searcher
  // boyer_moore_horspool_searcher

  std::cout << '\n';

  std::cout << "--------------\n";
  std::cout << "STL Utility\n";
  std::cout << "--------------\n";

  // byte

  // apply
  auto apply_tuple = std::make_tuple( 2, 3, 4 );
  auto apply_result = std::apply( multiply_values, apply_tuple );
  if( apply_result == 24 )
    std::cout << "std::apply() passed\n\n";
  else
    std::cout << "std::apply() failed\n\n";

  // make_from_tuple
  auto tuple_base = std::make_tuple( 97, std::string( "MakeFromTupleTest" ) );
  auto mft = std::make_from_tuple<MakeFromTuple>( std::move( tuple_base ) );
  if( mft.i == 97 && mft.s == "MakeFromTupleTest" )
    std::cout << "std::make_from_tuple passed()\n\n";
  else
    std::cout << "std::make_from_tuple failed\n\n";

  // to_chars
  std::array<char, 11> char_array;
  auto [p, ec] = std::to_chars( char_array.data(), char_array.data() + char_array.size(), 2797 );
  if( ec == std::errc() )
  {
    std::string_view sv( char_array.data(), p - char_array.data() );
    std::string str( sv );
    if( str == "2797" )
      std::cout << "std::to_chars() passed\n\n";
    else
      std::cout << "std::to_chars() #2 failed\n\n";
  }
  else
  {
    std::cout << "std::to_chars() #1 failed\n\n";
  }

  // from_chars
  std::string conv_source( "727" );
  int conv_value;
  std::from_chars( conv_source.c_str(), conv_source.c_str() + conv_source.size(), conv_value );
  if( conv_value == 727 )
    std::cout << "std::from_chars() passed\n\n";
  else
    std::cout << "std::from_chars() failed\n\n";

  // chars_format
  // Not supported by compiler - 12/23/2018
}
