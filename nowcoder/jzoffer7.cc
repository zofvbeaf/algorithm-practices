/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* solve(vector<int>& pre, vector<int>& vin,
                  int pstart, int pend, int vstart, int vend) {
    if(pstart > pend || vstart > vend)
      return nullptr;
    TreeNode* root = new TreeNode(pre[pstart]); 
    int vroot_pos = vstart;
    while(vroot_pos <= vend) {
      if(vin[vroot_pos] == pre[pstart]) 
        break;
      else 
        vroot_pos++;
    }
    root->left = solve(pre, vin, pstart+1, pstart+vroot_pos-vstart, vstart, vroot_pos-1);
    root->right = solve(pre, vin, pend-(vend-vroot_pos)+1, pend, vroot_pos+1, vend); 
    return root;
  }

	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.empty() || vin.empty() || pre.size() != vin.size())
			return nullptr;
    return solve(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
	}
};

