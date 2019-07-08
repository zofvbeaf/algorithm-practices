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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *ans = NULL, *temp = head;
		vector<ListNode*> nodes;
		int x = k;
		while(temp) {
			x = k;
			nodes.clear();
			while(temp && x--) nodes.push_back(temp), temp = temp->next;
			if(nodes.size() < k) {
				if(head != nodes[0]) head->next = nodes[0];
				else head = nodes[0];
				break;
			}
			else {
				if(head != nodes[0]) head->next = nodes[k-1], head = nodes[0];
				else head = nodes[0];
			}
			if(!ans) ans = nodes[k-1];
			for(int i = k-2; i >=0; --i) nodes[i+1]->next = nodes[i];
			if(!temp) nodes[0]->next = NULL;
		}
		return ans ? ans : head;
	}
};

// simpler O(1) space solution
// 11min
class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0, s = 0, e = height.size()-1;
		while(s < e) {
			ans = max(ans, (e-s)*(min(height[s], height[e])));
			if(height[s] < height[e]) {
				int hs = height[s];
				while(s < e && height[s] <= hs) ++s; // <=
			}
			else {
				int es = height[e];
				while(s < e && height[e] <= es) --e;
			}
		}
		return ans;
	}
};
