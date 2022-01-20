//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    s += " ";
    int num = 0, len = s.length(), sign = 1, ret = 0;

    for(int i=0; i<len; i+=1) {
      if(s[i] >= '0' && s[i] <= '9') {
        num = 0;
        while((s[i] >= '0' && s[i] <= '9') && i < len) {
          num *= 10;
          num += (s[i] - '0');
          i += 1;
        }
        //cout << sign << " " << num << endl;
        i -= 1;
        ret += (sign * num);
      }
      else if(s[i] == '+') {
        sign = 1;
      }
      else if(s[i] == '-') {
        //cout << "entered here ...\n";
        sign = -1;
      }
      else if(s[i] == '(') {
        st.push(ret);
        st.push(sign);
        sign = 1;
        ret = 0;
      }
      else if(s[i] == ')') {
        sign = st.top(); st.pop();
        int last = st.top(); st.pop();
        ret = last + (sign * ret);
      }
    }
    return ret;
  }
};