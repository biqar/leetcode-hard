//
// Created by Islam, Abdullah Al Raqibul on 02/01/22.
//

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    this->wordAt = false;
    for(int i=0; i<26; i+=1) {
      this->child[i] = NULL;
    }
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie *curr = this;
    int wordLen = word.length();

    for(int i=wordLen-1; i>=0; i-=1) {
      int currIdx = word[i] - 'a';
      if(curr->child[currIdx] == NULL) curr->child[currIdx] = new Trie();
      curr = curr->child[currIdx];
    }
    curr->wordAt = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie *curr = this;
    int wordLen = word.length();

    for(int i=wordLen-1; i>=0; i-=1) {
      int currIdx = word[i] - 'a';
      if(curr->wordAt) return true;
      if(curr->child[currIdx] == NULL) return false;
      curr = curr->child[currIdx];
    }
    return curr->wordAt;
  }
private:
  Trie *child[26];
  bool wordAt;
};

class StreamChecker {
private:
  string stream = "";
  Trie trie = Trie();
  int mxLen = 0;

public:
  StreamChecker(vector<string>& words) {
    int sz = words.size();
    for(int i=0; i<sz; i+=1) {
      trie.insert(words[i]);
      if(words[i].length() > mxLen) mxLen = words[i].length();
    }
  }

  bool query(char letter) {
    stream += letter;
    if(stream.length() > mxLen) {
      stream.erase(stream.begin());
    }
    //cout << stream << endl;
    return trie.search(stream);
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */