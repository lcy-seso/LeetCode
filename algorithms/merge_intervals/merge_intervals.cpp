#include <iostream>
#include <vector>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

std::vector<Interval> merge(std::vector<Interval>& intervals) {
  if (intervals.size() <= 1) return intervals;

  std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
    if (a.start == b.start)
      return a.end < b.end;
    else
      return a.start < b.start;
  });

  std::vector<Interval> results;
  results.emplace_back(intervals[0]);

  for (int i = 1; i < intervals.size(); ++i) {
    auto a = results.back();
    auto b = intervals[i];

    if (a.end >= b.start) {  // overlapped
      results.pop_back();
      results.push_back(
          Interval(std::min(a.start, b.start), std::max(a.end, b.end)));
    } else
      results.push_back(b);
  }

  return results;
}

int main() {
  std::vector<std::vector<int>> inputs = {{1, 4}, {4, 5}};
  // expected outputs: outputs = {{1, 5}}

  // std::vector<std::vector<int>> inputs = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  // expected outputs: outputs = {{1, 6}, {8, 10}, {15, 18}};

  // std::vector<std::vector<int>> inputs = {{1, 4}, {0, 2}, {3, 5}};
  // expected outputs: outputs = {{0, 5}};

  std::vector<Interval> intervals;
  for (auto in : inputs) intervals.emplace_back(Interval(in[0], in[1]));

  std::vector<Interval> results = merge(intervals);
  std::cout << "merged intervals : " << std::endl;
  for (auto interval : results)
    std::cout << "[" << interval.start << " " << interval.end << "]"
              << std::endl;

  return 0;
}
