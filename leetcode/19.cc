/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
eee
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return head;
    std::vector<ListNode*> nodes;
    ListNode* temp = head;
    while(temp != NULL) nodes.push_back(temp), temp = temp->next; 
    if(n == nodes.size()) return head->next;
    if(n == 1) {
      if(nodes.size() == 1) return NULL;
      nodes[nodes.size() - 2]->next = NULL;
    }
    else
      nodes[nodes.size() -n-1]->next = nodes[nodes.size()-n+1]; 
    return head;
  }
};
