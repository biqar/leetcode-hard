//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
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
  int maxPathSum(TreeNode* root) {
    int ret = INT_MIN;
    maxPathSumRecur(root, ret);
    return ret;
  }

  int maxPathSumRecur(TreeNode* curr, int &actual_max) {
    if(curr == nullptr) return 0;

    int l = maxPathSumRecur(curr->left, actual_max);
    int r = maxPathSumRecur(curr->right, actual_max);

    //int max_pass_through_curr = max(max(l, r) + curr->val, curr->val);
    //int max_rooted_in_curr = max(max_pass_through_curr, l + r + curr->val);
    //actual_max = max(actual_max, max_rooted_in_curr);
    actual_max = max(actual_max, max(max(max(l, r) + curr->val, curr->val), l + r + curr->val));
    //return max_pass_through_curr;
    return max(max(l, r) + curr->val, curr->val);
  }
};