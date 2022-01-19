//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return nullptr;

    int sz = lists.size();
    // we need to keep a dummy head to compare and insert to the next position of the l1
    ListNode* ret_root = new ListNode(0, lists[0]);

    for(int i=1; i<sz; i+=1) {
      ListNode* merged = ret_root;
      ListNode* curr = lists[i];

      while(curr != nullptr) {
        if(merged->next == nullptr) {
          merged->next = curr;
          break;
        }

        if(merged->next->val < curr->val) {
          merged = merged->next;
        }
        else {
          ListNode* rest_of_merged = merged->next;
          merged->next = curr;
          curr = curr-> next;
          merged->next->next = rest_of_merged;
          merged = merged->next;
        }
      }
    }

    return ret_root->next;
  }
};
