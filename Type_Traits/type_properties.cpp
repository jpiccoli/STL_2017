#include "../Tests.h"

void type_properties_test()
{
  bool status;

  std::cout << "Running type properties test...\n";

  // is_const
  typedef const int ci;
  status = std::is_const<ci>::value;
  if( !status )
    std::cout << "std::is_const #1 error\n";

  typedef int nci;
  status = std::is_const<nci>::value;
  if( status )
    std::cout << "std::is_const #2 error\n";

  // is_volatile
  typedef volatile int vi;
  status = std::is_volatile<vi>::value;
  if( !status )
    std::cout << "std::is_volatile error\n";

  // is_trivial
  struct ZAB { virtual void f() {} int i;  private: int j; };
  struct ZAC { int i; };
  status = std::is_trivial<ZAB>::value;
  if( status )
    std::cout << "is_trivial error 1\n";

  status = std::is_trivial<ZAC>::value;
  if( !status )
    std::cout << "is_trivial error 2\n";

  // is_trivially_copyable
  status = std::is_trivially_copyable<ZAB>::value;
  if( status )
    std::cout << "is_trivially_copyable error\n";

  // is_standard_layout
  status = std::is_standard_layout<ZAB>::value;
  if( status )
    std::cout << "is_standard_layout error\n";

  // is_pod
  struct ZYX { int i;  private: int j; };
  typedef char special_char;
  status = std::is_pod<ZYX>::value;
  if( status )
    std::cout << "is_pod error 1\n";

  status = std::is_pod<special_char>::value;
  if( !status )
    std::cout << "is_pod error 2\n";

  status = std::is_pod<ci>::value;
  if( !status )
    std::cout << "is_pod error 3\n";

  // is_empty
  struct VVV {};
  status = std::is_empty<VVV>::value;
  if( !status )
    std::cout << "std::is_empty error\n";

  // is_polymorphic - class must declare or inherit one or more virtual functions
  struct WWW { virtual void func() {} };
  status = std::is_polymorphic<WWW>::value;
  if( !status )
    std::cout << "std::is_polymorphic 1 error\n";

  struct XXX : public WWW {};
  status = std::is_polymorphic<XXX>::value;
  if( !status )
    std::cout << "std::is_polymorphic 2 error\n";

  // is_abstract
  struct YYY {
    virtual void f() = 0;
  };
  status = std::is_abstract<YYY>::value;
  if( !status )
    std::cout << "std::is_abstract error\n";

  // is_final
  struct ZZZ final {};
  status = std::is_final<ZZZ>::value;
  if( !status )
    std::cout << "std::is_final error\n";

  // is_aggregate
  // Not supported by compiler - 12/09/2017

  // is_signed
  typedef int signed_test;
  status = std::is_signed<signed_test>::value;
  if( !status )
    std::cout << "std::is_signed error\n";

  // is_unsigned
  typedef unsigned int unsigned_test;
  status = std::is_unsigned<unsigned_test>::value;
  if( !status )
    std::cout << "std::is_unsigned error\n";

}
