//
// Created by Islam, Abdullah Al Raqibul on 07/31/22.
//

#define MAX 100005
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))

class Solution {
public:
  void tarjan(int u, vector<int>& edges) {
    Index[u] = Lowlink[u] = idx++;
    Stack[top++] = u;
    Onstack[u] = 1;

    int v = edges[u];
    if(v != -1) {
      if(Index[v]==-1) {
        tarjan(v, edges);
        Lowlink[u] = min(Lowlink[u], Lowlink[v]);
      }
      else if(Onstack[v]) Lowlink[u] = min(Lowlink[u], Index[v]);
    }

    if(Lowlink[u] == Index[u]) {
      components++;
      do {
        v = Stack[--top];
        Onstack[v] = 0;
        Component[v] = components;
      } while(u != v);
    }
  }

  int longestCycle(vector<int>& edges) {
    int ret = -1;
    int n = edges.size();
    components = top = idx = 0;
    SET(Index); CLR(Onstack); MEM(Lowlink, 0x3f);
    for(int i = 0; i < n; i++) if(Index[i]==-1) tarjan(i, edges);

    map<int, int> mp;
    for(int i=0; i<n; i+=1) {
      mp[Component[i]] += 1;
      if(mp[Component[i]] > 1 && mp[Component[i]] > ret) ret = mp[Component[i]];
    }

    return ret;
  }

private:
  int Stack[MAX], top;
  int Index[MAX], Lowlink[MAX], Onstack[MAX];
  int Component[MAX];
  int idx, components;
};