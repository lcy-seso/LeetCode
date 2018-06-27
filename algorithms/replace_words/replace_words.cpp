#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

const int kAlphabetSize = 26;

struct TrieNode {
  TrieNode* children[kAlphabetSize];
  bool isEndOfWord;

  TrieNode() {
    for (int i = 0; i < kAlphabetSize; ++i) children[i] = NULL;
    isEndOfWord = false;
  };
  ~TrieNode() {
    for (int i = 0; i < kAlphabetSize; ++i) {
      if (children[i]) delete children[i];
    }
  };
};

void insertTrie(TrieNode* root, std::string key) {
  TrieNode* cur = root;
  for (int i = 0; i < key.length(); ++i) {
    int index = key[i] - 'a';

    if (!cur->children[index]) cur->children[index] = new TrieNode();
    cur = cur->children[index];
  }
  cur->isEndOfWord = true;
}

void emptyTrieTree(TrieNode* node) {}

void dfsPrintTrieTreeUtil(const TrieNode* node, int val) {
  if (!node) return;

  std::cout << char('a' + val) << " ";
  if (node->isEndOfWord) std::cout << std::endl;

  for (int i = 0; i < kAlphabetSize; ++i)
    dfsPrintTrieTreeUtil(node->children[i], i);
}

void dfsPrintTrieTree(const TrieNode* root) {
  for (int i = 0; i < kAlphabetSize; ++i)
    dfsPrintTrieTreeUtil(root->children[i], i);
}

void bfsPrintTrieTree(const TrieNode* root) {
  if (!root) return;

  std::queue<TrieNode*> to_be_visited;
  for (int i = 0; i < kAlphabetSize; ++i) {
    if (root->children[i]) {
      std::cout << char('a' + i) << " ";
      to_be_visited.push(root->children[i]);
    }
  }
  std::cout << std::endl;
  int count = to_be_visited.size();

  while (!to_be_visited.empty()) {
    for (int i = 0; i < count; ++i) {
      auto front = to_be_visited.front();
      to_be_visited.pop();

      for (int j = 0; j < kAlphabetSize; ++j) {
        if (front->children[j]) {
          std::cout << char('a' + j) << " ";
          to_be_visited.push(front->children[j]);
        }
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
    if (!pCur->children[idx]) return false;

    pCur = pCur->children[idx];
  }
  return pCur != NULL && pCur->isEndOfWord;
}

std::string searchPrefix(const TrieNode* root, const std::string word) {
  const TrieNode* pCur = root;

  std::string result = "";
  for (int i = 0; i < word.length(); ++i) {
    int idx = word[i] - 'a';
    if (!pCur->children[idx]) {
      if (pCur->isEndOfWord)
        break;
      else
        return "";
    }

    pCur = pCur->children[idx];
    result += word[i];
  }

  return (pCur != NULL && pCur->isEndOfWord) ? result : "";
}

std::string replaceWords(const std::vector<std::string>& dict,
                         const std::string sentence) {
  auto append_a_word = [](
      const TrieNode* root, const std::string word, std::string& ans) {
    std::string prefix = searchPrefix(root, word);
    ans += (prefix.empty() ? word : prefix);
  };

  // build the TrieTree.
  TrieNode* root = new TrieNode();
  for (auto word : dict) insertTrie(root, word);
  // bfsPrintTrieTree(root);
  // dfsPrintTrieTree(root);

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
  return ans;
}

int main() {
  std::vector<std::string> dict = {"cat", "bat", "rat"};
  std::string sentence = "the cattle was rattled by the battery";

  std::string result = replaceWords(dict, sentence);

  std::cout << result << std::endl;

  return 0;
}
