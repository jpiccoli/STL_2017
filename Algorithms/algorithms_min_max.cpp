#include "../prototypes.h"

void min()
{
  auto val = std::min(3, 4);
  if (val == 3)
    std::cout << "min() pass" << std::endl;
  else
    std::cout << "min() fail" << std::endl;
}

void max()
{
  auto val = std::max(3, 4);
  if (val == 4)
    std::cout << "max() pass" << std::endl;
  else
    std::cout << "max() fail" << std::endl;
}

void minmax()
{
  std::pair<int, int> pair1 = std::minmax({ 7, 9, 11, 13, 15, 17, 21 });
  if (pair1.first == 7 && pair1.second == 21)
    std::cout << "minmax() pass" << std::endl;
  else
    std::cout << "minmax() fail" << std::endl;
}

void min_element()
{
  std::vector<int> vec = { 9, 7, 11, 13, 15, 21, 17 };
  auto iter = std::min_element(vec.begin(), vec.end());
  if (*iter == 7)
    std::cout << "min_element() pass" << std::endl;
  else
    std::cout << "min_element() fail" << std::endl;
}

void max_element()
{
  std::vector<int> vec = { 9, 7, 11, 13, 15, 21, 17 };
  auto iter = std::max_element(vec.begin(), vec.end());
  if (*iter == 21)
    std::cout << "min_element() pass" << std::endl;
  else
    std::cout << "min_element() fail" << std::endl;
}

void minmax_element()
{
  std::vector<int> vec = { 9, 7, 11, 13, 15, 21, 17 };
  auto pair = std::minmax_element(vec.begin(), vec.end());
  if (*pair.first == 7 && *pair.second == 21)
    std::cout << "minmax_element() pass" << std::endl;
  else
    std::cout << "minmax_element() fail" << std::endl;

}

void clamp()
{
  auto low = 27;
  auto high = 123;
  auto res1 = std::clamp( 23, low, high );
  if( res1 == 27 )
    std::cout << "std::clamp() for below low passed\n";
  else
    std::cout << "std::clamp() for below low failed\n";

  res1 = std::clamp( 124, low, high );
  if( res1 == 123 )
    std::cout << "std::clamp() for above high passed\n";
  else
    std::cout << "std::clamp() for above high failed\n";

  res1 = std::clamp( 77, low, high );
  if( res1 == 77 )
    std::cout << "std::clamp() for in range value passed\n";
  else
    std::cout << "std::clamp() for in range value failed\n";
}

void lexicographical_compare()
{
  // TODO: 08/12/2018
}

void is_permutation()
{
  std::vector<int> vec1 = { 1, 2, 4, 6, 8 };
  std::vector<int> vec2 = { 2, 1, 4, 8, 6 };
  std::vector<int> vec3 = { 2, 1, 4, 8, 7 };

  auto status1 = std::is_permutation( vec1.begin(), vec1.end(), vec2.begin() );
  auto status2 = std::is_permutation( vec1.begin(), vec1.end(), vec3.begin() );
  if( status1 && !status2 )
  {
    std::cout << "is_permutation() test case passed" << std::endl;
  }
  else
  {
    if( !status1 )
    {
      std::cout << "is_permutation() test case positive failure" << std::endl;
    }
    if( status2 )
    {
      std::cout << "is_permutation() test case negative failure" << std::endl;
    }
  }
}

void next_permutation()
{
  // TODO: 08/12/2018
}

void prev_permutation()
{
  // TODO: 08/12/2018
}

void algorithms_min_max()
{
  min();
  max();
  minmax();
  min_element();
  max_element();
  minmax_element();
  clamp();
  lexicographical_compare();
  is_permutation();
  next_permutation();
  prev_permutation();
}
