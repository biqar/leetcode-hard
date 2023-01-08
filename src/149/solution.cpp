//
// Created by Islam, Abdullah Al Raqibul on 1/8/23.
//

class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int sz = points.size();
    int ret = 1;
    // map<pair<int64_t, int64_t>, int> mp;
    unordered_map<double, int> mp;

    for(int i=0; i<sz; i+=1) {
      int64_t slope, c;
      for(int j=i+1; j<sz; j+=1) {
        if(points[i][0] == points[j][0]) {
          slope = -90;
          // c = -1;
        }
        else {
          slope = (int64_t) (((double) (points[j][1] - points[i][1]) / (double) (points[j][0] - points[i][0])) * 10e6);
          // c = (int64_t) (((double) points[j][1] - ((points[j][1] - points[i][1]) * (double) points[j][0]) / (double) (points[j][0] - points[i][0])) * 10e6);
        }
        // auto tmp = make_pair(slope, c);
        auto tmp = slope;
        mp[tmp] += 1;
        // cout << i << " " << j << ": " << slope << " " << c << " " << mp[tmp] + 1 << setprecision(40) << endl;
        ret = max(ret, mp[tmp] + 1);
      }
      mp.clear();
    }

    return ret;
  }
};