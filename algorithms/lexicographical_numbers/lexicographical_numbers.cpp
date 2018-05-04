#include <iostream>
#include <stack>
#include <vector>

std::vector<int> lexicalOrder(int n) {
  std::vector<int> results;
  std::stack<int> stk;

  stk.push(1);
  while (!stk.empty()) {
    int num = stk.top();
    results.push_back(num);
    stk.pop();
    if (num + 1 <= n && num % 10 < 9) stk.push(num + 1);
    if (10 * num <= n) stk.push(10 * num);
  }

  return results;
}

int main() {
  const int N = 192;
  std::vector<int> results = lexicalOrder(N);

  for (auto n : results) std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}
