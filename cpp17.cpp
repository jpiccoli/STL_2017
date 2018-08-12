#include "cpp17.h"

#include <algorithm>
#include <chrono>
#include <execution>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

#include <any>
#include <variant>

#include <boost/any.hpp>
#include <boost/variant.hpp>

void show_cpp_17_features()
{
  //std::cout << "\n\n";
  //std::cout << "--------------\n";
  //std::cout << "C++17 features\n";
  //std::cout << "--------------\n";

  std::cout << '\n';

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



  std::cout << '\n';

  //std::cout << "--------------\n";
  //std::cout << "STL Algorithms\n";
  //std::cout << "--------------\n";
  
  // for_each_n
  //std::vector<int> v1{ 3, 5, 7, 9, 11, 15, 17 };
  //std::for_each_n( v1.begin(), 4, [] ( auto& n ) { n = n * n; } );
  //if( v1[ 0 ] != 9  || v1[ 1 ] != 25 || v1[ 2 ] != 49 || v1[ 3 ] != 81 ||
  //    v1[ 4 ] != 11 || v1[ 5 ] != 15 || v1[ 6 ] != 17 )
  //  std::cout << "std::for_each_n failure\n\n";
  //else
  //  std::cout << "std::for_each_n success\n\n";

  // sample
  //std::vector<int> v2;
  //std::sample( v1.begin(), v1.end(), std::back_inserter( v2 ), 2, std::mt19937{ std::random_device{}() } );
  //std::cout << "std::sample() output = ";
  //for( auto val : v2 )
  //  std::cout << val << ", ";

  //std::cout << "\n\n";

  // clamp
  //auto low = 27;
  //auto high = 123;
  //auto res1 = std::clamp( 23, low, high );
  //if( res1 == 27 )
  //  std::cout << "std::clamp() for below low passed\n";
  //else
  //  std::cout << "std::clamp() for below low failed\n";

  //res1 = std::clamp( 124, low, high );
  //if( res1 == 123 )
  //  std::cout << "std::clamp() for above high passed\n";
  //else
  //  std::cout << "std::clamp() for above high failed\n";

  //res1 = std::clamp( 77, low, high );
  //if( res1 == 77 )
  //  std::cout << "std::clamp() for in range value passed\n\n";
  //else
  //  std::cout << "std::clamp() for in range value failed\n\n";

  //std::cout << "--------------\n";
  //std::cout << "STL Numerics\n";
  //std::cout << "--------------\n";
  //// std::reduce -> compare with std::accumulate
  //std::vector<double> v( 100'000, 0.5 );
  //auto t1a = std::chrono::high_resolution_clock::now();
  //double result1 = std::accumulate( v.begin(), v.end(), 11.0 );
  //auto t2a = std::chrono::high_resolution_clock::now();
  //std::chrono::duration<double, std::milli> ms1 = t2a - t1a;
  //std::cout << std::fixed << "std::accumulate = " << result1 << " took " << ms1.count() << " ms\n";

  //auto t1r = std::chrono::high_resolution_clock::now();
  //double result2 = std::reduce(/*std::execution::par,*/ v.begin(), v.end(), 11.0 );
  //auto t2r = std::chrono::high_resolution_clock::now();
  //std::chrono::duration<double, std::milli> ms2 = t2r - t1r;
  //std::cout << std::fixed << "std::reduce = " << result2 << " took " << ms2.count() << " ms\n\n";

  // exclusive_scan
  //std::vector<int> scan_input{ 7, 14, 21, 30, 36, 42, 50, 56, 63 };
  //std::vector<int> scan_output;
  //auto exclusive_it = std::exclusive_scan( scan_input.begin() + 2, scan_input.end() - 2, std::back_inserter( scan_output ), 0 );
  //if( scan_output.size() == 5 )
  //{
  //  std::cout << "exclusive_output() #1 passed\n";
  //  if( scan_output[ 0 ] == 0 && scan_output[ 1 ] == 21 && scan_output[ 2 ] == 51 && scan_output[ 3 ] == 87 && scan_output[ 4 ] == 129 )
  //    std::cout << "exclusive_output() #2 passed\n";
  //  else
  //    std::cout << "exclusive_output() #2 passed\n";
  //}
  //else
  //  std::cout << "exclusive_output() #1 failed\n";

  //std::cout << '\n';

  //scan_output.clear();

  // inclusive_scan
  //auto inclusive_it = std::inclusive_scan( scan_input.begin() + 2, scan_input.end() - 2, std::back_inserter( scan_output ) );
  //if( scan_output.size() == 5 )
  //{
  //  std::cout << "inclusive_output() #1 passed\n";
  //  if( scan_output[0] == 21 && scan_output[1]== 51 && scan_output[2] == 87 && scan_output[3] == 129 && scan_output[4] == 179 )
  //    std::cout << "inclusive_output() #2 passed\n";
  //  else
  //    std::cout << "inclusive_output() #2 passed\n";
  //}
  //else
  //  std::cout << "inclusive_output() #1 failed\n";

  //std::cout << '\n';

  // transform_reduce
  // transform_exclusive_scan
  // transform_inclusive_scan

  // gcd
  //auto gcd_value = std::gcd( 42, 70 );
  //if( gcd_value == 14 )
  //  std::cout << "std::gcd() passed\n\n";
  //else
  //  std::cout << "std::gcd() failed\n\n";

  // lcm
  //auto lcm_value = std::lcm( 6, 15 );
  //if( lcm_value == 30 )
  //  std::cout << "std::lcm() passed\n\n";
  //else
  //  std::cout << "std::lcm() failed\n\n";

  //std::cout << "--------------\n";
  //std::cout << "STL Functional\n";
  //std::cout << "--------------\n";

  // invoke
  // not_fn

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

  // Utility
  // byte
  // apply
  // make_from_tuple
  // to_chars
  // from_chars
  // chars_format
}
