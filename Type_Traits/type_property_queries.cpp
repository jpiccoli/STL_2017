#include "../Tests.h"

void type_property_queries_test()
{
  std::cout << "Running type property queries test...\n";

  // alignment_of
  auto bool_align = std::alignment_of<bool>::value;
  auto int_align = std::alignment_of<int>::value;
  auto double_align = std::alignment_of<double>::value;
  if( bool_align != 1 || int_align != 4 || double_align != 8 )
    std::cout << "alignment_of error\n";

  // rank
  typedef int array_4d[ 9 ][ 11 ][ 15 ][ 17 ];
  auto rank = std::rank<array_4d>::value;
  if( rank != 4 )
    std::cout << "rank error\n";

  // extent
  auto extent = std::extent<array_4d, 3>::value;
  if( extent != 17 )
    std::cout << "extent error\n";

}
