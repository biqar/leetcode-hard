//
// Created by Islam, Abdullah Al Raqibul on 01/31/22.
//

class FreqStack {
public:
  map<int, int> m;
  map<int, stack<int>> rm;
  int mxFreq;

  FreqStack() {
    mxFreq = 0;
  }

  void push(int x) {
    int freq = (m.find(x) == m.end()) ? 0 : m[x];
    freq += 1;

    m[x] = freq;
    rm[freq].push(x);
    if(freq > mxFreq) mxFreq = freq;
  }

  int pop() {
    int x = rm[mxFreq].top();
    rm[mxFreq].pop();

    m[x] -= 1;
    if(rm[mxFreq].size() == 0) mxFreq -= 1;
    return x;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */