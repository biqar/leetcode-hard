//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    m.clear();
    path.clear();

    int sz = tickets.size();
    for(int i=0; i<sz; i+=1) {
      m[tickets[i][0]].push(tickets[i][1]);
    }
    construct_path("JFK");
    reverse(path.begin(), path.end());
    return path;
  }
private:
  vector<string> path;
  map<string, priority_queue<string, vector<string>, greater<string>> > m;

  void construct_path(string currCity) {
    while(!m[currCity].empty()) {
      string next = m[currCity].top();
      m[currCity].pop();
      construct_path(next);
    }
    path.push_back(currCity);
  }
};