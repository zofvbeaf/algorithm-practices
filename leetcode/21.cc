/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1 || !l2) return l1 ? l1 : l2;
    ListNode *ret, *node;
    if(l1->val < l2->val) node = l1, l1 = l1->next;
    else node = l2, l2 = l2->next;
    ret = node;
    while(l1 && l2) {
      if(l1->val < l2->val) node->next = l1, l1 = l1->next;
      else node->next = l2, l2 = l2->next;
      node = node->next;
    }
    if(!l1)  node->next = l2; 
    else if(!l2)  node->next = l1; 
    return ret;
  }
};
