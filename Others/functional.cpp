#include "../prototypes.h"

#include <string>
#include <functional>

void std_bind()
{
  using namespace std::placeholders;    // adds visibility of _1, _2, _3,...

  typedef std::function<int(int, int)> division;
  division const division_func = [](int x, int y)->int { return x / y; };

  auto divide1 = std::bind(division_func, 27, 3);
  auto result1 = divide1();
  if (result1 == 9)
    std::cout << "std_bind #1 passed." << std::endl;
  else
    std::cout << "std_bind #1 failed." << std::endl;

  auto divide2 = std::bind(division_func, _1, 3);
  auto result2 = divide2(27);
  if (result2 == 9)
    std::cout << "std_bind #2 passed." << std::endl;
  else
    std::cout << "std_bind #2 failed." << std::endl;

  auto divide3 = std::bind(division_func, 27, _1);
  auto result3 = divide3(3);
  if (result3 == 9)
    std::cout << "std_bind #3 passed." << std::endl;
  else
    std::cout << "std_bind #3 failed." << std::endl;

  auto divide4 = std::bind(division_func, _1, _2);
  auto result4 = divide4(27, 3);
  if (result4 == 9)
    std::cout << "std_bind #4 passed." << std::endl;
  else
    std::cout << "std_bind #4 failed." << std::endl;

  auto divide5 = std::bind(division_func, _2, _1);
  auto result5 = divide5(3, 27);
  if (result5 == 9)
    std::cout << "std_bind #5 passed." << std::endl;
  else
    std::cout << "std_bind #5 failed." << std::endl;

}

void std_cref()
{
  auto var = 26;
  auto ref_var = std::cref(var);
  var++;

  if (ref_var == 27)
    std::cout << "std_cref passed." << std::endl;
  else
    std::cout << "std_cref failed." << std::endl;
}

void std_mem_fn()
{
  struct int_holder {
    int value;
    int triple() { return value * 3; }
  };

  int_holder ih {9};  // Initializes "value" = 9

  auto triple_func = std::mem_fn(&int_holder::triple);
  auto result = triple_func(ih);
  if (result == 27)
    std::cout << "std_mem_fn passed." << std::endl;
  else
    std::cout << "std_mem_fn failed." << std::endl;
}

void std_invoke()
{
  // TODO: 08/12/2018
}

// Deprecated in C++17
//void std_not1()
//{
//  typedef std::function<bool(int)> is_odd;
//  is_odd const odd_func = [](int x)->bool{ return ( x % 2 ) == 1; };
//  auto even_func = std::not1(odd_func);
//  auto result = even_func(7);
//  if(!result)
//    std::cout << "std_not1 #1 passed." << std::endl;
//  else
//    std::cout << "std_not1 #1 failed." << std::endl;
//
//  result = even_func(8);
//  if (result)
//    std::cout << "std_not1 #2 passed." << std::endl;
//  else
//    std::cout << "std_not1 #2 failed." << std::endl;
//}

// Deprecated in C++17
//void std_not2()
//{
//  typedef std::function<bool(int, int)> is_equal;
//  is_equal const equal_func = [](int x, int y)->bool{ return x == y; };
//  auto not_equal_func = std::not2(equal_func);
//  auto result = not_equal_func(7, 7);
//  if (!result)
//    std::cout << "std_not2 #1 passed." << std::endl;
//  else
//    std::cout << "std_not2 #1 failed." << std::endl;
//
//  result = not_equal_func(7, 8);
//  if (result)
//    std::cout << "std_not2 #2 passed." << std::endl;
//  else
//    std::cout << "std_not2 #2 failed." << std::endl;
//}

void std_ref()
{
  auto var = 26;
  auto ref_var = std::ref(var);
  var++;

  if (ref_var == 27)
    std::cout << "std_ref passed." << std::endl;
  else
    std::cout << "std_ref failed." << std::endl;
}

// Deprecated in C++17
//void binary_negate()
//{
//  std::vector<int> v1 = { 10, 20, 30, 40, 50 };
//  std::vector<int> v2 = {  0, 15, 30, 45, 60 };
//
//  typedef std::function<bool(int, int)> same_type;
//  same_type const same = [](int x, int y)->bool{ return x == y; };
//
//  std::binary_negate<same_type> not_same(same);
//
//  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> first_mismatch = std::mismatch(v1.begin(), v1.end(), v2.begin(), same);
//  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> first_match = std::mismatch(v1.begin(), v1.end(), v2.begin(), not_same);
//
//  if (*first_mismatch.second == 0)
//    std::cout << "binary_negate #1 passed." << std::endl;
//  else
//    std::cout << "binary_negate #1 failed." << std::endl;
//
//  if (*first_match.second == 30)
//    std::cout << "binary_negate #2 passed." << std::endl;
//  else
//    std::cout << "binary_negate #2 failed." << std::endl;
//}

void std_reference_wrapper()
{
  int a(6), b(7), c(8);

  // an array of "references":
  std::reference_wrapper<int> refs[] = { a, b, c };

  if(refs[0] == 6 && refs[1] == 7 && refs[2] == 8)
    std::cout << "std_reference_wrapper passed." << std::endl;
  else
    std::cout << "std_reference_wrapper failed." << std::endl;
}

void std_function()
{
  //http://en.cppreference.com/w/cpp/utility/functional/function

  std::function<int(int,int)> multiplication = [](int x, int y) { return x * y; };
  auto result = multiplication(27, 6);
  if (result == 162)
    std::cout << "std_function passed." << std::endl;
  else
    std::cout << "std_function failed." << std::endl;
}

// Deprecated in C++17
//void unary_negate()
//{
//  std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7 };
//
//  typedef std::function<bool(int)> odd_type;
//  odd_type const odd_func = [](int x)->bool{ return x % 2 == 1; };
//  std::unary_negate<odd_type> even_func(odd_func);
//  auto cx = std::count_if(v1.begin(), v1.end(), even_func);
//  if(cx == 3)
//    std::cout << "unary_negate passed." << std::endl;
//  else
//    std::cout << "unary_negate failed." << std::endl;
//}

void std_bit_and()
{
    int arg1 = 0X0F;
    int arg2 = 0X0E;
    auto func = std::bit_and<int>();
    int result = func(arg1, arg2);
    if (result == 0X0E)
      std::cout << "std_bit_and passed." << std::endl;
    else
      std::cout << "std_bit_and failed." << std::endl;
}

void std_bit_or()
{
  int arg1 = 0XF0;
  int arg2 = 0XFF;
  auto func = std::bit_or<int>();
  int result = func(arg1, arg2);
  if (result == 0XFF)
    std::cout << "std_bit_or passed." << std::endl;
  else
    std::cout << "std_bit_or failed." << std::endl;
}

void std_bit_xor()
{
  int arg1 = 0XF0;
  int arg2 = 0X0F;
  auto func = std::bit_xor<int>();
  int result = func(arg1, arg2);
  if (result == 0XFF)
    std::cout << "std_bit_xor passed." << std::endl;
  else
    std::cout << "std_bit_xor failed." << std::endl;
}

void std_bit_not()
{
  auto bn = std::bit_not()(17);
  std::cout << "bit_not() = " << bn << '\n';
}

void std_divides()
{
  int arg1 = 80;
  int arg2 = 5;
  auto func = std::divides<int>();
  int result = func(arg1, arg2);
  if (result == 16)
    std::cout << "std_divides passed." << std::endl;
  else
    std::cout << "std_divides failed." << std::endl;
}

void std_equal_to()
{
  int arg1 = 80;
  int arg2 = 80;
  auto func = std::equal_to<int>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_equal_to passed." << std::endl;
  else
    std::cout << "std_equal_to failed." << std::endl;
}

void std_greater()
{
  int arg1 = 80;
  int arg2 = 78;
  auto func = std::greater<int>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_greater passed." << std::endl;
  else
    std::cout << "std_greater failed." << std::endl;
}

void std_greater_equal()
{
  int arg1 = 80;
  int arg2 = 78;
  auto func = std::greater_equal<int>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_greater_equal #1 passed." << std::endl;
  else
    std::cout << "std_greater_equal #2 failed." << std::endl;

  arg2 = 80;
  result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_greater_equal #1 passed." << std::endl;
  else
    std::cout << "std_greater_equal #2 failed." << std::endl;
}

void std_less()
{
  int arg1 = 78;
  int arg2 = 80;
  auto func = std::less<int>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_less passed." << std::endl;
  else
    std::cout << "std_less failed." << std::endl;
}

void std_less_equal()
{
  int arg1 = 78;
  int arg2 = 80;
  auto func = std::less_equal<int>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_less_equal #1 passed." << std::endl;
  else
    std::cout << "std_less_equal #2 failed." << std::endl;

  arg2 = 80;
  result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_less_equal #1 passed." << std::endl;
  else
    std::cout << "std_less_equal #2 failed." << std::endl;
}

void std_logical_and()
{
  bool arg1 = true;
  bool arg2 = true;
  auto func = std::logical_and<bool>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_logical_and #1 passed." << std::endl;
  else
    std::cout << "std_logical_and #1 failed." << std::endl;

  arg2 = false;
  result = func(arg1, arg2);
  if (!result)
    std::cout << "std_logical_and #2 passed." << std::endl;
  else
    std::cout << "std_logical_and #2 failed." << std::endl;
}

void std_logical_not()
{
  bool arg1 = true;
  auto func = std::logical_not<bool>();
  bool result = func(arg1);
  if (!result)
    std::cout << "std_logical_not #1 passed." << std::endl;
  else
    std::cout << "std_logical_not #1 failed." << std::endl;

  arg1 = false;
  result = func(arg1);
  if (result)
    std::cout << "std_logical_not #2 passed." << std::endl;
  else
    std::cout << "std_logical_not #2 failed." << std::endl;
}

void std_logical_or()
{
  bool arg1 = true;
  bool arg2 = false;
  auto func = std::logical_or<bool>();
  bool result = func(arg1, arg2);
  if (result)
    std::cout << "std_logical_or #1 passed." << std::endl;
  else
    std::cout << "std_logical_or #1 failed." << std::endl;

  arg1 = false;
  result = func(arg1, arg2);
  if (!result)
    std::cout << "std_logical_or #2 passed." << std::endl;
  else
    std::cout << "std_logical_or #2 failed." << std::endl;
}

void std_minus()
{
  int arg1 = 80;
  int arg2 = 5;
  auto func = std::minus<int>();
  int result = func(arg1, arg2);
  if (result == 75)
    std::cout << "std_minus passed." << std::endl;
  else
    std::cout << "std_minus failed." << std::endl;
}

void std_modulus()
{
  int arg1 = 27;
  int arg2 = 7;
  auto func = std::modulus<int>();
  int result = func(arg1, arg2);
  if (result == 6)
    std::cout << "std_modulus passed." << std::endl;
  else
    std::cout << "std_modulus failed." << std::endl;
}

void std_multiplies()
{
  int arg1 = 27;
  int arg2 = 6;
  auto func = std::multiplies<int>();
  int result = func(arg1, arg2);
  if (result == 162)
    std::cout << "std_multiplies passed." << std::endl;
  else
    std::cout << "std_multiplies failed." << std::endl;
}

void std_negate()
{
  int arg1 = 27;
  auto func = std::negate<int>();
  int result = func(arg1);
  if (result == -27)
    std::cout << "std_negate passed." << std::endl;
  else
    std::cout << "std_negate failed." << std::endl;
}

void std_not_equal_to()
{
  int arg1 = 78;
  int arg2 = 80;
  auto func = std::not_equal_to<int>();
  bool result = func(arg1, arg2);
  if (result == true)
    std::cout << "std_not_equal_to passed." << std::endl;
  else
    std::cout << "std_not_equal_to failed." << std::endl;
}

void std_plus()
{
  int arg1 = 78;
  int arg2 = 80;
  auto func = std::plus<int>();
  int result = func(arg1, arg2);
  if (result == 158)
    std::cout << "std_plus passed." << std::endl;
  else
    std::cout << "std_plus failed." << std::endl;
}

void std_default_searcher()
{
  std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
    " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
  std::string needle = "pisci";
  auto it = std::search( in.begin(), in.end(),
    std::default_searcher(
      needle.begin(), needle.end() ) );
  if( it != in.end() )
    std::cout << "default_searcher passed: The string " << needle << " found at offset " << it - in.begin() << "\n\n";
  else
    std::cout << "default_searcher failed: The string " << needle << " not found\n\n";
}

void std_boyer_moore_searcher()
{
  // TODO: 08/12/2018
}

void std_boyer_moore_horspool_searcher()
{
  // TODO: 08/12/2018
}

void std_functional()
{
  std_bind();
  std_cref();
  std_mem_fn();
  std_invoke();
  //std_not1(); Deprecated in C++17
  //std_not2(); Deprecated in C++17
  std_ref();
  //binary_negate(); Deprecated in C++17
  std_reference_wrapper();
  std_function();
  //unary_negate(); Deprecated in C++17
  std_bit_and();
  std_bit_or();
  std_bit_xor();
  std_bit_not();    // C++14
  std_divides();
  std_equal_to();
  std_greater();
  std_greater_equal();
  std_less();
  std_less_equal();
  std_logical_and();
  std_logical_not();
  std_logical_or();
  std_minus();
  std_modulus();
  std_multiplies();
  std_negate();
  std_not_equal_to();
  std_plus();
  std_default_searcher();                // C++17
  std_boyer_moore_searcher();            // C++17
  std_boyer_moore_horspool_searcher();   // C++17
}
