#include "../prototypes.h"

#include <tuple>
#include <string>

void std_tuple()
{
  // std::tie
  int test_int = 7;
  int result_int;
  std::string test_string( "test_string" );
  std::string result_string;
  std::tie( result_int, result_string ) = std::make_tuple( 27, "another_string" );
  if( result_int == 27 && result_string == "another_string" )
    std::cout << "std::tie() passed\n\n";
  else
    std::cout << "std::tie() failed\n\n";
}
