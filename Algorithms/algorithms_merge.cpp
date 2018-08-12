#include "../prototypes.h"

void merge()
{
  std::vector<int> vec1 = { 3, 7, 9, 5, 11, 15, 13 };
  std::vector<int> vec2 = { 6, 2, 4, 8, 12, 16, 14 };
  std::vector<int> vec3(vec1.size() + vec2.size());

  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());

  std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

  if (vec3[0] = 2 && vec3[13] == 16)
    std::cout << "merge() passed" << std::endl;
  else
    std::cout << "merge() failed" << std::endl;
}

void inplace_merge()
{
  std::vector<int> vec1 = { 3, 7, 9, 5, 11, 15, 13 };
  std::vector<int> vec2 = { 6, 2, 4, 8, 12, 16, 14 };
  std::vector<int> vec3(vec1.size() + vec2.size());

  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());

  std::vector<int>::iterator it = std::copy(vec1.begin(), vec1.end(), vec3.begin());
  std::copy(vec2.begin(), vec2.end(), it);

  std::inplace_merge(vec3.begin(), vec3.begin() + 7, vec3.end());

  if (vec3[0] = 2 && vec3[13] == 16)
    std::cout << "inplace_merge() passed" << std::endl;
  else
    std::cout << "inplace_merge() failed" << std::endl;
}

void includes()
{
  std::vector<int> container1 = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
  std::vector<int> container2 = { 5, 10, 15, 20, 25, 30, 35, 41, 45, 50 };
  std::vector<int> container3 = { 40, 30, 20, 10 };

  std::sort(container1.begin(), container1.end());
  std::sort(container2.begin(), container2.end());
  std::sort(container3.begin(), container3.end());

  auto status1 = std::includes(container1.begin(), container1.end(), container3.begin(), container3.end());
  auto status2 = std::includes(container2.begin(), container2.end(), container3.begin(), container3.end());

  if (status1 && !status2)
    std::cout << "includes() passed" << std::endl;
  else
    std::cout << "includes() failed" << std::endl;
}

void set_union()
{
  std::vector<int> container1 = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
  std::vector<int> container2 = { 5, 10, 15, 21, 27, 31, 35, 41, 45, 50 };
  std::vector<int> result(20);

  std::set_union(container1.begin(), container1.end(), container2.begin(), container2.end(), result.begin());
  if (result[0] == 5 &&
      result[1] == 10 &&
      result[2] == 15 &&
      result[3] == 20 &&
      result[4] == 21 &&
      result[5] == 25 &&
      result[6] == 27 &&
      result[7] == 30 &&
      result[8] == 31 &&
      result[9] == 35 &&
      result[10] == 40 &&
      result[11] == 41 &&
      result[12] == 45 &&
      result[13] == 50
    )
  {
    std::cout << "set_union() passed" << std::endl;
  }
  else
  {
    std::cout << "set_union() failed" << std::endl;
  }
}

void set_intersection()
{
  std::vector<int> container1 = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
  std::vector<int> container2 = { 5, 10, 15, 21, 27, 31, 35, 41, 45, 50 };
  std::vector<int> result(20);

  std::set_intersection(container1.begin(), container1.end(), container2.begin(), container2.end(), result.begin());
  if (result[0] == 5 &&
      result[1] == 10 &&
      result[2] == 15 &&
      result[3] == 35 &&
      result[4] == 45 &&
      result[5] == 50
    )
  {
    std::cout << "set_intersection() passed" << std::endl;
  }
  else
  {
    std::cout << "set_intersection() failed" << std::endl;
  }
}

void set_difference()
{
  std::vector<int> container1 = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 52 };
  std::vector<int> container2 = { 5, 10, 15, 21, 27, 31, 35, 41, 45, 50 };
  std::vector<int> result(20);

  std::set_difference(container1.begin(), container1.end(), container2.begin(), container2.end(), result.begin());
  if (result[0] == 20 &&
      result[1] == 25 &&
      result[2] == 30 &&
      result[3] == 40 &&
      result[4] == 52
    )
  {
    std::cout << "set_difference() passed" << std::endl;
  }
  else
  {
    std::cout << "set_difference() failed" << std::endl;
  }
}

void set_symmetric_difference()
{
  std::vector<int> container1 = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 52 };
  std::vector<int> container2 = { 5, 10, 15, 21, 27, 31, 35, 41, 45, 50 };
  std::vector<int> result(20);

  std::set_symmetric_difference(container1.begin(), container1.end(), container2.begin(), container2.end(), result.begin());
  if (result[0] == 20 &&
      result[1] == 21 &&
      result[2] == 25 &&
      result[3] == 27 &&
      result[4] == 30 &&
      result[5] == 31 &&
      result[6] == 40 &&
      result[7] == 41 &&
      result[8] == 52
    )
  {
    std::cout << "set_symmetric_difference() passed" << std::endl;
  }
  else
  {
    std::cout << "set_symmetric_difference() failed" << std::endl;
  }
}

void algorithms_merge()
{
  merge();
  inplace_merge();
  includes();
  set_union();
  set_intersection();
  set_difference();
  set_symmetric_difference();
}