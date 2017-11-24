#include <iostream>

#include "../utils/utils.h"

bool isPerfectSquare(int num) {
  if (num < 0) return false;

  int left = 0;
  int right = num;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    // This line may have the overflow problem.
    int square = mid * mid;
    if (square == num)
      return true;
    else if (square > num)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return false;
}

int main() {
  const int kMinValue = -100;
  const int kMaxValue = 100;
  int = genRandIntList(nums, 1, kMinValue, kMaxValue)[0];

  if (isPerfectSquare(num))
    std::cout << num << " is a perfect square." << std::endl;
  else
    std::cout << num << " is not a perfect square." << std::endl;

  return 0;
}
