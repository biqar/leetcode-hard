//
// Created by Islam, Abdullah Al Raqibul on 08/07/22.
//

class Solution {
public:
  int countVowelPermutation(int n) {
    long long a = 1, e = 1, i = 1, o = 1, u = 1, mod = (1e9) + 7;
    long long a2, e2, i2, o2, u2;

    for(int j=2; j<=n; j+=1) {
      a2 = (e + i + u) % mod;
      e2 = (a + i) % mod;
      i2 = (e + o) % mod;
      o2 = (i) % mod;
      u2 = (i + o) % mod;

      a = a2, e = e2, i = i2, o = o2, u = u2;
    }

    return (a + e + i + o + u) % mod;
  }
};