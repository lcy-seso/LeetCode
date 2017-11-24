#pragma once

#include <random>
#include <vector>

int randint(const int min, const int max) {
  std::random_device rnd;
  std::mt19937 engine(rnd());
  std::uniform_int_distribution<int> dist(min, max);
  return dist(engine);
}

void genRandIntList(std::vector<int>& vec,
                    const int max_len,
                    const int min,
                    const int max) {
  if (!max_len) return;
  vec.resize(max_len, 0);

  std::random_device rnd;                          // random seed.
  std::mt19937 engine(rnd());                      // the engine.
  std::uniform_int_distribution<> dist(min, max);  // the distribution
  auto gen = std::bind(dist, engine);
  std::generate(vec.begin(), vec.end(), gen);
}

template <typename T>
void printList(const std::vector<T>& vec) {
  for (auto v : vec) std::cout << v << " ";
  std::cout << std::endl;
}
