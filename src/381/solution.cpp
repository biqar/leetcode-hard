//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class RandomizedCollection {
public:
  /** Initialize your data structure here. */
  RandomizedCollection() {
    srand(time(NULL));
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val) {
    mp[val].push_back(vec.size());
    vec.push_back(make_pair(val, mp[val].size()-1));

    return mp[val].size() > 1 ? false : true;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val) {
    if(mp.find(val) == mp.end()) return false;

    int pos = mp[val].back();
    mp[val].pop_back();

    pair<int, int> last = vec.back();

    // Case: vector `vec` contains `val` at `pos`
    if(last.first != val){
      vec[pos] = last;
      mp[last.first][last.second] = pos;
    }

    if(mp[val].size() == 0) mp.erase(val);
    vec.pop_back();
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    int rand_pos = rand() % vec.size();
    return vec[rand_pos].first;
  }

private:
  // map[val] will keep the positions `pos` in vector `vec`, where vec[pos] = val
  map<int, vector<int>> mp;

  // pair<`val`, position in map for value `val`>
  vector<pair<int, int>> vec;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */