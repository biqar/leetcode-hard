//
// Created by Islam, Abdullah Al Raqibul on 09/13/22.
//

#define MAX 100005

struct disjoint_set {
  int parent, rank;
};

bool comp(const vector<int>& lft, const vector<int>& rgt) {
  return (lft[2] < rgt[2]);
}

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    init_dsd(n);
    sort(meetings.begin(), meetings.end(), comp);

    // for(auto m : meetings) cout << m[0] << " " << m[1] << " " << m[2] << endl;
    vector<int> ret;
    int psrc;
    int pu = find_set(0);
    int pv = find_set(firstPerson);
    union_by_rank(pu, pv);
    int sz = meetings.size(), i = 0;
    while(i < sz) {
      int j = i;

      // look forward for the meeting of the similar intervals
      while(j < sz && meetings[j][2] == meetings[i][2]) j+=1;

      // first merge all of them
      for(int k=i; k<j; k+=1) {
        union_by_rank(find_set(meetings[k][0]), find_set(meetings[k][1]));
      }

      // rollback those who are not connected to person-0
      for(int k=i; k<j; k+=1) {
        if(find_set(meetings[k][0]) != find_set(0)) {
          dset[meetings[k][0]].parent = meetings[k][0];
        }
        if(find_set(meetings[k][1]) != find_set(0)) {
          dset[meetings[k][1]].parent = meetings[k][1];
        }
      }
      i = j;
    }

    for(int i=0; i<n; i+=1) find_set(i);
    for(int i=0; i<n; i+=1) if(dset[i].parent == dset[0].parent) ret.push_back(i);

    return ret;
  }

private:
  struct disjoint_set dset[MAX];

  void init_dsd(int n) {
    for(int i=0; i<n; i+=1) {
      dset[i].parent = i;
      dset[i].rank = 0;
    }
  }

  /*find root of the disjoint set with path compression*/
  int find_set(int x) {
    if(x != dset[x].parent) dset[x].parent = find_set(dset[x].parent);
    return dset[x].parent;
  }

  /*union disjoint sets by rank*/
  void union_by_rank(int px, int py) {
    if(dset[px].rank < dset[py].rank) {
      dset[px].parent = py;
    }
    else if(dset[px].rank > dset[py].rank) {
      dset[py].parent = px;
    }
    else {
      dset[py].parent = px;
      dset[px].rank += 1;
    }
  }
};