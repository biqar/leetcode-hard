//
// Created by Islam, Abdullah Al Raqibul on 01/25/22.
//

class SummaryRanges {
private:
  vector<vector<int>> intervals;
public:
  SummaryRanges() {

  }

  void addNum(int val) {
    vector<int> tmp = {val, val};
    intervals = addInterval(intervals, tmp);
  }

  vector<vector<int>> getIntervals() {
    return intervals;
  }

  // copied from: "57. Insert Interval" (https://leetcode.com/problems/insert-interval/)
  vector<vector<int>> addInterval(vector<vector<int>>& is, vector<int>& newI) {
    vector<vector<int>> ret;
    int sz = is.size();

    if(sz == 0) {
      vector<int> tmp = {newI[0], newI[1]};
      ret.push_back(tmp);
      return ret;
    }

    for(int i=0; i<sz; i+=1) {
      vector<int> &curr = is[i];

      if(newI[1]+1 < is[i][0]) {
        ret.push_back(newI);

        for(int j=i; j<sz; j+=1) ret.push_back(is[j]);
        return ret;
      }

      else if(newI[0] > is[i][1]+1) ret.push_back(is[i]);

      else {
        newI[0] = min(newI[0], is[i][0]);
        newI[1] = max(newI[1], is[i][1]);
      }
    }

    ret.push_back(newI);
    return ret;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */