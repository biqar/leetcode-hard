//
// Created by Islam, Abdullah Al Raqibul on 11/13/22.
//

class MedianFinder {
private:
  priority_queue<int> mxq;
  priority_queue<int,vector<int>,greater<int> > mnq;
  int n;

public:
  MedianFinder() {
    n = 0;
  }

  void addNum(int num) {
    mxq.push(num);

    if(mxq.size() > mnq.size() + 1) {
      mnq.push(mxq.top());
      mxq.pop();
    }

    if(mxq.size() && mnq.size()) {
      if(mxq.top() > mnq.top()) {
        int tmp = mxq.top();

        mxq.pop();
        mxq.push(mnq.top());

        mnq.pop();
        mnq.push(tmp);
      }
    }

    n += 1;
  }

  double findMedian() {
    if(n % 2) return mxq.top();
    return (double) (mxq.top() + mnq.top()) / 2;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */