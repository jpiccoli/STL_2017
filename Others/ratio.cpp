#include "../prototypes.h"

#include <ratio>

void ratio_add()
{
  typedef std::ratio<2, 3> r23;
  typedef std::ratio<7, 2> r72;

  typedef std::ratio_add<r23, r72> sum;

  if (sum::num == 25 && sum::den == 6)
    std::cout << "ratio_add passed." << std::endl;
  else
    std::cout << "ratio_add failed." << std::endl;
}

void ratio_divide()
{
  typedef std::ratio<2, 3> r23;
  typedef std::ratio<7, 2> r72;

  typedef std::ratio_divide<r23, r72> quotient;

  if (quotient::num == 4 && quotient::den == 21)
    std::cout << "ratio_divide passed." << std::endl;
  else
    std::cout << "ratio_divide failed." << std::endl;
}

void ratio_equal()
{
  typedef std::ratio<2, 3> r1;
  typedef std::ratio<2, 3> r2;

  typedef std::ratio_equal<r1, r2> equal_op;

  if (equal_op::value == true)
    std::cout << "ratio_equal passed." << std::endl;
  else
    std::cout << "ratio_equal failed." << std::endl;
}

void ratio_greater()
{
  typedef std::ratio<3, 4> r1;
  typedef std::ratio<2, 3> r2;

  typedef std::ratio_greater<r1, r2> gt_op;

  if (gt_op::value == true)
    std::cout << "ratio_greater passed." << std::endl;
  else
    std::cout << "ratio_greater failed." << std::endl;
}

void ratio_greater_equal()
{
  typedef std::ratio<3, 4> r1;
  typedef std::ratio<2, 3> r2;
  typedef std::ratio<3, 4> r3;

  typedef std::ratio_greater_equal<r1, r2> ge_op1;
  typedef std::ratio_greater_equal<r1, r3> ge_op2;

  if (ge_op1::value == true)
    std::cout << "ratio_greater_equal #1 passed." << std::endl;
  else
    std::cout << "ratio_greater_equal #1 failed." << std::endl;

  if (ge_op2::value == true)
    std::cout << "ratio_greater_equal #2 passed." << std::endl;
  else
    std::cout << "ratio_greater_equal #2 failed." << std::endl;
}

void ratio_less()
{
  typedef std::ratio<3, 4> r1;
  typedef std::ratio<2, 3> r2;

  typedef std::ratio_less<r2, r1> lt_op;

  if (lt_op::value == true)
    std::cout << "ratio_less passed." << std::endl;
  else
    std::cout << "ratio_less failed." << std::endl;
}

void ratio_less_equal()
{
  typedef std::ratio<3, 4> r1;
  typedef std::ratio<2, 3> r2;
  typedef std::ratio<3, 4> r3;

  typedef std::ratio_less_equal<r2, r1> le_op1;
  typedef std::ratio_less_equal<r1, r3> le_op2;

  if (le_op1::value == true)
    std::cout << "ratio_less_equal #1 passed." << std::endl;
  else
    std::cout << "ratio_less_equal #1 failed." << std::endl;

  if (le_op2::value == true)
    std::cout << "ratio_less_equal #2 passed." << std::endl;
  else
    std::cout << "ratio_less_equal #2 failed." << std::endl;
}

void ratio_multiply()
{
  typedef std::ratio<2, 3> r23;
  typedef std::ratio<7, 2> r72;

  typedef std::ratio_multiply<r23, r72> product;

  if (product::num == 7 && product::den == 3)
    std::cout << "ratio_multiply passed." << std::endl;
  else
    std::cout << "ratio_multiply failed." << std::endl;
}

void ratio_not_equal()
{
  typedef std::ratio<3, 4> r1;
  typedef std::ratio<2, 3> r2;

  typedef std::ratio_not_equal<r1, r2> ne_op;

  if (ne_op::value == true)
    std::cout << "ratio_not_equal passed." << std::endl;
  else
    std::cout << "ratio_not_equal failed." << std::endl;
}

void ratio_subtract()
{
  typedef std::ratio<2, 3> r23;
  typedef std::ratio<7, 2> r72;

  typedef std::ratio_subtract<r72, r23> difference;

  if (difference::num == 17 && difference::den == 6)
    std::cout << "ratio_subtract passed." << std::endl;
  else
    std::cout << "ratio_subtract failed." << std::endl;
}

void std_ratio()
{
  ratio_add();
  ratio_divide();
  ratio_equal();
  ratio_greater();
  ratio_greater_equal();
  ratio_less();
  ratio_less_equal();
  ratio_multiply();
  ratio_not_equal();
  ratio_subtract();
}
