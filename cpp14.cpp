#include "cpp14.h"

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

using namespace std;

template<typename T>
constexpr T pi = T( 3.141592653589793238462643383 );

auto deduce_return_type()
{
  return 7;
}

int&& f()
{
  int i = 42;
  return std::move(i);
}

[[ deprecated("g() is thread-unsafe.") ]] int g()
{
  return 99;
}

// More flexible constexpr
constexpr int factorial( int n )
{
  if( n <= 1 )
    return 1;

  return n * factorial( n - 1 );
}

void show_cpp_14_features()
{
  //std::cout << '\n';
  //std::cout << "--------------\n";
  //std::cout << "C++14 features\n";
  //std::cout << "--------------\n";

  //auto bn = std::bit_not()(17);
  //std::cout << "bit_not() = " << bn << '\n';

  //auto original = 27;
  //auto replace = std::exchange( original, 29 );
  //std::cout << "std::exchange() old value = " << replace << '\n';
  //std::cout << "std::exchange() new value = " << original << '\n';

  // integer_sequence
  // Reference: https://msdn.microsoft.com/en-us/library/mt125500.aspx

  // Function return type deduction
  std::cout << "Deduce return type = " << deduce_return_type() << "\n\n";

  // Alternate type declaration on declaration
  int i = 43;
  auto x3a = i;
  decltype(i) x3d = i;
  auto x4a = (i);
  decltype((i)) x4d = (i);
  auto x5a = f();
  decltype(f()) x5d = f();
  std::cout << "Type of x3a = " << typeid(x3a).name() << '\n';
  std::cout << "Type of x3d = " << typeid(x3d).name() << '\n';
  std::cout << "Type of x4a = " << typeid(x4a).name() << '\n';
  std::cout << "Type of x4a = " << typeid(x4d).name() << '\n';
  std::cout << "Type of x5a = " << typeid(x4a).name() << '\n';
  std::cout << "Type of x5d = " << typeid(x5d).name() << '\n';

  // More flexible constexpr
  std::cout << "Flexible constexpr = " << factorial( 5 ) << '\n';

  // Variable templates
  std::cout << "Pi = " << pi<double> << '\n';

  // Aggregate member initialization

  // Binary literals
  auto z = 0b111;
  std::cout << "Binary literal value = " << z << '\n';

  // Digit separators

  // Generic lambdas
  auto generic_lambda = [] ( auto x, auto y ) { return x * y; };
  auto lambda_result = generic_lambda( 7, 8 );
  std::cout << "Generic lambda = " << lambda_result << '\n';

  // Lambda capture expressions
  auto lambda_capture = [ value = 9 ]( auto x, auto y ){ return x * y * value; };
  auto capture_result = lambda_capture( 7, 8 );
  std::cout << "Lambda capture #1 = " << capture_result << '\n';

  std::unique_ptr<int> ptr( new int( 11 ) );
  auto lambda_capture2 = [ value = std::move(ptr) ]( auto x, auto y ){ return x * y * *value; };
  auto capture_result2 = lambda_capture2( 7, 8 );
  std::cout << "Lambda capture #2 = " << capture_result2 << '\n';

  // User-defined literals - requires "using namespace::std;" for predefined literals
  std::string str1 = "Hello"s + " "s + "World!"s;
  std::cout << "User defined literal #1 = " << str1 << '\n';

  auto day = 30h;
  std::cout << "User defined literal #2 = " << day.count() << '\n';


  // Additional: https://docs.microsoft.com/en-us/cpp/cpp/user-defined-literals-cpp

  // Tuple addressing via type
  std::cout << "\nTuple addressing via type:\n";
  std::tuple<std::string, char, int, double> t( "Addr", 'Z', 47, 27.3 );
  std::cout << "String = " << std::get<std::string>( t ) << '\n';
  std::cout << "Char = " << std::get<char>( t ) << '\n';
  std::cout << "Int = " << std::get<int>( t ) << '\n';
  std::cout << "Double = " << std::get<double>( t ) << '\n';

  // [[deprecated]] attribute
  // Causes compilation error.
  // g();
}
