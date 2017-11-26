#include <iostream>

#include "../../utils/utils.h"
#include "heap.h"

int main() {
  const int kMinValue = 0;
  const int kMaxValue = 23;
  const int kMaxVecLen = 10;

  int vec_len = randint(1, kMaxVecLen);
  std::cout << "The length of the vector is : " << vec_len << std::endl;
  std::vector<int> data;
  genRandIntList(data, vec_len, kMinValue, kMaxValue);
  std::cout << "Input :" << std::endl;
  printList<int>(data);

  Heap<int>::sort(data, true);
  std::cout << "Sorted by ascending order: " << std::endl;
  printList<int>(data);

  Heap<int>::sort(data, false);
  std::cout << "Sorted by decending order: " << std::endl;
  printList<int>(data);
}
