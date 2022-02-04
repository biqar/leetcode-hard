//
// Created by Islam, Abdullah Al Raqibul on 02/04/22.
//

//MLE Solution
/*class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0; i<n; i+=1) {
            vec.push_back(make_pair(parent[i], i));
        }
        sort(vec.begin(), vec.end());
        for(int i=1; i<n; i+=1) {
            par[i] = par[parent[i]];
            par[i].push_back(parent[i]);
        }
        nodes = n;
    }

    int getKthAncestor(int node, int k) {
        // int i = 0;
        // while(par[node] != -1) {
        //     node = par[node];
        //     i += 1;
        //     if(i == k) break;
        // }

        //return -1;
        int sz = par[node].size();
        return sz < k ? -1 : par[node][sz-k];
    }
private:
    int nodes;
    vector<pair<int, int>> vec;
    vector<int> par[50005];
};*/

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

class TreeAncestor {
public:
  TreeAncestor(int n, vector<int>& parent) {
    //
    memset(dp, -1, sizeof(dp));
    // for(int i=0; i<n; i+=1) {
    //     for(int j=0; j*j<=n; j+=1) {
    //         dp[i][j] = -1;
    //     }
    // }

    for(int i=0; i<n; i+=1) dp[i][0] = parent[i];

    for(int i=0; i<n; i+=1) {
      for(int h=1; h*h<=n; h+=1) {
        if(dp[i][h-1] != -1) dp[i][h] = dp[dp[i][h-1]][h-1];
      }
    }
    nodes = n;
  }

  int getKthAncestor(int node, int k) {
    for(int i=log2(nodes); i>=0; i-=1) {
      int pow_of_2 = (1 << i);
      if(node != -1 && pow_of_2 <= k) {
        node = dp[node][i];
        k = k - pow_of_2;
      }
    }

    return node;
  }
private:
  int nodes;
  int dp[50005][225];
};