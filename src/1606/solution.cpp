//
// Created by Islam, Abdullah Al Raqibul on 09/07/22.
//

struct Server {
  // note: it'a a trap here!
  // there will be 10^5 jobs with (10^9) as the start/end time
  // declaring free_at as 32-bit int would overflown
  long long free_at;
  int room_id;

  Server() {}
  Server(long long free_at, int room_id) : free_at(free_at), room_id(room_id) { }
};

struct CompareServers {
  bool operator()(Server const& r1, Server const& r2) {
    if(r1.free_at == r2.free_at) return r1.room_id > r2.room_id;
    return r1.free_at > r2.free_at;
  }
};

bool compmeetings(vector<int> const& m1, vector<int> const& m2) {
return m1[0] < m2[0];
}

class Solution {
public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    // priority queue will track the occupied rooms with lowest free_at and room-id order
    priority_queue<Server, vector<Server>, CompareServers> q;
    vector<int> jcount(k, 0);
    set<int> available;
    int n = arrival.size();

    // all the servers will be available at the beginning
    for(int i=0; i<k; i+=1) available.insert(i);

    for(int i=0; i<n; i+=1) {
      // first make the servers available that have `free_at` before this job's start-time
      while(!q.empty() && q.top().free_at <= arrival[i]) {
        available.insert(q.top().room_id);
        q.pop();
      }

      // if there is no available servers, drop the job
      if(available.size()) {
        // looking up for the available server from (i%k) and upper
        auto it = available.lower_bound(i%k);
        if (it == available.end()) {
          // wrapping around the list
          it = available.begin();
        }
        q.push(Server(arrival[i] + load[i], *it));
        jcount[*it] += 1;
        available.erase(it);
      }
    }

    vector<int> ret;
    int mx = *max_element(jcount.begin(), jcount.end());
    for(int i=0; i<k; i+=1) if(jcount[i] == mx) ret.push_back(i);
    return ret;
  }
};