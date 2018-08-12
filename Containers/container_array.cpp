#include "../prototypes.h"

void container_array()
{
  std::array<int, 15> arr = { 21, 22, 23, 24, 25, 26, 27, 28, 29 };

  if (arr.size() == 15)
    std::cout << "array size() pass" << std::endl;
  else
    std::cout << "array size() fail" << std::endl;

  if (arr.max_size() == 15)
    std::cout << "array max_size() pass" << std::endl;
  else
    std::cout << "array max_size() fail" << std::endl;

  if (!arr.empty())
    std::cout << "array empty() pass" << std::endl;
  else
    std::cout << "array empty() fail" << std::endl;

  std::array<int, 5> arr1 = { 21, 22, 23, 24, 25 };
  std::array<int, 5> arr2 = { 31, 32, 33, 34, 35 };

  arr1.swap(arr2);
  if (arr1[0] == 31 && arr1[1] == 32 && arr1[2] == 33 && arr1[3] == 34 && arr1[4] == 35)
    std::cout << "array swap() pass" << std::endl;
  else
    std::cout << "array swap() fail" << std::endl;

  std::array<int, 5> arr3;
  arr3.fill(11);
  if (arr3[0] == 11 && arr3[1] == 11 && arr3[2] == 11 && arr3[3] == 11 && arr3[4] == 11)
    std::cout << "array fill() pass" << std::endl;
  else
    std::cout << "array fill() fail" << std::endl;

  if( arr.at(6) == 27)
    std::cout << "array at() pass" << std::endl;
  else
    std::cout << "array at() fail" << std::endl;

  if (arr.front() == 21)
    std::cout << "array front() pass" << std::endl;
  else
    std::cout << "array front() fail" << std::endl;

  if (arr.back() == 0)
    std::cout << "array back() pass" << std::endl;
  else
    std::cout << "array back() fail" << std::endl;
}