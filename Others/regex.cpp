#include "../prototypes.h"

#include <regex>

void std_regex()
{
  std::string s = "cartoons are carried by cardboard cutout cardrivers.";
  std::smatch m;
  std::regex e1("(car)(.*)");
  std::regex e2("(car)([^ ]*)");

  if (std::regex_match(s, m, e1))
    std::cout << "std::regex #1 passed." << std::endl;
  else
    std::cout << "std::regex #1 failed." << std::endl;

  while (std::regex_search(s, m, e2))
  {
    for (auto x : m)
    {
      std::cout << x << " ";
    }

    std::cout << std::endl;
    s = m.suffix().str();
  }
}
