#include "../prototypes.h"

#include <initializer_list>

void std_initializer_list()
{
  std::vector < int > test_vec {7, 17, 27};

  if (test_vec.size() == 3)
    std::cout << "std_initializer_list #1 passed." << std::endl;
  else
    std::cout << "std_initializer_list #1 failed." << std::endl;

  if(test_vec[0] == 7 && test_vec[1] == 17 && test_vec[2] == 27)
    std::cout << "std_initializer_list #2 passed." << std::endl;
  else
    std::cout << "std_initializer_list #2 failed." << std::endl;
}
