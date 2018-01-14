#include <iostream>
#include <unordered_map>
#include <vector>

#include "../utils/utils.h"

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
  std::vector<std::string> results;

  std::unordered_map<std::string, int> word_counts;
  for (auto word : words) {
    auto it = word_counts.find(word);
    if (it == word_counts.end())
      word_counts[word] = 1;
    else
      word_counts[word] += 1;
  }

  std::vector<std::pair<std::string, int>> word_count_pairs;
  for (const auto& item : word_counts)
    word_count_pairs.push_back(std::make_pair(item.first, item.second));

  std::sort(word_count_pairs.begin(),
            word_count_pairs.end(),
            [](const std::pair<std::string, int>& a,
               const std::pair<std::string, int>& b) {
              if (a.second != b.second) {
                return a.second > b.second;
              } else {
                if (a.first.compare(b.first) < 0)
                  return true;
                else
                  return false;
              };
            });

  for (auto it = word_count_pairs.begin(); it < word_count_pairs.begin() + k;
       ++it)
    results.push_back(it->first);

  return results;
}

int main() {
  std::vector<std::string> inputs{
      "i", "love", "leetcode", "i", "love", "coding"};
  const int k = 2;

  std::cout << std::endl;
  printList<std::string>(topKFrequent(inputs, k));
}
