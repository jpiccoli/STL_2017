#include "../prototypes.h"

void all_of()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, -9 };

  bool status1 = std::all_of(vec1.begin(), vec1.end(), [](int const& i){ return i > 0; });
  bool status2 = std::all_of(vec2.begin(), vec2.end(), [](int const& i){ return i > 0; });

  if (status1 == true && status2 == false)
  {
    std::cout << "all_of() test case passed" << std::endl;
  }
  else
  {
    if (status1 == false)
    {
      std::cout << "all_of positive case failure" << std::endl;
    }

    if (status2 == true)
    {
      std::cout << "all_of negative case failure" << std::endl;
    }
  }
}

void any_of()
{
  std::vector<int> vec1 = { 1, -2, -3, -4, -5, -6, -7, -8, -9 };
  std::vector<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  bool status1 = std::any_of(vec1.begin(), vec1.end(), [](int const& i){ return i > 0; });
  bool status2 = std::any_of(vec2.begin(), vec2.end(), [](int const& i){ return i < 0; });

  if (status1 == true && status2 == false)
  {
    std::cout << "any_of() test case passed" << std::endl;
  }
  else
  {
    if (status1 == false)
    {
      std::cout << "any_of positive case failure" << std::endl;
    }

    if (status2 == true)
    {
      std::cout << "any_of negative case failure" << std::endl;
    }
  }
}

void none_of()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, -9 };

  bool status1 = std::none_of(vec1.begin(), vec1.end(), [](int const& i){ return i < 0; });
  bool status2 = std::none_of(vec2.begin(), vec2.end(), [](int const& i){ return i < 0; });

  if (status1 == true && status2 == false)
  {
    std::cout << "none_of() test case passed" << std::endl;
  }
  else
  {
    if (status1 == true)
    {
      std::cout << "none_of positive case failure" << std::endl;
    }

    if (status2 == false)
    {
      std::cout << "none_of negative case failure" << std::endl;
    }
  }
}

void for_each()
{
  std::vector<int> vec = { 9, 11, 14 };

  std::cout << "for_each() test: ";
  std::for_each(vec.begin(), vec.end(), [](int const &i){ std::cout << i * 2 << " "; });
  std::cout << std::endl;
}

void for_each_n()
{
  std::vector<int> v1{ 3, 5, 7, 9, 11, 15, 17 };
  std::for_each_n( v1.begin(), 4, [] ( auto& n ) { n = n * n; } );
  if( v1[ 0 ] != 9 || v1[ 1 ] != 25 || v1[ 2 ] != 49 || v1[ 3 ] != 81 ||
    v1[ 4 ] != 11 || v1[ 5 ] != 15 || v1[ 6 ] != 17 )
    std::cout << "std::for_each_n failure\n";
  else
    std::cout << "std::for_each_n success\n";
}

void find()
{
  std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto iter1 = std::find(vec.begin(), vec.end(), 7);
  auto iter2 = std::find(vec.begin(), vec.end(), 17);
  if (iter1 != vec.end() && iter2 == vec.end())
  {
    std::cout << "find() test case passed" << std::endl;
  }
  else
  {
    if (iter1 == vec.end())
    {
      std::cout << "find() positive case failure" << std::endl;
    }
    if (iter2 != vec.end())
    {
      std::cout << "find() negative case failure" << std::endl;
    }
  }
}

void find_if()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, -9 };
  std::vector<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto iter1 = std::find_if(vec1.begin(), vec1.end(), [](int const& i){ return i < 0; });
  auto iter2 = std::find_if(vec2.begin(), vec2.end(), [](int const& i){ return i < 0; });
  if (iter1 != vec1.end() && iter2 == vec2.end())
  {
    std::cout << "find_if() test case passed" << std::endl;
  }
  else
  {
    if (iter1 == vec1.end())
    {
      std::cout << "find_if() positive case failure" << std::endl;
    }
    if (iter2 != vec2.end())
    {
      std::cout << "find_if() negative case failure" << std::endl;
    }
  }
}

void find_if_not()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, -9 };
  std::vector<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto iter1 = std::find_if_not(vec1.begin(), vec1.end(), [](int const& i){ return i > 0; });
  auto iter2 = std::find_if_not(vec2.begin(), vec2.end(), [](int const& i){ return i > 0; });
  if (iter1 != vec1.end() && iter2 == vec2.end())
  {
    std::cout << "find_if_not() test case passed" << std::endl;
  }
  else
  {
    if (iter1 == vec1.end())
    {
      std::cout << "find_if_not() positive case failure" << std::endl;
    }
    if (iter2 != vec2.end())
    {
      std::cout << "find_if_not() negative case failure" << std::endl;
    }
  }
}

void find_end()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 1, 2, 3 };
  std::vector<int> vec2 = { 4, 5, 6, 7, 8, 9 };
  std::vector<int> vec3 = { 1, 2, 3 };

  auto iter1 = std::find_end(vec1.begin(), vec1.end(), vec3.begin(), vec3.end());
  auto iter2 = std::find_end(vec2.begin(), vec2.end(), vec3.begin(), vec3.end());
  if (iter1 != vec1.end() && iter2 == vec2.end())
  {
    auto pos = iter1 - vec1.begin();
    if (pos == 6)
      std::cout << "find_end() test case passed" << std::endl;
  }
  else
  {
    if (iter1 == vec1.end())
    {
      std::cout << "find_end() positive case failure" << std::endl;
    }
    if (iter2 != vec2.end())
    {
      std::cout << "find_end() negative case failure" << std::endl;
    }
  }
}

void find_first_of()
{
  std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6 };
  std::vector<int> vec2 = { 4, 5, 6, 7, 8, 9 };
  std::vector<int> vec3 = { 1, 2, 3 };

  auto iter1 = std::find_first_of(vec1.begin(), vec1.end(), vec3.begin(), vec3.end());
  auto iter2 = std::find_first_of(vec2.begin(), vec2.end(), vec3.begin(), vec3.end());
  if (iter1 != vec1.end() && iter2 == vec2.end())
  {
    std::cout << "find_first_of() test case passed" << std::endl;
  }
  else
  {
    if (iter1 == vec1.end())
    {
      std::cout << "find_first_of() positive case failure" << std::endl;
    }
    if (iter2 != vec2.end())
    {
      std::cout << "find_first_of() negative case failure" << std::endl;
    }
  }

}

void adjacent_find()
{
  std::vector<int> vec1 = { 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  std::vector<int> vec2 = { 4, 5, 6, 7, 8, 9 };

  auto iter1 = std::adjacent_find(vec1.begin(), vec1.end());
  auto iter2 = std::adjacent_find(vec2.begin(), vec2.end());
  if (iter1 != vec1.end() && iter2 == vec2.end())
  {
    if ( *iter1 == 2 )
      std::cout << "adjacent_find() test case passed" << std::endl;
  }
  else
  {
    if (iter1 == vec1.end())
    {
      std::cout << "adjacent_find() positive case failure" << std::endl;
    }
    if (iter2 != vec2.end())
    {
      std::cout << "adjacent_find() negative case failure" << std::endl;
    }
  }
}

void count()
{
  std::vector<int> vec1 = { 1, 2, 3, 2, 4, 2, 5, 2, 6, 2 };

  auto cnt = std::count(vec1.begin(), vec1.end(), 2);
  if (cnt = 5)
  {
    std::cout << "count() test case passed" << std::endl;
  }
  else
  {
    std::cout << "count() test case failed" << std::endl;
  }
}

void count_if()
{
  std::vector<int> vec1 = { 1, 2, 4, 6, 8, 11, 12, 14 };

  auto cnt = std::count_if(vec1.begin(), vec1.end(), [](int const & i){ return i % 2 == 0; });
  if (cnt = 6)
  {
    std::cout << "count_if() test case passed" << std::endl;
  }
  else
  {
    std::cout << "count_if() test case failed" << std::endl;
  }
}

void mismatch()
{
  std::vector<int> vec1 = { 1, 2, 4, 6, 8, 11, 12, 14 };
  std::vector<int> vec2 = { 1, 2, 4, 7, 8, 11, 12, 14 };

  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair = std::mismatch(vec1.begin(), vec1.end(), vec2.begin());
  if (*pair.first == 6 && *pair.second == 7)
  {
    std::cout << "mismatch() test case passed" << std::endl;
  }
  else
  {
    std::cout << "mismatch() test case failed" << std::endl;
  }
}

void equal()
{
  std::vector<int> vec1 = { 1, 2, 4, 6, 8, 11, 12, 14 };
  std::vector<int> vec2 = { 1, 2, 4, 6, 8, 11, 12, 14 };
  std::vector<int> vec3 = { 1, 2, 4, 7, 8, 11, 12, 15 };

  auto status1 = std::equal(vec1.begin(), vec1.end(), vec2.begin());
  auto status2 = std::equal(vec1.begin(), vec1.end(), vec3.begin());
  if (status1 && !status2)
  {
    std::cout << "equal() test case passed" << std::endl;
  }
  else
  {
    if (!status1)
    {
      std::cout << "equal() test case positive failure" << std::endl;
    }
    if (status2)
    {
      std::cout << "equal() test case negative failure" << std::endl;
    }
  }
}

void search()
{
  std::vector<int> vec1 = { 1, 2, 4, 6, 8 };
  std::vector<int> vec2 = { 1, 2, 4 };
  std::vector<int> vec3 = { 1, 2, 6 };

  std::vector<int>::iterator iter1 = std::search(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
  std::vector<int>::iterator iter2 = std::search(vec1.begin(), vec1.end(), vec3.begin(), vec3.end());
  if ((iter1 != vec1.end() && *iter1 == 1) && (iter2 == vec1.end()))
  {
    std::cout << "search() test case passed" << std::endl;
  }
  else
  {
    std::cout << "search() test case failure" << std::endl;
  }
}

void search_n()
{
  std::vector<int> vec1 = { 11, 11, 11, 22, 33, 11, 44 };

  auto iter1 = std::search_n(vec1.begin(), vec1.end(), 3, 11);
  auto iter2 = std::search_n(vec1.begin(), vec1.end(), 4, 11);
  if (iter1 != vec1.end() && iter2 == vec1.end())
  {
    std::cout << "search_n() test case passed" << std::endl;
  }
  else
  {
    std::cout << "search_n() test case failure" << std::endl;
  }
}

void algorithms_not_modifying()
{
  all_of();
  any_of();
  none_of();
  for_each();
  for_each_n();
  count();
  count_if();
  mismatch();
  equal();
  find();
  find_if();
  find_if_not();
  find_end();
  find_first_of();
  adjacent_find();
  search();
  search_n();
}
