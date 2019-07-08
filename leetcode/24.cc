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
  ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *node, *temp, *next_head, *ret = head->next;
    while(head && head->next) {
      if(head->next->next) 
        node = head->next->next->next ? head->next->next->next : head->next->next;
      else 
        node = NULL;
        temp = head;
        next_head = head->next->next;
        head = head->next;
        head->next = temp;
        temp->next = node;
        head = next_head;
    }
    return ret;
  }
};
