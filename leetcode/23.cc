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
	struct cmp {
		bool operator() (const pair<int, ListNode*>& lhs, const pair<int, ListNode*>& rhs) { 
			return lhs.first > rhs.first;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, cmp> heads;
		for(int i = 0; i < lists.size(); ++i) {
			if(!lists[i]) continue;
			heads.push(make_pair(lists[i]->val, lists[i]));
		}
		if(heads.empty()) return NULL;
		ListNode* node, *ret = heads.top().second;
		while(!heads.empty()) {
			node = heads.top().second;
			heads.pop();
			if(node->next) heads.push(make_pair(node->next->val, node->next));
			if(!heads.empty()) node->next = heads.top().second;
		}
		return ret;
	}
};

// simpler solution
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
