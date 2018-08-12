#include "../prototypes.h"

#include <string>
#include <bitset>

void std_bitset()
{
  std::bitset<8> bit_vector;

  if (bit_vector.size() == 8)
  {
    std::cout << "bitset size() passed" << std::endl;
  }
  else
  {
    std::cout << "bitset size() failed" << std::endl;
  }

  if (!bit_vector.any())
  {
    std::cout << "bitset any() #1 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset any() #1 failed" << std::endl;
  }

  if (bit_vector.none())
  {
    std::cout << "bitset none() #1 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset none() #1 failed" << std::endl;
  }
  
  bit_vector[0] = 1;

  if (bit_vector.any())
  {
    std::cout << "bitset any() #2 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset any() #2 failed" << std::endl;
  }

  bit_vector[1] = 1;

  if (bit_vector.count() == 2)
  {
    std::cout << "bitset count() #1 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset count() #1 failed" << std::endl;
  }

  if (!bit_vector.all())
  {
    std::cout << "bitset all() #1 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset all() #1 failed" << std::endl;
  }

  if (!bit_vector.test(0) == 1)
  {
    std::cout << "bitset test() #1 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset test() #1 failed" << std::endl;
  }

  if (!bit_vector.test(2) == 0)
  {
    std::cout << "bitset test() #2 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset test() #2 failed" << std::endl;
  }

  bit_vector[2] = 1;
  bit_vector[3] = 1;
  bit_vector[4] = 1;
  bit_vector[5] = 1;
  bit_vector[6] = 1;
  bit_vector[7] = 1;

  if (bit_vector.all())
  {
    std::cout << "bitset all() #2 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset all() #2 failed" << std::endl;
  }

  if (!bit_vector.none())
  {
    std::cout << "bitset none() #2 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset none() #2 failed" << std::endl;
  }

  bit_vector[2] = 0;
  bit_vector[3] = 0;
  bit_vector[4] = 0;
  bit_vector[5] = 0;
  bit_vector[6] = 0;
  bit_vector[7] = 0;

  bit_vector.set(2);

  if (bit_vector.count() == 3)
  {
    std::cout << "bitset count() #2 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset count() #2 failed" << std::endl;
  }

  bit_vector.reset(2);

  if (bit_vector.test(2) == 0)
  {
    std::cout << "bitset test() #3 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset count() #3 failed" << std::endl;
  }

  bit_vector.set(2);
  bit_vector.flip(2);
  bit_vector.flip(3);
  bit_vector.flip(4);

  if (bit_vector.test(2) == 0 && bit_vector.test(3) == 1 && bit_vector.test(4) == 1)
  {
    std::cout << "bitset test() #4 passed" << std::endl;
  }
  else
  {
    std::cout << "bitset count() #4 failed" << std::endl;
  }

  if (bit_vector.to_string() == "00011011")
  {
    std::cout << "bitset to_string() passed" << std::endl;
  }
  else
  {
    std::cout << "bitset to_string() failed" << std::endl;
  }
}
