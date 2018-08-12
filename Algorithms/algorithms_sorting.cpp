#include "../prototypes.h"

void sort()
{
  std::vector<int> vec1 = { 29, 13, 25, 17, 23, 21, 15, 27, 11 };
  std::sort(vec1.begin(), vec1.end());
  if (vec1[0] == 11 && vec1[8] == 29)
  {
    std::cout << "sort() passed" << std::endl;
  }
  else
  {
    std::cout << "sort() failed" << std::endl;
  }
}

void stable_sort()
{
  std::vector<int> vec1 = { 29, 13, 25, 17, 23, 21, 15, 27, 11 };
  std::sort(vec1.begin(), vec1.end());
  if (vec1[0] == 11 && vec1[8] == 29)
  {
    std::cout << "sort() passed" << std::endl;
  }
  else
  {
    std::cout << "sort() failed" << std::endl;
  }
}

struct flight_info
{
  std::string name;
  int flight_no;
  std::string destination;
};

void partial_sort()
{
  flight_info fi1, fi2, fi3, fi4;

  fi1.name = "Smith";
  fi1.flight_no = 995;
  fi1.destination = "New York";

  fi2.name = "Smith";
  fi2.flight_no = 996;
  fi2.destination = "Chicago";

  fi3.name = "Jones";
  fi3.flight_no = 997;
  fi3.destination = "Boston";

  fi4.name = "Thomas";
  fi4.flight_no = 998;
  fi4.destination = "Newark";

  std::vector<flight_info> fi_vec;
  fi_vec.push_back(fi1);
  fi_vec.push_back(fi2);
  fi_vec.push_back(fi3);
  fi_vec.push_back(fi4);

  std::stable_sort(fi_vec.begin(), fi_vec.end(), [](flight_info const &info1, flight_info const &info2){
    return info1.name < info2.name;
  });

  if (fi_vec[1].flight_no == 995 && fi_vec[2].flight_no == 996 &&
      fi_vec[1].destination == "New York" && fi_vec[2].destination == "Chicago")
  {
    std::cout << "partial_sort() passed" << std::endl;
  }
  else
  {
    std::cout << "partial_sort() failed" << std::endl;
  }
}

void partial_sort_copy()
{
  std::vector<int> vec1 = { 17, 13, 15, 11, 27, 23, 21, 27, 31, 29 };
  std::vector<int> sorted_vec(5);

  std::partial_sort_copy(vec1.begin(), vec1.end(), sorted_vec.begin(), sorted_vec.end());
  if (*sorted_vec.begin() == 11 && *(sorted_vec.begin() + 4) == 21)
  {
    std::cout << "partial_sort_copy() passed" << std::endl;
  }
  else
  {
    std::cout << "partial_sort_copy() failed" << std::endl;
  }
}

void is_sorted()
{
  std::vector<int> vec1 = { 11, 13, 15, 17, 21, 23, 25, 27, 29 };
  std::vector<int> vec2 = { 11, 13, 15, 17, 21, 23, 25, 27, 24 };
  auto status1 = std::is_sorted(vec1.begin(), vec1.end());
  auto status2 = std::is_sorted(vec2.begin(), vec2.end());
  if (status1 && !status2)
  {
    std::cout << "is_sorted() passed" << std::endl;
  }
  else
  {
    std::cout << "is_sorted() failed" << std::endl;
  }
}

void is_sorted_until()
{
  std::vector<int> vec1 = { 11, 13, 15, 17, 21, 23, 25, 27, 24 };
  auto iter = std::is_sorted_until(vec1.begin(), vec1.end());
  if (*iter == 24)
  {
    std::cout << "is_sorted_until() passed" << std::endl;
  }
  else
  {
    std::cout << "is_sorted_until() failed" << std::endl;
  }

}

void nth_element()
{
  std::vector<int> vec1 = { 29, 13, 25, 17, 23, 21, 15, 27, 11, 31 };
  std::nth_element(vec1.begin(), vec1.begin() + 4, vec1.end());
  if (vec1[4] == 21)
  {
    std::cout << "nth_element() passed" << std::endl;
  }
  else
  {
    std::cout << "nth_element() failed" << std::endl;
  }
}

void algorithms_sorting()
{
  sort();
  stable_sort();
  partial_sort();
  partial_sort_copy();
  is_sorted();
  is_sorted_until();
  nth_element();
}