//
// Created by Islam, Abdullah Al Raqibul on 10/26/22.
//

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    this->count = 0;
    for (int i = 0; i < 26; i += 1) {
      this->child[i] = NULL;
    }
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie *curr = this;
    int wordLen = word.length();

    for (int i = 0; i < wordLen; i += 1) {
      int currIdx = word[i] - 'a';
      if (curr->child[currIdx] == NULL) curr->child[currIdx] = new Trie();
      curr = curr->child[currIdx];
      curr->count += 1;
    }
  }

  /** Returns if the word is in the trie. */
  int search(string word) {
    Trie *curr = this;
    int ret = 0;
    int wordLen = word.length();

    for (int i = 0; i < wordLen; i += 1) {
      int currIdx = word[i] - 'a';
      curr = curr->child[currIdx];
      ret += curr->count;
    }
    return ret;
  }

private:
  Trie *child[26];
  int count;
};

class Solution {
private:
  Trie trie = Trie();

public:
  vector<int> sumPrefixScores(vector <string> &words) {
    vector<int> ret;
    int sz = words.size();
    for (int i = 0; i < sz; i += 1) {
      trie.insert(words[i]);
    }

    for (int i = 0; i < sz; i += 1) {
      ret.push_back(trie.search(words[i]));
    }

    return ret;
  }
};