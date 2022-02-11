//
// Created by Islam, Abdullah Al Raqibul on 02/10/22.
//

class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    init(target);
    return countInSegments(0, sz - 1, 0, target);
  }

private:
  vector<int> segTree;
  int segTreeSz, sz;

  void init(vector<int>& target) {
    segTree.clear();
    sz = target.size();
    segTreeSz = sz * 4;
    segTree.resize(segTreeSz, 0);
    build(1, 0, sz - 1, target);
  }

  int build(int node, int l, int r, vector<int>& target) {
    if(l == r) {
      return segTree[node] = l;
    }
    int ln = node * 2;
    int rn = (node * 2) + 1;
    int mid = l + (r - l) / 2;
    int lIdx = build(ln, l, mid, target);
    int rIdx = build(rn, mid + 1, r, target);
    return segTree[node] = (target[lIdx] <= target[rIdx]) ? lIdx : rIdx;
  }

  int query(int node, int l, int r, int x, int y, vector<int>& target) {
    if(x > r or y < l) return -1;
    if(l >= x and r <= y) return segTree[node];
    int ln = node * 2;
    int rn = (node * 2) + 1;
    int mid = l + (r - l) / 2;
    int lIdx = query(ln, l, mid, x, y, target);
    int rIdx = query(rn, mid + 1, r, x, y, target);
    if(lIdx == -1) return rIdx;
    if(rIdx == -1) return lIdx;
    return (target[lIdx] <= target[rIdx]) ? lIdx : rIdx;
  }

  int countInSegments(int l, int r, int dx, vector<int>& target) {
    if(l > r) return 0;
    int mid = query(1, 0, sz - 1, l, r, target);
    int min = target[mid];

    int cnt = 0;
    cnt += (min - dx);
    cnt += countInSegments(l, mid - 1, min, target) + countInSegments(mid + 1, r, min, target);

    return cnt;
  }
};