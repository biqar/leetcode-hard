//
// Created by Islam, Abdullah Al Raqibul on 11/13/22.
//

struct location {
  int score;
  string name;

  location(int score, string name): score(score), name(name) {}

  bool operator<(const location &l) const {
    return score > l.score || (score == l.score && name < l.name);
  }
};

class SORTracker {
private:
  set<location> scenes;
  set<location>::iterator it;

public:
  SORTracker() {
  }

  void add(string name, int score) {
    location loc(score, name);

    if(scenes.empty()) {
      scenes.insert(loc);
      it = scenes.begin();
    }
    else {
      scenes.insert(loc);
      if(it == scenes.end() || loc < *it) {
        it--;
      }
    }
  }

  string get() {
    string ret = it->name;
    it++;
    return ret;
  }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */