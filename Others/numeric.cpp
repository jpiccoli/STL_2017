#include "../prototypes.h"

#include <chrono>
#include <numeric>

void accumulate()
{
  // Notes:
  // 1. Default: Add each value and add total to "init"
  // 2. Other: Perform operation on each value combined with "init"

  std::vector<int> vec1{ 12, 22, 33, 44 };

  // Default
  auto result = std::accumulate(vec1.begin(), vec1.end(), 0);
  if (result == 111)
    std::cout << "accumulate #1 passed." << std::endl;
  else
    std::cout << "accumulate #1 failed." << std::endl;

  // Standard function
  result = std::accumulate(vec1.begin(), vec1.end(), 100, std::minus<int>());
  if (result == -11)
    std::cout << "accumulate #2 passed." << std::endl;
  else
    std::cout << "accumulate #2 failed." << std::endl;

  // Custom function
  auto op = [](int x, int y) -> int { return x + 2 * y; };

  result = std::accumulate(vec1.begin(), vec1.end(), 100, op);
  if (result == 322)
    std::cout << "accumulate #3 passed." << std::endl;
  else
    std::cout << "accumulate #3 failed." << std::endl;
}

void adjacent_difference()
{
  std::vector<int> vec = { 5, 7, 11, 14, 20 };
  std::vector<int> result;
  result.resize(5);

  // Default
  std::adjacent_difference(vec.begin(), vec.end(), result.begin());
  if (result[0] == 5 && result[1] == 2 && result[2] == 4 && result[3] == 3 && result[4] == 6)
    std::cout << "adjacent_difference #1 passed." << std::endl;
  else
    std::cout << "adjacent_difference #1 failed." << std::endl;

  result.clear();
  result.resize(5);

  // Standard function
  auto func = std::multiplies<int>();
  std::adjacent_difference(vec.begin(), vec.end(), result.begin(), std::multiplies<int>());
  if (result[0] == 5 && result[1] == 35 && result[2] == 77 && result[3] == 154 && result[4] == 280)
    std::cout << "adjacent_difference #2 passed." << std::endl;
  else
    std::cout << "adjacent_difference #2 failed." << std::endl;

  // Custom function
  auto const my_op = [](int x, int y)->int { return x + y + 2; };
  std::adjacent_difference(vec.begin(), vec.end(), result.begin(), my_op);
  if (result[0] == 5 && result[1] == 14 && result[2] == 20 && result[3] == 27 && result[4] == 36)
    std::cout << "adjacent_difference #3 passed." << std::endl;
  else
    std::cout << "adjacent_difference #3 failed." << std::endl;
}

void inner_product()
{
  // Notes:
  // 1. Standard: first do multiplication; next do addition.
  // 2. Functional operations: first do second operation, next do first operation
  //    with result of second operation and "init" value. Result is new "init".
  std::vector<int> vec1 = { 5, 7, 11 };
  std::vector<int> vec2 = { 6, 8, 12 };
  std::vector<int> vec3 = { 30, 42, 56 };
  std::vector<int> vec4 = { 6, 7, 8 };
  std::vector<int> vec5 = { 4, 5, 6 };
  std::vector<int> vec6 = { 3, 4, 5 };
  int result;
  int init = 0;

  // Default
  result = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), init);
  if(result == 218)
    std::cout << "inner_product #1 passed." << std::endl;
  else
    std::cout << "inner_product #1 failed." << std::endl;

  // Functional operations
  result = std::inner_product(vec3.begin(), vec3.end(), vec4.begin(), 100, std::minus<int>(), std::divides<int>());
  if (result == 82)
    std::cout << "inner_product #2 passed." << std::endl;
  else
    std::cout << "inner_product #2 failed." << std::endl;

  // Custom operations
  auto op1 = [](int x, int y)->int { return x - y; };
  auto op2 = [](int x, int y)->int { return x + y; };

  result = std::inner_product(vec5.begin(), vec5.end(), vec6.begin(), 100, op1, op2);
  if (result == 73)
    std::cout << "inner_product #3 passed." << std::endl;
  else
    std::cout << "inner_product #3 failed." << std::endl;
}

void iota()
{
  std::vector<int> result;
  result.resize(5);

  std::iota(result.begin(), result.end(), 23);
  if (result[0] == 23 && result[1] == 24 && result[2] == 25 && result[3] == 26 && result[4] == 27)
    std::cout << "iota passed." << std::endl;
  else
    std::cout << "iota failed." << std::endl;
}

// NOTE: Used to generate factorial results
void partial_sum()
{
  std::vector<int> vec = { 1, 2, 3, 4, 5 };
  std::vector<int> result;
  result.resize(5);

  // Default
  std::partial_sum( vec.begin(), vec.end(), result.begin() );
  if( result[0] == 1 && result[1] == 3 && result[2] == 6 && result[3] == 10 && result[4] == 15 )
    std::cout << "partial_sum #1 passed." << std::endl;
  else
    std::cout << "partial_sum #1 failed." << std::endl;

  result.clear();
  result.resize(5);

  // Standard function
  auto func = std::multiplies<int>();
  std::partial_sum( vec.begin(), vec.end(), result.begin(), std::multiplies<int>() );
  if ( result[0] == 1 && result[1] == 2 && result[2] == 6 && result[3] == 24 && result[4] == 120 )
    std::cout << "partial_sum #2 passed." << std::endl;
  else
    std::cout << "partial_sum #2 failed." << std::endl;

  result.clear();
  result.resize(5);

  // Custom function
  typedef std::function<int(int, int)> custom_op;
  custom_op const my_op = [](int x, int y)->int { return x + y + 2; };
  std::partial_sum( vec.begin(), vec.end(), result.begin(), my_op );
  if (result[0] == 1 && result[1] == 5 && result[2] == 10 && result[3] == 16 && result[4] == 23)
    std::cout << "partial_sum #3 passed." << std::endl;
  else
    std::cout << "partial_sum #3 failed." << std::endl;
}

void gcd()
{
  auto gcd_value = std::gcd( 42, 70 );
  if( gcd_value == 14 )
    std::cout << "std::gcd() passed\n\n";
  else
    std::cout << "std::gcd() failed\n\n";
}

void lcm()
{
  auto lcm_value = std::lcm( 6, 15 );
  if( lcm_value == 30 )
    std::cout << "std::lcm() passed\n\n";
  else
    std::cout << "std::lcm() failed\n\n";
}

void reduce()
{
  // std::reduce -> compare with std::accumulate
  std::vector<double> v( 100'000, 0.5 );
  auto t1a = std::chrono::high_resolution_clock::now();
  double result1 = std::accumulate( v.begin(), v.end(), 11.0 );
  auto t2a = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms1 = t2a - t1a;
  std::cout << std::fixed << "std::accumulate = " << result1 << " took " << ms1.count() << " ms\n";

  auto t1r = std::chrono::high_resolution_clock::now();
  double result2 = std::reduce(/*std::execution::par,*/ v.begin(), v.end(), 11.0 );
  auto t2r = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms2 = t2r - t1r;
  std::cout << std::fixed << "std::reduce = " << result2 << " took " << ms2.count() << " ms\n\n";
}

void transform_reduce()
{
  // TODO: 08/12/2018
}

void inclusive_scan()
{
  std::vector<int> scan_input{ 7, 14, 21, 30, 36, 42, 50, 56, 63 };
  std::vector<int> scan_output;

  auto inclusive_it = std::inclusive_scan( scan_input.begin() + 2, scan_input.end() - 2, std::back_inserter( scan_output ) );
  if( scan_output.size() == 5 )
  {
    std::cout << "inclusive_output() #1 passed\n";
    if( scan_output[ 0 ] == 21 && scan_output[ 1 ] == 51 && scan_output[ 2 ] == 87 && scan_output[ 3 ] == 129 && scan_output[ 4 ] == 179 )
      std::cout << "inclusive_output() #2 passed\n";
    else
      std::cout << "inclusive_output() #2 passed\n";
  }
  else
    std::cout << "inclusive_output() #1 failed\n";
}

void exclusive_scan()
{
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
}

void transform_exclusive_scan()
{
  // TODO: 08/12/2018
}

void std_numeric()
{
  accumulate();
  adjacent_difference();
  inner_product();
  iota();
  partial_sum();
  reduce();
  transform_reduce();
  inclusive_scan();
  exclusive_scan();
  transform_exclusive_scan();
}
