//
// Created by Islam, Abdullah Al Raqibul on 06/16/22.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode *node, TreeNode *par) {
    if (node == nullptr) return;

    dfs(node->left, node);
    dfs(node->right, node);

    if ((par == nullptr && covered.find(node) == covered.end()) ||
        covered.find(node->left) == covered.end() ||
        covered.find(node->right) == covered.end()) {
      ans++;
      covered.insert(node);
      covered.insert(par);
      covered.insert(node->left);
      covered.insert(node->right);
    }
  }

  int minCameraCover(TreeNode* root) {
    ans = 0;
    covered.insert(nullptr);

    dfs(root, nullptr);
    return ans;
  }

private:
  int ans;
  unordered_set<TreeNode *> covered;
};