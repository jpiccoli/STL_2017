#include "../constructs.h"

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

void generic_lambda()
{
  auto square = [] ( auto x ) { return x * x; };

  auto val = square( 11 );

  if( val == 121 )
    std::cout << "Generic Lambda passed\n";
  else
    std::cout << "Generic Lambda failed\n";
}

void generalized_lambda_capture()
{
  int x = 27;
  auto square = [ value = x ]() { return value * value; };

  auto val = square();

  if( val == 729 )
    std::cout << "Generalized Lambda Capture passed\n";
  else
    std::cout << "Generalized Lambda Capture failed\n";
}

template<typename T>
T adder( T v ) {
  return v;
}

template<typename T, typename... Args>
T adder( T first, Args... args ) {
  return first + adder( args... );
}

// Reference: https://thispointer.com/c11-variadic-template-function-tutorial-examples/
// Reference: https://eli.thegreenplace.net/2014/variadic-templates-in-c/
void test_simple_variadic()
{
  auto sum = adder( 11, 22, 33, 44, 55, 66, 77 );

  if( sum == 308 )
    std::cout << "Simple Variadic passed\n";
  else
    std::cout << "Simple Variadic failed\n";
}

// TODO: 09/15/2019
// Create more complex examples

void test_string_literal()
{
  std::string str1 = R"(C:\Temp\Log.txt)";
  std::string str2 = R"token(C:\Temp\Log.txt"))token";

  if( str1 == "C:\\Temp\\Log.txt" )
    std::cout << "String Literal Test 1 passed\n";
  else
    std::cout << "String Literal Test 1 failed\n";

  if( str2 == "C:\\Temp\\Log.txt\")" )
    std::cout << "String Literal Test 2 passed\n";
  else
    std::cout << "String Literal Test 2 failed\n";
}

// TODO: 09/15/2019
// constexpr - all variations

void test_constructs()
{
  generic_lambda();
  generalized_lambda_capture();
  test_simple_variadic();
  test_string_literal();
}

