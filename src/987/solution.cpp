//
// Created by Islam, Abdullah Al Raqibul on 02/01/22.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    nodeMap.clear();
    dfs(root, 0, 0);
    vector<vector<int>> res;
    for (auto nm : nodeMap) {
      sort(nm.second.begin(), nm.second.end());
      vector<int> cols;
      for (auto p : nm.second)
        cols.push_back(p.second);
      res.push_back(cols);
    }
    return res;
  }
private:
  map<int, vector<pair<int, int>>> nodeMap; // x ==> (-y, value)
  void dfs(TreeNode* root, int x, int y) {
    if (!root) return;
    nodeMap[x].emplace_back(-y, root->val);
    dfs(root->left, x - 1, y - 1);
    dfs(root->right, x + 1, y - 1);
  }
};


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void verticalTraversal(TreeNode* root, int vo, map<int, vector<int>> &m) {
//         if(root == NULL) return;
//         m[vo].push_back(root->val);
//         verticalTraversal(root->left, vo-1, m);
//         verticalTraversal(root->right, vo+1, m);
//     }

//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int, vector<int>> m;
//         vector<vector<int>> ret;

//         //verticalTraversal(root, 0, m);

//         queue<pair<int, TreeNode*>> q;
//         q.push(make_pair(0, root));
//         while(!q.empty()) {
//             int vo = q.front().first;
//             TreeNode* curr = q.front().second;
//             q.pop();

//             if(curr == NULL) continue;
//             m[vo].push_back(curr->val);

//             q.push(make_pair(vo-1, curr->left));
//             q.push(make_pair(vo+1, curr->right));
//         }

//         for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
//             ret.push_back(it->second);
//         }

//         return ret;
//     }
// };