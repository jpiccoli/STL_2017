#include "../Tests.h"

#include <type_traits>

void integral_constant_test()
{
  // Base class for type traits

  std::cout << "Running integral constant test...\n";

  // Helpers
  const unsigned int1 = 7, int2 = 18;
  static_assert(std::true_type::value == (int1 == int1), "7 != 7");
  static_assert(std::false_type::value == (int1 == int2), "7 == 18");

  // User created implementations
  typedef std::integral_constant<int, 27> two_seven_t;
  typedef std::integral_constant<int, 29> two_nine_t;
  typedef std::integral_constant<int, 31> three_one_t;
  typedef std::integral_constant<int, 37> three_seven_t;

  static_assert(two_seven_t::value + 2 == two_nine_t::value, "27+2 != 29");
  static_assert(three_one_t::value + 6 == three_seven_t::value, "31+6 != 37");

  std::cout << '\n';
}
