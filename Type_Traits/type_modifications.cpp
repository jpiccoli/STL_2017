#include "../Tests.h"

void type_modifications_test()
{
  bool status;

  std::cout << "Running type modifications test...\n";

  // remove_cv
  typedef const volatile int cv_all;
  typedef std::remove_cv<cv_all>::type cv_none;
  status = std::is_same<int, cv_none>::value;
  if( !status )
    std::cout << "remove_cv error\n";

  // remove_const
  typedef const int int_const;
  typedef std::remove_const<int_const>::type int_no_const;
  status = std::is_same<int, int_no_const>::value;
  if( !status )
    std::cout << "remove_const error\n";

  // remove_volatile
  typedef int volatile int_volatile;
  typedef std::remove_volatile<int_volatile>::type int_no_volatile;
  status = std::is_same<int, int_no_volatile>::value;
  if( !status )
    std::cout << "remove_volatile error\n";

  // add_cv
  typedef std::add_cv<int>::type cv_add;
  status = std::is_same<cv_add, cv_all>::value;
  if( !status )
    std::cout << "add_cv error\n";

  // add_const
  typedef std::add_const<int>::type const_add;
  status = std::is_same<const_add, int_const>::value;
  if( !status )
    std::cout << "add_const error\n";

  // add_volatile
  typedef std::add_volatile<int>::type add_volatile;
  status = std::is_same<add_volatile, int_volatile>::value;
  if( !status )
    std::cout << "add_volatile error\n";

  // remove_reference
  typedef int& int_lvalue_reference;
  typedef int&& int_rvalue_reference;
  typedef std::remove_reference<int_lvalue_reference>::type no_lvalue_ref;
  status = std::is_same<no_lvalue_ref, int>::value;
  if( !status )
    std::cout << "remove_reference error 1\n";
  typedef std::remove_reference<int_rvalue_reference>::type no_rvalue_ref;
  status = std::is_same<no_rvalue_ref, int>::value;
  if( !status )
    std::cout << "remove_reference error 2\n";

  // add_lvalue_reference
  typedef std::add_lvalue_reference<int>::type add_lvalue_ref;
  status = std::is_same<add_lvalue_ref, int_lvalue_reference>::value;
  if( !status )
    std::cout << "add_lvalue_reference error\n";

  // add_rvalue_reference
  typedef std::add_rvalue_reference<int>::type add_rvalue_ref;
  status = std::is_same<add_rvalue_ref, int_rvalue_reference>::value;
  if( !status )
    std::cout << "add_lvalue_reference error\n";

  // remove_pointer
  typedef int* int_ptr;
  typedef std::remove_pointer<int_ptr>::type int_no_ptr;
  status = std::is_same<int_no_ptr, int>::value;
  if( !status )
    std::cout << "remove_pointer error\n";

  // add_pointer
  typedef std::add_pointer<int>::type int_add_ptr;
  status = std::is_same<int_ptr, int_add_ptr>::value;
  if( !status )
    std::cout << "add_pointer error\n";

  typedef unsigned int unsigned_int;
  typedef signed int signed_int;

  // make_signed
  typedef std::make_signed<unsigned_int>::type signed_int_t;
  status = std::is_same<signed_int_t, signed_int>::value;
  if( !status )
    std::cout << "make_signed error\n";

  // make_unsigned
  typedef std::make_unsigned<signed_int>::type unsigned_int_t;
  status = std::is_same<unsigned_int_t, unsigned_int>::value;
  if( !status )
    std::cout << "make_signed error\n";

  // remove_extent
  typedef int arr1[ 12 ][ 14 ];
  typedef int arr2[ 14 ];
  typedef std::remove_extent<arr1>::type removed_arr1;
  status = std::is_same<removed_arr1, arr2>::value;
  if( !status )
    std::cout << "remove_extents error\n";

  // remove_all_extents
  typedef std::remove_all_extents<arr1>::type all_removed;
  status = std::is_same<all_removed, int>::value;
  if( !status )
    std::cout << "remove_all_extents error\n";

}
