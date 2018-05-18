#include <iostream>
#include <vector>

std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
  std::vector<int> s;

  for (int i = 0; i < asteroids.size(); ++i) {
    if (asteroids[i] > 0 || s.empty() || s.back() < 0) {
      // push the positive integer into the stack
      s.push_back(asteroids[i]);
    } else if (s.back() <= -asteroids[i]) {  // collided
      if (s.back() < -asteroids[i]) i--;     // both starts are exploded.
      s.pop_back();
    }  // else { the negative asteriod is exploded }
  }
  return s;
}

int main() {
  // std::vector<int> asteroids = {10, 2, -5};
  std::vector<int> asteroids = {8, -8};

  std::vector<int> results = asteroidCollision(asteroids);
  for (auto n : results) std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}
