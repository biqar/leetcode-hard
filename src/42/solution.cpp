//
// Created by Islam, Abdullah Al Raqibul on 04/17/24.
//

class Solution {
public:
  int trap(vector<int>& height) {
    stack<int> sk;
    int ret = 0;
    int w, h;
    int m, l;

    for(int i=0; i<height.size(); i+=1) {
      while(!sk.empty() && height[sk.top()] < height[i]) {
        m = sk.top();
        sk.pop();
        if(sk.empty()) break;
        l = sk.top();

        w = i - l - 1;
        h = min(height[i], height[l]) - height[m];
        // cout << i << " " << l << " " << w << " " << h << endl;
        ret += (w * h);
      }
      sk.push(i);
    }
    return ret;
  }
};