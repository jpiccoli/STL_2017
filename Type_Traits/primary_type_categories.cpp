#include "../Tests.h"

void f() {}

void primary_type_categories_test()
{
  bool status;

  std::cout << "Running primary type categories test...\n";

  // is_void
  typedef std::void_t<int> void_type_t;
  status = std::is_void<void_type_t>::value;
  if( !status )
    std::cout << "std::is_void error\n";

  // is_null_pointer
  typedef std::nullptr_t null_pointer;
  status = std::is_null_pointer<null_pointer>::value;
  if( !status )
    std::cout << "std::is_null_pointer error\n";

  // is_integral
  struct ZAB {
    virtual void f() {}
    int a; private: int b;
  };
  status = std::is_integral<ZAB>::value;
  if( status )
    std::cout << "is_integral error\n";

  // is_floating_point
  typedef double dbl_test;
  status = std::is_null_pointer<null_pointer>::value;
  if( !status )
    std::cout << "std::is_null_pointer error\n";

  // is_array
  typedef std::array<int, 11> arr_int;
  status = std::is_null_pointer<null_pointer>::value;
  if( !status )
    std::cout << "std::is_null_pointer error\n";

  // is_enum
  enum class E { E1, E2 };
  status = std::is_null_pointer<null_pointer>::value;
  if( !status )
    std::cout << "std::is_null_pointer error\n";

  // is_union
  union ZZZ {
    int a;
    double b;
  };
  status = std::is_union<ZZZ>::value;
  if( !status )
    std::cout << "std::is_union error\n";

  // is_class
  struct YYY {};
  status = std::is_class<YYY>::value;
  if( !status )
    std::cout << "std::is_class error\n";

  // is_function
  //typedef std::function<void()> function_t;
  //status = std::is_function<int(int)>::value; <= doesn't work
  status = std::is_function<decltype(f)>::value;
  if( !status )
    std::cout << "std::is_function error\n";

  // is_pointer
  typedef YYY* struct_ptr_t;
  status = std::is_pointer<struct_ptr_t>::value;
  if( !status )
    std::cout << "std::is_pointer error\n";

  // is_lvalue_reference
  typedef int& LLL;
  status = std::is_lvalue_reference<LLL>::value;
  if( !status )
    std::cout << "std::is_lvalue_reference error\n";

  // is_rvalue_reference
  typedef int&& RRR;
  status = std::is_rvalue_reference<RRR>::value;
  if( !status )
    std::cout << "std::is_rvalue_reference error\n";

  // is_member_object_pointer
  struct AAA { int a; void f() {} };
  //status = std::is_member_object_pointer<int(AAA::*)>::value; <= Also works
  status = std::is_member_object_pointer<decltype(&AAA::a)>::value;
  if( !status )
    std::cout << "std::is_member_object_pointer error\n";

  // is_member_function_pointer
  status = std::is_member_function_pointer<decltype(&AAA::f)>::value;
  if( !status )
    std::cout << "std::is_member_function_pointer error\n";

}
