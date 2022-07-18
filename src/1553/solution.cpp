//
// Created by Islam, Abdullah Al Raqibul on 07/18/22.
//

class Solution {
public:
  int minDaysRecur(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(m.find(n) != m.end()) return m[n];

    int ret = 100000000;
    if(n%2 == 0) ret = min(ret, 1 + minDaysRecur(n / 2));
    if(n%2 == 1) ret = min(ret, 2 + minDaysRecur(n / 2));
    if(n%3 == 0) ret = min(ret, 1 + minDaysRecur(n / 3));
    if(n%3 == 1) ret = min(ret, 2 + minDaysRecur(n / 3));
    if(n%3 == 2) ret = min(ret, 3 + minDaysRecur(n / 3));
    return m[n] = ret;
  }

  int minDays(int n) {
    m.clear();
    return minDaysRecur(n);
  }

private:
  unordered_map<int, int> m;
};