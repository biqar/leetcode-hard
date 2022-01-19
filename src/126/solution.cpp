//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Node{
public:
  string word;
  int depth;
  Node *prev;

  Node(string word_, int depth_, Node *prev_){
    word = word_;
    depth = depth_;
    prev = prev_;
  }
};

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    mapWords(beginWord, wordList);
    vector<vector<string>> ret;
    if(m.find(endWord) == m.end()) return ret;

    int src = m[beginWord], dst = m[endWord], sz, u, v;

    while(!q.empty()) q.pop();
    q.push(new Node(beginWord, 0, NULL));
    m.erase(beginWord);
    int minDistance = n*2;
    bool solFound = false;

    while(!q.empty()) {
      sz = q.size();
      newWords.clear();

      for(int x=0; x<sz; x+=1) {
        Node *nodeU = q.front(); q.pop();
        string strU = nodeU->word;
        int distance = nodeU->depth;

        //cout << "-> " << strU << " " << distance << endl;
        //if(distance == 11) break;

        if(distance+1 > minDistance) {
          continue;
        }

        for(int j=0; j<wl; j+=1) {
          for(char ch='a'; ch<='z'; ch+=1) {
            if(strU[j] == ch) continue;
            char tmp = strU[j];
            strU[j] = ch;
            if(m.find(strU) != m.end()) {
              newWords.push_back(strU);
              v = m[strU];

              if(v == dst) {
                solFound = true;
                vector<string> tmp;
                tmp.push_back(strU);
                Node *tmpNode = nodeU;
                while(tmpNode != NULL) {
                  tmp.push_back(tmpNode->word);
                  tmpNode = tmpNode->prev;
                }
                reverse(tmp.begin(), tmp.end());
                ret.push_back(tmp);
                minDistance = distance + 1;
              }
              else {
                q.push(new Node(strU, distance + 1, nodeU));
              }
            }
            strU[j] = tmp;
          }
        }
      }

      if(solFound) return ret;

      sz = newWords.size();
      for(int i=0; i<sz; i+=1) {
        if(m.find(newWords[i]) != m.end()) m.erase(newWords[i]);
      }
    }

    return ret;
  }
private:
  queue<Node *> q;
  unordered_map<string, int> m;
  vector<string> newWords;
  int n, wl;

  void mapWords(string beginWord, vector<string>& wordList) {
    m.clear();
    n = 0;
    wl = beginWord.length();
    int sz = wordList.size();

    m[beginWord] = n++;
    for(int i=0; i<sz; i+=1) {
      if(m.find(wordList[i]) == m.end()) {
        m[wordList[i]] = n++;
      }
    }
  }
};