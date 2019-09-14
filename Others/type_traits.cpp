#include "../prototypes.h"
#include "../Tests.h"

#include <type_traits>

struct field1 {};
struct field2 {};
struct field3 {};
struct field4 {};

struct record_def1 {};

template<typename field_type, typename enable = void>
struct field_value
{
  template<typename record>
  static void describe( record & )
  {
    std::cout << "Type name original = " << typeid(record).name() << "\n";
  }
};

template<typename field_type >
struct field_value<typename field_type, typename std::enable_if< std::is_same< field_type, field4 >::value >::type >
{
  template<typename record>
  static void describe( record & )
  {
    std::cout << "Type name specialization = " << typeid(record).name() << "\n";
  }
};

template <typename T, typename = void>
struct is_compute_available : std::false_type {};

template <typename T>
struct is_compute_available<T,
  std::void_t<decltype( Compute( std::declval<T>(),
    std::declval<T&>() ) ) >> : std::true_type {};

template< class T>
inline constexpr bool is_compute_available_v = is_compute_available<T>::value;

void Compute( int, int& ) { std::cout << "Computing int\n"; }
void Compute( double, double& ) { std::cout << "Computing double\n"; }

template <typename T>
void ComputeTest( T val )
{
  if constexpr ( is_compute_available_v<T> )    // Note different syntax
  {
    T out{};
    Compute( val, out );
  }
  else
  {
    std::cout << "fallback...\n";
  }
}

void std_type_traits()
{
  // Check std::enable_if and std::is_same
  record_def1 record1;

  field_value<field1>::describe( record1 );
  field_value<field2>::describe( record1 );
  field_value<field3>::describe( record1 );
  field_value<field4>::describe( record1 );

  // Done: 12/09/2017
  primary_type_categories_test();
  composite_type_categories_test();
  type_properties_test();
  type_property_queries_test();
  type_relationships_test();
  type_modifications_test();
  type_transformations_test();

  // Compiler does not support constructs
  type_operations_test();

  integral_constant_test();

  int int_result = 0;
  int double_result = 0;

  ComputeTest<int>( 7 );        // Prints "Computing int"
  ComputeTest<double>( 8.0 );   // Prints "Computing double"
  ComputeTest<float>( 8.0f );   // Prints "fallback..."
}

// Reference: http://coliru.stacked-crooked.com/a/dff6ff04ab058c29
/*
#include <iostream>
#include <type_traits>

void Compute(int, int&) { std::cout << "Computing int\n"; }
void Compute(double, double&) { std::cout << "Computing double\n"; }

template <typename T, typename = void>
struct is_compute_available : std::false_type {};
template <typename T>
struct is_compute_available<T, std::void_t<decltype(Compute(std::declval<T>(), std::declval<T&>())) >> : std::true_type {};

// helper variable template
template< class T> inline constexpr bool is_compute_available_v = is_compute_available<T>::value;

template <typename T>
void ComputeTest(T val)
{
if constexpr (is_compute_available_v<T>)
{
T out { };
Compute(val, out);
}
else
{
std:: cout << "fallback...\n";
}
}

int main(int argc, const char** argv) {

ComputeTest<int>(10);
ComputeTest<double>(10.5);
ComputeTest<float>(10.5f);

return 0;
}
*/