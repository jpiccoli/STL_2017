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
}
