#pragma once

#include <random>
#include <vector>

void genRandIntList(std::vector<int>& vec,
                    const int max_len,
                    const int min,
                    const int max) {
  if (!max_len) return;

  vec.resize(max_len, 0);

  std::random_device rnd_device;
  std::mt19937 mersenne_engine(rnd_device());
  std::uniform_int_distribution<> dist(min, max);
  auto gen = std::bind(dist, mersenne_engine);
  std::generate(vec.begin(), vec.end(), gen);
}

template <typename T>
void printList(const std::vector<T>& vec) {
  for (auto v : vec) std::cout << v << " ";
  std::cout << std::endl;
}
