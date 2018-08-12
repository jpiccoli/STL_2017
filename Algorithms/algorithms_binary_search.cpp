#include "../prototypes.h"

void lower_bound()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };

  auto iter = std::lower_bound(vec.begin(), vec.end(), 22);
  if (*iter == 23)
  {
    std::cout << "lower_bound() passed" << std::endl;
  }
  else
  {
    std::cout << "lower_bound() failed" << std::endl;
  }
}

void upper_bound()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };

  auto iter = std::upper_bound(vec.begin(), vec.end(), 23);
  if (*iter == 25)
  {
    std::cout << "upper_bound() passed" << std::endl;
  }
  else
  {
    std::cout << "upper_bound() failed" << std::endl;
  }
}

void equal_range()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };

  auto pair = std::equal_range(vec.begin(), vec.end(), 23);
  if (*pair.first == 23 && *pair.second == 25)
  {
    std::cout << "equal_range() passed" << std::endl;
  }
  else
  {
    std::cout << "equal_range() failed" << std::endl;
  }
}

void binary_search()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };

  auto status1 = std::binary_search(vec.begin(), vec.end(), 23);
  auto status2 = std::binary_search(vec.begin(), vec.end(), 24);
  if (status1 && !status2)
  {
    std::cout << "binary_search() passed" << std::endl;
  }
  else
  {
    std::cout << "binary_search() failed" << std::endl;
  }
}

void algorithms_binary_search()
{
  lower_bound();
  upper_bound();
  equal_range();
  binary_search();
}