#include "../prototypes.h"

#include <limits>

bool status;

void is_specialized()
{
  status = std::numeric_limits<int>::is_specialized;
  if (status)
    std::cout << "is_specialized passed." << std::endl;
  else
    std::cout << "is_specialized failed." << std::endl;
}

void limits_min()
{
  // CHAR_MIN, SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN, FLT_MIN, DBL_MIN, LDBL_MIN or 0, depending on type.
}

void limits_max()
{
  // CHAR_MAX, SCHAR_MAX, UCHAR_MAX, SHRT_MAX, USHRT_MAX, INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX, LLONG_MAX, ULLONG_MAX, UINT_LEAST16_MAX, UINT_LEAST32_MAX, FLT_MAX, DBL_MAX or LDBL_MAX
}

void limits_lowest()
{
}

void digits()
{
}

void digits10()
{
}

void max_digits10()
{
}

void is_signed()
{
  status = std::numeric_limits<int>::is_signed;
  if (status)
    std::cout << "is_signed #1 passed." << std::endl;
  else
    std::cout << "is_signed #1 failed." << std::endl;

  status = std::numeric_limits<unsigned int>::is_signed;
  if (!status)
    std::cout << "is_signed #2 passed." << std::endl;
  else
    std::cout << "is_signed #2 failed." << std::endl;
}

void is_integer()
{
  status = std::numeric_limits<int>::is_integer;
  if (status)
    std::cout << "is_integer #1 passed." << std::endl;
  else
    std::cout << "is_integer #1 failed." << std::endl;

  status = std::numeric_limits<double>::is_integer;
  if (!status)
    std::cout << "is_integer #2 passed." << std::endl;
  else
    std::cout << "is_integer #2 failed." << std::endl;
}

void is_exact()
{
  status = std::numeric_limits<int>::is_exact;
  if (status)
    std::cout << "is_exact passed." << std::endl;
  else
    std::cout << "is_exact failed." << std::endl;
}

void radix()
{
}

void limits_epsilon()
{
}

void limits_round_error()
{
}

void min_exponent()
{
  // FLT_MIN_EXP, DBL_MIN_EXP or LDBL_MIN_EXP
}

void min_exponent10()
{
  // FLT_MIN_10_EXP, DBL_MIN_10_EXP or LDBL_MIN_10_EXP
}

void max_exponent()
{
  // FLT_MAX_EXP, DBL_MAX_EXP or LDBL_MAX_EXP 
}

void max_exponent10()
{
  // FLT_MAX_10_EXP, DBL_MAX_10_EXP or LDBL_MAX_10_EXP
}

void has_infinity()
{
  status = std::numeric_limits<double>::has_infinity;
  if (status)
    std::cout << "has_infinity #1 passed." << std::endl;
  else
    std::cout << "has_infinity #1 failed." << std::endl;

  status = std::numeric_limits<double>::is_integer;
  if (!status)
    std::cout << "has_infinity #2 passed." << std::endl;
  else
    std::cout << "has_infinity #2 failed." << std::endl;
}

void has_quiet_NAN()
{
}

void has_signaling_NAN()
{
}

void has_denorm()
{
}

void infinity()
{
}

void quiet_NAN()
{
}

void signaling_NAN()
{
}

void denorm_min()
{
}

void is_iec559()
{
}

void is_bounded()
{
  status = std::numeric_limits<int>::is_bounded;
  if (status)
    std::cout << "is_bounded passed." << std::endl;
  else
    std::cout << "is_bounded failed." << std::endl;
}

void is_modulo()
{
  status = std::numeric_limits<int>::is_modulo;
  if (status)
    std::cout << "is_modulo passed." << std::endl;
  else
    std::cout << "is_modulo failed." << std::endl;
}

void traps()
{
}

void tinyness_before()
{
}

void round_style()
{
}

void std_limits()
{
  is_specialized();
  limits_min();
  limits_max();
  limits_lowest();
  digits();
  digits10();
  max_digits10();
  is_signed();
  is_integer();
  is_exact();
  radix();
  limits_epsilon();
  limits_round_error();
  min_exponent();
  min_exponent10();
  max_exponent();
  max_exponent10();
  has_infinity();
  has_quiet_NAN();
  has_signaling_NAN();
  has_denorm();
  infinity();
  quiet_NAN();
  signaling_NAN();
  denorm_min();
  is_iec559();
  is_bounded();
  is_modulo();
  traps();
  tinyness_before();
  round_style();
}
