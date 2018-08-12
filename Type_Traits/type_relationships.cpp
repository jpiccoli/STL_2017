#include "../Tests.h"

void type_relationships_test()
{
  bool status;

  std::cout << "Running type relationships test...\n";

  // is_same
  struct same1 {};
  typedef same1 same2;
  status = std::is_same<same1, same2>::value;
  if( !status )
    std::cout << "std::is_same error\n";

  // is_base_of
  struct Base {};
  struct Derived : Base {};
  status = std::is_base_of<Base, Derived>::value;
  if( !status )
    std::cout << "std::is_base_of error\n";

  // is_convertible
  status = std::is_convertible<Derived, Base>::value;
  if( !status )
    std::cout << "std::is_convertible error\n";
}
