#pragma once

#include <chrono>
#include <random>
#include <vector>

int randint(const int min,
            const int max,
            const unsigned int seed = 0,
            bool fix_seed = false) {
  std::mt19937 engine;
  if (fix_seed)
    engine.seed(seed);
  else
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());

  std::uniform_int_distribution<int> dist(min, max);
  return dist(engine);
}

void genRandIntList(std::vector<int>& vec,
                    const int max_len,
                    const int min,
                    const int max,
                    const unsigned int seed = 0,
                    bool fix_seed = false) {
  if (!max_len) return;
  vec.resize(max_len, 0);

  std::random_device rnd;  // random seed.
  std::mt19937 engine;     // the engine.
  if (fix_seed)
    engine.seed(fix_seed);
  else
    engine.seed(rnd());

  std::uniform_int_distribution<> dist(min, max);  // the distribution
  auto gen = std::bind(dist, engine);
  std::generate(vec.begin(), vec.end(), gen);
}

template <typename T>
void printList(const std::vector<T>& vec) {
  for (auto v : vec) std::cout << v << " ";
  std::cout << std::endl;
}
