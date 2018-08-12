#include "../prototypes.h"

void heap_process()
{
  std::vector<int> vec = { 11, 21, 31, 5, 15 };

  if (!std::is_heap(vec.begin(), vec.end()))
  {
    std::make_heap(vec.begin(), vec.end());
    if (std::is_heap(vec.begin(), vec.end()))
    {
      std::cout << "make_heap() and is_heap() passed" << std::endl;
    }
  }

  std::pop_heap(vec.begin(), vec.end());
  if (vec.front() == 21)
  {
    std::cout << "pop_heap() passed" << std::endl;
  }
  else
  {
    std::cout << "pop_heap() failed" << std::endl;
  }

  vec.push_back(99);
  std::make_heap(vec.begin(), vec.end());
  std::push_heap(vec.begin(), vec.end());
  if (vec.front() == 99)
  {
    std::cout << "push_heap() passed" << std::endl;
  }
  else
  {
    std::cout << "push_heap() failed" << std::endl;
  }

  std::vector<int> vec4 = { 27, 26, 29, 25, 24, 22 };
  //std::make_heap(vec4.begin(), vec4.end());
  //vec4.push_back(29);
  auto iter = std::is_heap_until(vec4.begin(), vec4.end());
  auto count = iter - vec4.begin();
  if (count == 2)
  {
    std::cout << "is_heap_until() passed" << std::endl;
  }
  else
  {
    std::cout << "is_heap_until() failed" << std::endl;
  }

  std::make_heap(vec4.begin(), vec4.end());
  std::sort_heap(vec4.begin(), vec4.end());
  if (vec4[0] == 22 && vec4[5] == 29)
    std::cout << "sort_heap() passed" << std::endl;
  else
    std::cout << "sort_heap() failed" << std::endl;
}

void algorithms_heap()
{
  heap_process();
}