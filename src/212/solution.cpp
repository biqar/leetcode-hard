//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

struct TrieNode {
  struct TrieNode *child[26];
  string wordAt;

  TrieNode() {
    this->wordAt = "";
    for(int i=0; i<26; i+=1) {
      this->child[i] = NULL;
    }
  }
};

class Solution {
public:
  struct TrieNode *buildTrie(vector<string>& words) {
    struct TrieNode *root = new TrieNode();

    for(string word : words) {
      struct TrieNode *curr = root;
      int wordLen = word.length();

      for(int i=0; i<wordLen; i+=1) {
        int currIdx = word[i] - 'a';

        if(curr->child[currIdx] == NULL) {
          curr->child[currIdx] = new TrieNode();
        }
        curr = curr->child[currIdx];
      }
      curr->wordAt = word;
    }
    return root;
  }

  void findWords(vector<vector<char>>& board, TrieNode *trieNode,
                 int x, int y, vector<string>& ret) {
    if(x < 0 || y < 0 || x >= r || y >= c) return;
    char currCh = board[x][y];
    if(currCh == '*' || trieNode->child[currCh - 'a'] == NULL) return;
    trieNode = trieNode->child[currCh - 'a'];
    if(trieNode->wordAt != "") {
      ret.push_back(trieNode->wordAt);
      matchedWords += 1;
      trieNode->wordAt = "";
    }

    board[x][y] = '*';
    findWords(board, trieNode, x+1, y, ret);
    findWords(board, trieNode, x-1, y, ret);
    findWords(board, trieNode, x, y+1, ret);
    findWords(board, trieNode, x, y-1, ret);
    board[x][y] = currCh;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    numWords = words.size();
    r = board.size();
    c = board[0].size();
    matchedWords = 0;

    struct TrieNode *root = buildTrie(words);
    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        findWords(board, root, i, j, ret);
        if(matchedWords == numWords) return ret;
      }
    }

    return ret;
  }
private:
  int r, c, numWords, matchedWords;
};