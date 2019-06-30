#include "../prototypes.h"

void copy()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };
  std::vector<int> copy_vec(vec.size());

  std::copy(vec.begin() + 3, vec.begin() + 8, copy_vec.begin());

  if ( copy_vec[0] == 17 &&
       copy_vec[1] == 21 &&
       copy_vec[2] == 23 &&
       copy_vec[3] == 25 &&
       copy_vec[4] == 27)
  {
    std::cout << "copy() passed" << std::endl;
  }
  else
  {
    std::cout << "copy() failed" << std::endl;
  }
}

void copy_n()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };
  std::vector<int> copy_vec(7);

  std::copy_n(vec.begin(), 7, copy_vec.begin());

  if (copy_vec[0] == 11 &&
      copy_vec[1] == 13 &&
      copy_vec[2] == 15 &&
      copy_vec[3] == 17 &&
      copy_vec[4] == 21 &&
      copy_vec[5] == 23 &&
      copy_vec[6] == 25)
  {
    std::cout << "copy_n() passed" << std::endl;
  }
  else
  {
    std::cout << "copy_n() failed" << std::endl;
  }
}

void copy_if()
{
  std::vector<int> vec = { 11, 12, 15, 16, 21, 22, 26, 27, 29, 32 };
  std::vector<int> copy_vec(vec.size());

  std::copy_if(vec.begin(), vec.end(), copy_vec.begin(), [](int const &i){ return i % 2 != 0; });

  if ( copy_vec[0] == 11 &&
       copy_vec[1] == 15 &&
       copy_vec[2] == 21 &&
       copy_vec[3] == 27 &&
       copy_vec[4] == 29)
  {
    std::cout << "copy_if() passed" << std::endl;
  }
  else
  {
    std::cout << "copy_if() failed" << std::endl;
  }
}

void copy_backward()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };
  std::vector<int> copy_vec(vec.size());

  std::copy_backward(vec.begin(), vec.begin() + 5, vec.end());

  if (vec[0] == 11 &&
      vec[1] == 13 &&
      vec[2] == 15 &&
      vec[3] == 17 &&
      vec[4] == 21)
  {
    std::cout << "copy_backward() passed" << std::endl;
  }
  else
  {
    std::cout << "copy_backward() failed" << std::endl;
  }
}

void move()
{
  std::vector<int> vec = { 11, 13, 15, 17, 21, 23, 25, 27, 29, 31 };
  std::vector<int> copy_vec(vec.size());

  std::move(vec.begin(), vec.end(), copy_vec.begin());

  if (copy_vec.size() == 10)
  {
    std::cout << "move() passed" << std::endl;
  }
  else
  {
    std::cout << "move() failed" << std::endl;
  }

}

void move_backward()
{
  //int elems[7] = {11, 13, 15, 17, 21 };

  //std::move_backward( elems, elems + 5, elems + 7);

  //elems[0] = 7;
  //elems[1] = 9;

  //if (elems[2] == 11 &&
  //    elems[3] == 13 &&
  //    elems[4] == 15 &&
  //    elems[5] == 17 &&
  //    elems[6] == 21)
  //{
  //  std::cout << "move_backward() passed" << std::endl;
  //}
  //else
  //{
  //  std::cout << "move_backward() failed" << std::endl;
  //}
}

void swap()
{
  std::vector<int> vec1 = { 4, 17 };
  std::vector<int> vec2 = { 6, 18 };

  std::swap(vec1, vec2);

  if (vec1[0] == 6 && vec1[1] == 18 && vec2[0] == 4 && vec2[1] == 17 )
  {
    std::cout << "swap() passed" << std::endl;
  }
  else
  {
    std::cout << "swap() failed" << std::endl;
  }
}

void swap_ranges()
{
  std::vector<int> vec1(6, 11);
  std::vector<int> vec2(6, 33);

  std::swap_ranges(vec1.begin() + 2, vec1.end() - 2, vec2.begin() + 2);
  if (vec1[2] == 33 && vec1[3] == 33 && vec2[2] == 11 && vec2[3] == 11)
  {
    std::cout << "swap_ranges() passed" << std::endl;
  }
  else
  {
    std::cout << "swap_ranges() failed" << std::endl;
  }
}

void iter_swap()
{
  std::vector<int> vec1 = { 4, 6, 8, 11, 17 };
  std::vector<int> vec2 = { 25, 27, 28, 34, 38 };

  std::iter_swap(vec1.begin(), vec2.begin());

  if (vec1[0] == 25 && vec2[0] == 4)
  {
    std::cout << "iter_swap() passed" << std::endl;
  }
  else
  {
    std::cout << "iter_swap() failed" << std::endl;
  }

}

void transform()
{
  std::vector<int> vec1 = { 6, 7, 8, 11, 17 };
  std::vector<int> vec2(vec1.size());

  std::transform(vec1.begin(), vec1.end(), vec2.begin(), [](int const &i){ return i * 2; });

  if (vec2[0] == 12 &&
      vec2[1] == 14 &&
      vec2[2] == 16 &&
      vec2[3] == 22 &&
      vec2[4] == 34)
  {
    std::cout << "transform() passed" << std::endl;
  }
  else
  {
    std::cout << "transform() failed" << std::endl;
  }
}

void replace()
{
  std::vector<int> vec1 = { 6, 11, 8, 11, 13, 11 };

  std::replace(vec1.begin(), vec1.end(), 11, 17);

  if (vec1[1] == 17 &&
      vec1[3] == 17 &&
      vec1[5] == 17)
  {
    std::cout << "replace() passed" << std::endl;
  }
  else
  {
    std::cout << "replace() failed" << std::endl;
  }
}

void replace_if()
{
  std::vector<int> vec1 = { 6, 11, 8, 11, 14, 11 };

  std::replace_if(vec1.begin(), vec1.end(), [](int const &i){ return i % 2 != 0; }, 16);

  if (vec1[1] == 16 &&
      vec1[3] == 16 &&
      vec1[5] == 16)
  {
    std::cout << "replace_if() passed" << std::endl;
  }
  else
  {
    std::cout << "replace_if() failed" << std::endl;
  }
}

void replace_copy()
{
  std::vector<int> vec1 = { 6, 11, 8, 11, 14, 11, 24, 11 };
  std::vector<int> vec2(vec1.size());

  std::replace_copy(vec1.begin(), vec1.end(), vec2.begin(), 11, 78);
  if (vec2[0] == 6 &&
      vec2[1] == 78 &&
      vec2[2] == 8 &&
      vec2[3] == 78 &&
      vec2[4] == 14 &&
      vec2[5] == 78 &&
      vec2[6] == 24 &&
      vec2[7] == 78)
  {
    std::cout << "replace_copy() passed" << std::endl;
  }
  else
  {
    std::cout << "replace_copy() failed" << std::endl;
  }
}

void replace_copy_if()
{
  std::vector<int> vec1 = { 6, 11, 8, 13, 14, 15, 24, 17 };
  std::vector<int> vec2(vec1.size());

  std::replace_copy_if(vec1.begin(), vec1.end(), vec2.begin(), [](int const &i){ return i % 2 != 0; }, 99);
  if (vec2[0] == 6 &&
      vec2[1] == 99 &&
      vec2[2] == 8 &&
      vec2[3] == 99 &&
      vec2[4] == 14 &&
      vec2[5] == 99 &&
      vec2[6] == 24 &&
      vec2[7] == 99)
  {
    std::cout << "replace_copy_if() passed" << std::endl;
  }
  else
  {
    std::cout << "replace_copy_if() failed" << std::endl;
  }
}

void fill()
{
  std::vector<int> vec(8);

  std::fill(vec.begin(), vec.begin() + 4, 17);
  std::fill(vec.begin() + 4, vec.end() - 2, 21);

  if (vec[0] == 17 &&
      vec[1] == 17 &&
      vec[2] == 17 &&
      vec[3] == 17 &&
      vec[4] == 21 &&
      vec[5] == 21 &&
      vec[6] == 0 &&
      vec[7] == 0)
  {
    std::cout << "fill() passed" << std::endl;
  }
  else
  {
    std::cout << "fill() failed" << std::endl;
  }
}

void fill_n()
{
  std::vector<int> vec(8,17);
  std::fill_n(vec.begin() + 4, 2, 21);
  if (vec[0] == 17 &&
      vec[1] == 17 &&
      vec[2] == 17 &&
      vec[3] == 17 &&
      vec[4] == 21 &&
      vec[5] == 21 &&
      vec[6] == 17 &&
      vec[7] == 17)
  {
    std::cout << "fill_n() passed" << std::endl;
  }
  else
  {
    std::cout << "fill_n() failed" << std::endl;
  }
}

struct c_unique {
  int current;
  c_unique() { current = 26; }
  int operator()() { return ++current; }
} UniqueNumber;

void generate()
{
  std::vector<int> vec(5);

  std::generate(vec.begin(), vec.end(), UniqueNumber);

  if(vec[0] == 27 && vec[4] == 31)
  {
    std::cout << "generate() passed" << std::endl;
  }
  else
  {
    std::cout << "generate() failed" << std::endl;
  }
}

void generate_n()
{
  std::vector<int> vec(7);

  std::generate_n(vec.begin(), 5, UniqueNumber);

  if (vec[0] == 27 && vec[4] == 31 && vec[5] == 0 && vec[6] == 0)
  {
    std::cout << "generate_n() passed" << std::endl;
  }
  else
  {
    std::cout << "generate_n() failed" << std::endl;
  }
}

void remove()
{
  std::vector<int> vec = { 6, 11, 8, 11, 14, 11, 24, 11 };

  std::vector<int>::iterator iter_result = std::remove(vec.begin(), vec.end(), 11);

  std::cout << "remove(): ";
  for (auto itr = vec.begin(); itr != iter_result; ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void remove_if()
{
  std::vector<int> vec = { 9, 12, 13, 14, 15, 16, 17, 18 };

  std::vector<int>::iterator iter_result = std::remove_if(vec.begin(), vec.end(), [](int const& i){return ((i % 2) == 0); });
  std::cout << "remove_if(): ";
  for (auto itr = vec.begin(); itr != iter_result; ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void remove_copy()
{
  std::vector<int> vec = { 7, 11, 9, 11, 13, 11, 27, 11 };
  std::vector<int> result(8);

  std::vector<int>::iterator iter_result = std::remove_copy(vec.begin(), vec.end(), result.begin(), 11);
  std::cout << "remove_copy(): ";
  for (auto itr = result.begin(); itr != result.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void remove_copy_if()
{
  std::vector<int> vec = { 7, 8, 11, 12, 17, 18, 20, 21 };
  std::vector<int> result(8);

  std::vector<int>::iterator iter_result = std::remove_copy_if(vec.begin(), vec.end(), result.begin(), [](int const& i){return ((i % 2) == 0); });
  std::cout << "remove_copy_if(): ";
  for (auto itr = result.begin(); itr != result.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void unique()
{
  std::vector<int> vec = { 6, 7, 7, 8, 9, 9, 9, 11, 12, 12, 12 };

  auto itr = std::unique(vec.begin(), vec.end());
  vec.resize(std::distance(vec.begin(), itr));
  //std::cout << "unique(): ";
  //for (auto itr = vec.begin(); itr != vec.end(); ++itr)
  //{
  //  std::cout << *itr << " ";
  //}

  if( vec.size() == 6 )
  {
    std::cout << "unique() #1 passed\n";
  }
  else
  {
    std::cout << "unique() #1 failed\n";
  }

  if( vec[0] == 6 && vec[1] == 7 && vec[2] == 8 && vec[3] == 9 && vec[4] == 11 && vec[5] == 12 )
  {
    std::cout << "unique() #2 passed\n";
  }
  else
  {
    std::cout << "unique() #2 failed\n";
  }

  std::cout << std::endl;
}

void unique_copy()
{
  std::vector<int> vec = { 6, 7, 7, 8, 9, 9, 9, 11, 12, 12, 12, 14 };
  std::vector<int> result(12);

  auto itr = std::unique_copy(vec.begin(), vec.end(), result.begin());
  result.resize(std::distance(result.begin(), itr));
  std::cout << "unique_copy(): ";
  for (auto itr = result.begin(); itr != result.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void reverse()
{
  std::vector<int> vec = { 1, 3, 5, 7, 9 };
  std::vector<int> vec1 = { 1, 3, 5, 7, 9 };
  std::string test = "abcdefg";
  std::string output;

  std::reverse(vec.begin(), vec.end());
  std::cout << "reverse(): ";
  for (auto itr = vec.begin(); itr != vec.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void reverse_copy()
{
  std::vector<int> vec = { 1, 3, 5, 7, 9 };
  std::vector<int> result(vec.size());

  std::reverse_copy(vec.begin(), vec.end(), result.begin());
  std::cout << "reverse_copy(): ";
  for (auto itr = result.begin(); itr != result.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void rotate()
{
  std::vector<int> vec = { 21, 23, 25, 27, 29, 31, 33 };

  std::rotate(vec.begin(), vec.begin() + 3, vec.end());
  std::cout << "rotate(): ";
  for (auto itr = vec.begin(); itr != vec.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;

}

void rotate_copy()
{
  std::vector<int> vec = { 21, 23, 25, 27, 29, 31, 33 };
  std::vector<int> result(vec.size());

  std::rotate_copy(vec.begin(), vec.begin() + 4, vec.end(), result.begin());
  std::cout << "rotate_copy(): ";
  for (auto itr = result.begin(); itr != result.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

// Deprecated in C++17
//void random_shuffle()
//{
//  std::vector<int> vec = { 21, 23, 25, 27, 29, 31, 33 };
//  std::random_shuffle(vec.begin(), vec.end());
//  std::cout << "random_shuffle(): ";
//  for (auto itr = vec.begin(); itr != vec.end(); ++itr)
//  {
//    std::cout << *itr << " ";
//  }
//  std::cout << std::endl;
//}

void shuffle()
{
  std::vector<int> vec = { 21, 23, 25, 27, 29, 31, 33 };
  std::shuffle(vec.begin(), vec.end(), std::default_random_engine(762));
  std::cout << "shuffle(): ";
  for (auto itr = vec.begin(); itr != vec.end(); ++itr)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}

void sample()
{
  std::vector<int> v1{ 3, 5, 7, 9, 11, 15, 17 };
  std::vector<int> v2;
  std::sample( v1.begin(), v1.end(), std::back_inserter( v2 ), 2, std::mt19937{ std::random_device{}() } );
  std::cout << "std::sample() output = ";
  for( auto val : v2 )
    std::cout << val << ", ";

  std::cout << '\n';
}

void algorithms_modifying()
{
  copy();
  copy_n();
  copy_if();
  copy_backward();
  move();
  move_backward();
  swap();
  swap_ranges();
  iter_swap();
  transform();
  replace();
  replace_if();
  replace_copy();
  replace_copy_if();
  fill();
  fill_n();
  generate();
  generate_n();
  remove();
  remove_if();
  remove_copy();
  remove_copy_if();
  unique();
  unique_copy();
  reverse();
  reverse_copy();
  rotate();
  rotate_copy();
  // random_shuffle(); - Deprecated in C++17
  shuffle();
  sample();
}