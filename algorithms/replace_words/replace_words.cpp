#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

const int kAlphabetSize = 26;

struct TrieNode {
  char val;
  TrieNode* next[kAlphabetSize];
  bool isEndOfWord = true;

  TrieNode(char c) : val(c) {
    for (int i = 0; i < kAlphabetSize; ++i) next[i] = NULL;
    isEndOfWord = false;
  };
};

void insertTrie(TrieNode* root, const std::string key) {
  TrieNode* cur = root;
  for (int i = 0; i < key.length(); ++i) {
    int index = key[i] - 'a';

    if (!cur->next[index]) cur->next[index] = new TrieNode(key[i]);
    cur = cur->next[index];
  }
  cur->isEndOfWord = true;
}

void emptyTrieTree(TrieNode* root) {
  if (!root) return;

  std::queue<TrieNode*> to_be_visited;
  for (int i = 0; i < kAlphabetSize; ++i) {
    if (root->next[i]) to_be_visited.push(root->next[i]);
  }
  delete root;
  root = NULL;

  while (!to_be_visited.empty()) {
    auto front = to_be_visited.front();
    to_be_visited.pop();

    for (int i = 0; i < kAlphabetSize; ++i) {
      if (front->next[i]) to_be_visited.push(front->next[i]);
    }
    delete front;
    front = NULL;
  }
}

void dfsPrintTrieTree(const TrieNode* node, std::string path) {
  // print root to leaf path.

  if (!node) return;
  if (node->isEndOfWord)
    std::cout << path.substr(1, path.length() - 1) + node->val << std::endl;

  for (int i = 0; i < kAlphabetSize; ++i)
    dfsPrintTrieTree(node->next[i], path + node->val);
}

void bfsPrintTrieTree(const TrieNode* root) {
  if (!root) return;

  std::queue<TrieNode*> to_be_visited;
  for (int i = 0; i < kAlphabetSize; ++i) {
    if (root->next[i]) to_be_visited.push(root->next[i]);
  }
  int count = to_be_visited.size();

  while (!to_be_visited.empty()) {
    for (int i = 0; i < count; ++i) {
      auto front = to_be_visited.front();
      to_be_visited.pop();
      std::cout << front->val << " ";
      for (int j = 0; j < kAlphabetSize; ++j) {
        if (front->next[j]) to_be_visited.push(front->next[j]);
      }
    }
    std::cout << std::endl;
    count = to_be_visited.size();
  }
}

bool searchTrie(const TrieNode* root, std::string key) {
  const TrieNode* pCur = root;
  for (int i = 0; i < key.length(); ++i) {
    int idx = key[i] - 'a';
    if (!pCur->next[idx]) return false;

    pCur = pCur->next[idx];
  }
  return pCur != NULL && pCur->isEndOfWord;
}

std::string searchPrefix(const TrieNode* root, const std::string word) {
  const TrieNode* pCur = root;

  std::string result = "";
  for (int i = 0; i < word.length(); ++i) {
    int idx = word[i] - 'a';
    if (!pCur->next[idx]) {
      if (pCur->isEndOfWord)
        return result;
      else
        return "";
    } else {
      if (pCur->isEndOfWord) return result;
    }

    pCur = pCur->next[idx];
    result += word[i];
  }

  return (pCur != NULL && pCur->isEndOfWord) ? result : "";
}

std::string replaceWords(const std::vector<std::string>& dict,
                         const std::string sentence) {
  auto append_a_word = [&](
      const TrieNode* root, const std::string word, std::string& ans) {
    std::string prefix = searchPrefix(root, word);
    ans += (prefix.empty() ? word : prefix);
  };

  // build the TrieTree.
  // root is a special node whose value is '#'
  TrieNode* root = new TrieNode('#');
  for (auto word : dict) insertTrie(root, word);
  // bfsPrintTrieTree(root);
  // dfsPrintTrieTree(root, "");

  size_t start = 0;
  std::string ans = "";
  while (true) {
    size_t pos = sentence.find(' ', start);
    if (pos == std::string::npos) break;
    std::string word = sentence.substr(start, pos - start);

    append_a_word(root, word, ans);
    ans += " ";

    start = pos + 1;
  }

  if (start != sentence.length()) {
    std::string word = sentence.substr(start, sentence.length() - start);
    append_a_word(root, word, ans);
  }

  emptyTrieTree(root);
  return ans;
}

int main() {
  // std::vector<std::string> dict = {"cat", "bat", "rat"};
  // std::string sentence = "the cattle was rattled by the battery";

  // expected : "a a a a a a a a bbb baba a"
  std::vector<std::string> dict = {"a", "aa", "aaa", "aaaa"};
  std::string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";

  std::string result = replaceWords(dict, sentence);

  std::cout << result << std::endl;

  return 0;
}
