class Solution {
public:
	int find(unordered_map<int, int>& head, int x) {
		if(head[x] == x) return x;
		return (head[x] = find(head, head[x]));
	}

	void add(unordered_map<int, int>& count, unordered_map<int, int>& head, int x) {
		int pre = head.count(x-1), next = head.count(x+1);
		if(!pre && !next) {
			count[x] = 1;
			head[x] = x;
		}
		else if(pre && !next) {
			head[x] = find(head, x-1);
			++count[head[x]];
		} 
		else if(!pre && next) {
			head[x] = find(head, x+1);
			++count[head[x]];
		}
		else {
			int prehead = find(head, x-1); 
			int nexthead = find(head, x+1); 
			count[prehead] += count[nexthead] + 1;
			head[nexthead] = head[x] = prehead;
		}
	}

	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> count;
		unordered_map<int, int> head;
		for(int i = 0; i < nums.size(); ++i) {
			if(!head.count(nums[i])) {
				add(count, head, nums[i]);         
			}
		}
		int ans = 0;
		for(auto i : count) ans = max(ans, i.second);
		return ans;
	}
};
