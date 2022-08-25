//
// Created by Islam, Abdullah Al Raqibul on 08/25/22.
//

class Solution {
public:
  string spell_out(string& curr, string& sticker) {
    string ret = "";
    int i = 0;
    bool found;
    for(char ch : curr) {
      found = false;
      while(i<sticker.length() && sticker[i] <= ch) {
        if(sticker[i++] == ch) {
          found = true;
          break;
        }
      }

      if(!found) ret += ch;
    }

    return ret;
  }

  int minStickers(vector<string>& stickers, string target) {
    int n = stickers.size();

    for(int i=0; i<n; i+=1) {
      sort(stickers[i].begin(), stickers[i].end());
    }
    sort(stickers.begin(), stickers.end());
    sort(target.begin(), target.end());

    queue<pair<string, int>> q;
    set<string> vis;
    q.push(make_pair(target, 0));
    vis.insert(target);
    pair<string, int> u;
    string v;
    while(!q.empty()) {
      u = q.front();
      q.pop();

      if(u.first == "") return u.second;

      for(int i=0; i<n; i+=1) {
        v = spell_out(u.first, stickers[i]);

        if(vis.find(v) == vis.end()) {
          vis.insert(v);
          q.push(make_pair(v, u.second + 1));
        }
      }
    }

    return -1;
  }
};