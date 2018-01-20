#include <iostream>

int hammingWeight(uint32_t n) {
  int count = 0;
  uint32_t mask = 1;

  for (size_t i = 0; i < 32; ++i) {
    if (n & mask) count++;
    mask <<= 1;
  }
  return count;
}

int main() {
  uint32_t n = 4;
  std::cout << hammingWeight(n) << std::endl;
  return 0;
}
