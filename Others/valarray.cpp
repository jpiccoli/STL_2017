#include "../prototypes.h"

#include <valarray>

void std_valarray()
{
  int val = 0;

  std::vector<int> vec1{ 23, 24, 25, 26, 27 };

  // Initialize with vector
  std::valarray<int> va1(vec1.data(), vec1.size());

  // apply
  auto op = [](int x)->int { return x * 5; };
  std::valarray<int> result = va1.apply(op);
  if(result[0] == 115 && result[1] == 120 && result[2] == 125 && result[3] == 130 && result[4] == 135)
    std::cout << "valarray apply passed." << std::endl;
  else
    std::cout << "valarray apply failed." << std::endl;

  // cshift
  // Note: (+) value => left shift; (-) value => right shift
  // First make copies
  std::valarray<int> lsva = va1;
  std::valarray<int> rsva = va1;
  lsva = lsva.cshift(1);
  rsva = rsva.cshift(-1);

  if (lsva[0] == 24 && lsva[1] == 25 && lsva[2] == 26 && lsva[3] == 27 && lsva[4] == 23)
    std::cout << "valarray cshift #1 passed." << std::endl;
  else
    std::cout << "valarray cshift #1 failed." << std::endl;

  if (rsva[0] == 27 && rsva[1] == 23 && rsva[2] == 24 && rsva[3] == 25 && rsva[4] == 26)
    std::cout << "valarray cshift #2 passed." << std::endl;
  else
    std::cout << "valarray cshift #2 failed." << std::endl;

  // max
  val = va1.max();
  if (val == 27)
    std::cout << "valarray max passed." << std::endl;
  else
    std::cout << "valarray max failed." << std::endl;

  // min
  val = va1.min();
  if (val == 23)
    std::cout << "valarray min passed." << std::endl;
  else
    std::cout << "valarray min failed." << std::endl;

  // resize
  std::valarray<int> resize_va = va1;
  resize_va.resize(3, 7);
  if (resize_va.size() == 3 && resize_va[0] == 7 && resize_va[1] == 7 && resize_va[2] == 7)
    std::cout << "valarray resize passed." << std::endl;
  else
    std::cout << "valarray resize failed." << std::endl;

  // shift

  // sum
  val = va1.sum();
  if (val == 125)
    std::cout << "valarray sum passed." << std::endl;
  else
    std::cout << "valarray sum failed." << std::endl;

  // swap
  std::vector<int> vec1A{ 25, 26, 27 };
  std::vector<int> vec1B{ 30, 31, 32 };

  std::valarray<int> swap1(vec1A.data(), vec1A.size());
  std::valarray<int> swap2(vec1B.data(), vec1B.size());

  swap1.swap(swap2);

  if (swap1[0] == 30 && swap1[1] == 31 && swap1[2] == 32 && 
      swap2[0] == 25 && swap2[1] == 26 && swap2[2] == 27)
    std::cout << "valarray swap passed." << std::endl;
  else
    std::cout << "valarray swap failed." << std::endl;
}
