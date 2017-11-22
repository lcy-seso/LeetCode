#include <iostream>
#include <random>
#include <vector>

void genRandomInput(const int min, const int max, std::vector<int>& vec) {
  std::random_device rnd_device;
  std::mt19937 mersenne_engine(rnd_device());
  std::uniform_int_distribution<int> dist(min, max);
  auto gen = std::bind(dist, mersenne_engine);

  std::generate(vec.begin(), vec.end(), gen);
}

void printList(const std::vector<int>& in) {
  for (auto value : in) std::cout << value << " ";
  std::cout << std::endl << std::endl;
}

std::vector<int> maxSlidingWindow(std::vector<int>& nums, const int k) {
  // A naive and the most direct solution that everyone can think of.

  std::vector<int> max_elements;
  if (!nums.size()) return max_elements;

  int window_num = k >= nums.size() ? 1 : nums.size() - k + 1;
  max_elements.resize(window_num, 0);

  if (k >= nums.size()) {
    max_elements[0] = *std::max_element(nums.begin(), nums.end());
  } else {
    for (size_t i = 0; i < window_num; ++i) {
      max_elements[i] =
          *std::max_element(nums.begin() + i, nums.begin() + (i + k));
    }
  }

  return max_elements;
}

int main() {
  const int kVecLength = 15;
  const int kMinValue = -7;
  const int kMaxValue = 7;

  std::vector<int> nums(kVecLength);
  genRandomInput(kMinValue, kMaxValue, nums);

  std::cout << "Input numbers :" << std::endl;
  printList(nums);

  int window_size = 3;

  std::cout << "The maximum elements in window :" << std::endl;
  printList(maxSlidingWindow(nums, window_size));
  return 0;
}
