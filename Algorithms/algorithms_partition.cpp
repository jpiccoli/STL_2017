#include "../prototypes.h"

void is_partitioned()
{
  std::vector<int> vec1 = { 1, 7, 3, 9, 2, 8, 4, 6 };
  std::vector<int> vec2 = { 1, 12, 3, 9, 2, 8, 4, 6 };
  auto status1 = std::is_partitioned(vec1.begin(), vec1.end(), [](int const &i){ return i % 2 == 1; });
  auto status2 = std::is_partitioned(vec2.begin(), vec2.end(), [](int const &i){ return i % 2 == 1; });
  if (status1 && !status2)
    std::cout << "is_partitioned() pass" << std::endl;
  else
    std::cout << "is_partitioned() fail" << std::endl;
}

void partition()
{
  std::vector<int> vec1 = { 1, 4, 7, 6, 9, 2, 3, 8, 5 };
  auto iter = std::partition(vec1.begin(), vec1.end(), [](int const &i){ return i % 2 == 1; });
  if (*iter == 4 || *iter == 6 || *iter == 2 || *iter == 8)
    std::cout << "partition() pass" << std::endl;
  else
    std::cout << "partition() fail" << std::endl;
}

void stable_partition()
{
  std::vector<int> vec1 = { 1, 4, 7, 6, 9, 2, 3, 8, 5 };
  auto iter = std::stable_partition(vec1.begin(), vec1.end(), [](int const &i){ return i % 2 == 1; });
  if (vec1[0] == 1 && *iter == 4)
    std::cout << "stable_partition() pass" << std::endl;
  else
    std::cout << "stable_partition() fail" << std::endl;
}

bool IsOdd(int i)
{
  return i % 2 == 1;
}

void partition_copy()
{
  std::vector<int> vec1 = { 1, 4, 7, 6, 9, 2, 3, 8, 5 };
  std::vector<int> odd, even;

  unsigned n = std::count_if(vec1.begin(), vec1.end(), IsOdd);
  odd.resize(n); even.resize(vec1.size() - n);

  std::partition_copy(vec1.begin(), vec1.end(), odd.begin(), even.begin(), /*[](int &i){ return i % 2 == 1; }*/IsOdd);
  if (odd[0] == 1 && even[0] == 4)
    std::cout << "partition_copy() pass" << std::endl;
  else
    std::cout << "partition_copy() fail" << std::endl;
}

void partition_point()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  std::stable_partition(vec1.begin(), vec1.end(), [](int const &i){ return i % 2 == 1; });

  auto iter = std::partition_point(vec1.begin(), vec1.end(), [](int const &i){ return i % 2 == 1; });

  if (*iter == 2)
    std::cout << "partition_point() pass" << std::endl;
  else
    std::cout << "partition_point() fail" << std::endl;
}

void algorithms_partition()
{
  is_partitioned();
  partition();
  stable_partition();
  partition_copy();
  partition_point();
}