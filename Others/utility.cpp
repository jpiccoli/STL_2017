#include "../prototypes.h"

#include <utility>
#include <tuple>

void std_utility()
{
	std::vector<int> v1{ 1, 2, 3, 4 }, v2{ 5, 6, 7, 8 };

	std::swap( v1, v2 );

	if ( v1[ 0 ] == 5 && v1[ 1 ] == 6 && v1[ 2 ] == 7 && v1[ 3 ] == 8 )
		std::cout << "std::swap passed." << std::endl;
	else
		std::cout << "std::swap failed." << std::endl;

	std::pair<int, int> pair1( 27, 29 );
	std::pair<int, int> pair2 = std::make_pair( 31, 34 );

	if( pair1.first == 27 && pair1.second == 29 && pair2.first == 31 && pair2.second == 34 )
		std::cout << "std::pair passed." << std::endl;
	else
		std::cout << "std::pair failed." << std::endl;

  auto original = 27;
  auto replace = std::exchange( original, 29 );
  if( replace == 27 )
    std::cout << "std::exchange #1 passed\n";
  else
    std::cout << "std::exchange #1 failed\n";

  if( original == 29 )
    std::cout << "std::exchange #2 passed\n";
  else
    std::cout << "std::exchange #2 failed\n";

  // TODO: 08/12/2018
  // any
  // variant
  // tuple
  // forward
  // move
  // declval
  // as_const
  // to_chars
  // from_chars
  // chars_format
}
