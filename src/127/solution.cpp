//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    mapWords(beginWord, wordList);
    if(m.find(endWord) == m.end()) return 0;

    int src = m[beginWord], dst = m[endWord], sz, u, v;
    queue<pair<string, int> > q;
    q.push(make_pair(beginWord, 1));
    m.erase(beginWord);

    while(!q.empty()) {
      string strU = q.front().first;
      int distance = q.front().second;
      q.pop();

      for(int j=0; j<wl; j+=1) {
        for(char ch='a'; ch<='z'; ch+=1) {
          if(strU[j] != ch) {
            char tmp = strU[j];
            strU[j] = ch;
            if(m.find(strU) != m.end()) {
              v = m[strU];

              if(v == dst) {
                return distance + 1;
              }

              q.push(make_pair(strU, distance + 1));
              m.erase(strU);
            }
            strU[j] = tmp;
          }
        }
      }
    }

    return 0;
  }
private:
  map<string, int> m;
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