#include "../Tests.h"

void composite_type_categories_test()
{
  bool status;

  std::cout << "Running composite type categories test...\n";

  // is_fundamental - arithmetic, void, std::null_ptr_t
  typedef std::void_t<int> void_type_t;
  status = std::is_fundamental<void_type_t>::value;
  if( !status )
    std::cout << "std::is_fundamental 1 error\n";

  typedef std::nullptr_t null_pointer;
  status = std::is_fundamental<null_pointer>::value;
  if( !status )
    std::cout << "std::is_fundamental 2 error\n";

  typedef float DDD;
  status = std::is_fundamental<DDD>::value;
  if( !status )
    std::cout << "std::is_fundamental 3 error\n";

  // is_arithmetic - integral, fundamental
  typedef int FFF;
  typedef double GGG;
  status = std::is_arithmetic<FFF>::value;
  if( !status )
    std::cout << "std::is_arithmetic 1 error\n";
  status = std::is_arithmetic<GGG>::value;
  if( !status )
    std::cout << "std::is_arithmetic 2 error\n";

  // is_scalar - arithmetic, pointer, pointer to member, enumeration, std::null_ptr_t
  status = std::is_scalar<DDD>::value;
  if( !status )
    std::cout << "std::is_scalar 1 error\n";

  status = std::is_scalar<null_pointer>::value;
  if( !status )
    std::cout << "std::is_scalar 2 error\n";

  typedef int* int_ptr;
  status = std::is_scalar<int_ptr>::value;
  if( !status )
    std::cout << "std::is_scalar 3 error\n";

  enum class E { E1, E2 };
  status = std::is_scalar<E>::value;
  if( !status )
    std::cout << "std::is_scalar 4 error\n";

  // is_object
  struct JJJ {};
  status = std::is_object<JJJ>::value;
  if( !status )
    std::cout << "std::is_object error\n";

  // is_compound - array, function, object pointer, function pointer, member object pointer, member function pointer, reference, class, union, or enumeration
  typedef std::array<int, 11> arr_int;
  typedef std::function<void()> empty_function_t;
  typedef std::function<void()> *empty_function_ptr_t;
  struct WWW {};
  typedef WWW* struct_ptr_t;
  typedef int& XXX;
  union ZZZ {
    int a;
    double b;
  };

  status = std::is_compound<arr_int>::value;
  if( !status )
    std::cout << "std::is_compound 1 error\n";

  status = std::is_compound<empty_function_t>::value;
  if( !status )
    std::cout << "std::is_compound 2 error\n";

  status = std::is_compound<struct_ptr_t>::value;
  if( !status )
    std::cout << "std::is_compound 3 error\n";

  status = std::is_compound<empty_function_ptr_t>::value;
  if( !status )
    std::cout << "std::is_compound 4 error\n";

  status = std::is_compound<XXX>::value;
  if( !status )
    std::cout << "std::is_compound 7 error\n";

  status = std::is_compound<WWW>::value;
  if( !status )
    std::cout << "std::is_compound 8 error\n";

  status = std::is_compound<ZZZ>::value;
  if( !status )
    std::cout << "std::is_compound 9 error\n";

  status = std::is_compound<E>::value;
  if( !status )
    std::cout << "std::is_compound 10 error\n";

  // is_reference
  status = std::is_reference<XXX>::value;
  if( !status )
    std::cout << "std::is_reference error\n";

  // is_member_pointer
  struct AAA { int a; void f() {} };
  //status = std::is_member_object_pointer<int(AAA::*)>::value; <= Also works
  status = std::is_member_pointer<decltype(&AAA::a)>::value;
  if( !status )
    std::cout << "std::is_member_pointer 1 error\n";

  status = std::is_member_pointer<decltype(&AAA::f)>::value;
  if( !status )
    std::cout << "std::is_member_pointer 2 error\n";

}
