#include "../prototypes.h"

bool is_even(unsigned int const& i) {
  return (i % 2 == 0);
}

void container_forward_list()
{
  std::forward_list<unsigned int> f_list1, f_list2;

  std::vector<unsigned int> scratchpad;

  // assign
  f_list1.assign({ 66, 67, 68, 69, 70 });

  unsigned int size = 0;
  for (auto const& item : f_list1)
    size++;

  if (size == 5)
    std::cout << "forward_list assign() pass" << std::endl;
  else
    std::cout << "forward_list assign() fail" << std::endl;

  // emplace_front
  f_list1.emplace_front(65);
  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if(scratchpad[0] == 65)
    std::cout << "forward_list emplace_front() pass" << std::endl;
  else
    std::cout << "forward_list emplace_front() fail" << std::endl;

  // push_front
  scratchpad.clear();
  f_list1.clear();
  f_list1.assign({ 66, 67, 68, 69, 70 });
  f_list1.push_front(64);
  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if (scratchpad[0] == 64)
    std::cout << "forward_list push_front() pass" << std::endl;
  else
    std::cout << "forward_list push_front() fail" << std::endl;

  // pop_front
  scratchpad.clear();
  f_list1.pop_front();

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if (scratchpad[0] == 66)
    std::cout << "forward_list pop_front() pass" << std::endl;
  else
    std::cout << "forward_list pop_front() fail" << std::endl;

  // emplace_after
  scratchpad.clear();
  auto itr = f_list1.before_begin();
  f_list1.emplace_after(itr, 63);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if (scratchpad[0] == 63)
    std::cout << "forward_list emplace_after() pass" << std::endl;
  else
    std::cout << "forward_list emplace_after() fail" << std::endl;

  // insert_after
  scratchpad.clear();
  f_list1.clear();
  f_list1.assign({ 66, 67, 68, 69, 70 });
  itr = f_list1.before_begin();
  f_list1.insert_after(itr, 63);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if (scratchpad[0] == 63)
    std::cout << "forward_list insert_after() pass" << std::endl;
  else
    std::cout << "forward_list insert_after() fail" << std::endl;

  // erase_after
  scratchpad.clear();
  itr = f_list1.before_begin();
  f_list1.erase_after(itr);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if (scratchpad[0] == 66)
    std::cout << "forward_list erase_after() pass" << std::endl;
  else
    std::cout << "forward_list erase_after() fail" << std::endl;

  // swap
  scratchpad.clear();
  f_list2.assign({ 60, 61, 62, 63, 64 });
  f_list1.swap(f_list2);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 60) && (scratchpad[4] == 64))
    std::cout << "forward_list swap() pass" << std::endl;
  else
    std::cout << "forward_list swap() fail" << std::endl;

  // resize - shrink
  scratchpad.clear();
  f_list1.resize(4);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 60) && (scratchpad[3] == 63))
    std::cout << "forward_list resize() #1 pass" << std::endl;
  else
    std::cout << "forward_list resize() #1 fail" << std::endl;

  // resize - grow
  scratchpad.clear();
  f_list1.resize(5, 65);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 60) && (scratchpad[4] == 65))
    std::cout << "forward_list resize() #2 pass" << std::endl;
  else
    std::cout << "forward_list resize() #2 fail" << std::endl;

  // clear
  scratchpad.clear();
  f_list1.clear();

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if (scratchpad.empty())
    std::cout << "forward_list clear() pass" << std::endl;
  else
    std::cout << "forward_list clear() fail" << std::endl;

  // splice_after
  scratchpad.clear();
  f_list1.assign({ 66, 67, 68, 69, 70 });
  f_list2.assign({ 60, 61, 62, 63, 64 });

  itr = f_list1.before_begin();
  f_list1.splice_after(itr, f_list2);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 60) && (scratchpad[9] == 70))
    std::cout << "forward_list splice_after() pass" << std::endl;
  else
    std::cout << "forward_list splice_after() fail" << std::endl;

  // remove
  scratchpad.clear();
  f_list1.assign({ 66, 67, 68, 69, 70 });
  f_list1.remove(66);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 67) && (scratchpad[3] == 70))
    std::cout << "forward_list remove() pass" << std::endl;
  else
    std::cout << "forward_list remove() fail" << std::endl;

  // remove_if
  scratchpad.clear();
  f_list1.assign({ 66, 67, 68, 69, 70, 71 });
  f_list1.remove_if(is_even);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 67) && (scratchpad[2] == 71))
    std::cout << "forward_list remove_if() pass" << std::endl;
  else
    std::cout << "forward_list remove_if() fail" << std::endl;

  // unique
  scratchpad.clear();
  f_list1.assign({ 66, 67, 68, 69, 70, 71, 71, 72, 72, 73, 74 });
  f_list1.unique();

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 66) && (scratchpad[8] == 74))
    std::cout << "forward_list unique() pass" << std::endl;
  else
    std::cout << "forward_list unique() fail" << std::endl;

  // merge
  scratchpad.clear();
  f_list1.assign({ 60, 62, 64, 66, 68 });
  f_list2.assign({ 61, 63, 65, 67, 69 });
  f_list1.merge(f_list2);

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 60) && (scratchpad[9] == 69))
    std::cout << "forward_list merge() pass" << std::endl;
  else
    std::cout << "forward_list merge() fail" << std::endl;

  // sort
  scratchpad.clear();
  f_list1.assign({ 60, 62, 64, 66, 68, 61, 63, 65, 67, 69 });
  f_list1.sort();

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 60) && (scratchpad[9] == 69))
    std::cout << "forward_list sort() pass" << std::endl;
  else
    std::cout << "forward_list sort() fail" << std::endl;

  // reverse
  scratchpad.clear();
  f_list1.assign({ 66, 67, 68, 69, 70 });
  f_list1.reverse();

  for (auto const& item : f_list1)
    scratchpad.push_back(item);

  if ((scratchpad[0] == 70) && (scratchpad[4] == 66))
    std::cout << "forward_list reverse() pass" << std::endl;
  else
    std::cout << "forward_list reverse() fail" << std::endl;
}