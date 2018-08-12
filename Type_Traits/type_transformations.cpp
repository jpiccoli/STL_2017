#include "../Tests.h"

void type_transformations_test()
{
  std::cout << "Running type transformations test...\n";

  // decay - lvalue used as rvalue and cv qualifier removed
  typedef int& R;
  typedef int&& S;
  typedef const int U;
  typedef volatile int V;

  typedef std::decay<R>::type W;
  typedef std::decay<S>::type X;
  typedef std::decay<U>::type Y;
  typedef std::decay<V>::type Z;

  auto dec1 = std::is_same<W, int>::value;
  auto dec2 = std::is_same<X, int>::value;
  auto dec3 = std::is_same<Y, int>::value;
  auto dec4 = std::is_same<Z, int>::value;
  if( !dec1 || !dec2 || !dec3 || !dec4 )
    std::cout << "std::decay error\n";

  // conditional
  typedef int first_type;
  typedef double second_type;
  typedef std::conditional<true, first_type, second_type>::type result1;
  typedef std::conditional<false, first_type, second_type>::type result2;
  auto status1 = std::is_same<result1, int>::value;
  auto status2 = std::is_same<result2, double>::value;
  if( !status1 || !status2 )
    std::cout << "std::conditional error 1\n";
  auto str1 = typeid(result1).name();
  auto str2 = typeid(result2).name();
  if( str1 != "int" )
    std::cout << "std::conditional error 2\n";
  if( str2 != "double" )
    std::cout << "std::conditional error 3\n";

  // common_type
  struct A { int a; };
  struct B : public A { int b; };
  typedef std::common_type<A, B>::type Common;
  auto str_common = typeid(Common).name();
  auto status = std::is_same<A, Common>::value;
  if( !status )
    std::cout << "std::common_type error\n";

  // underlying_type
  enum class e1 { E1 };
  enum class e2 : unsigned { E2 };
  auto str3 = typeid(std::underlying_type<e1>::type).name();
  auto str4 = typeid(std::underlying_type<e2>::type).name();
  if( str3 != std::string( "int" ) || str4 != std::string( "unsigned int" ) )
    std::cout << "std::underlying_type error\n";

}
