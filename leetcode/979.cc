/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int dfs(TreeNode* root) {
    if(!root) return 0;
    root->val += dfs(root->left) + dfs(root->right);
    ans += abs(root->val - 1);
    return root->val - 1;
  }

	int distributeCoins(TreeNode* root) {
	  ans = 0;
	  dfs(root);	
	  return ans;
	}
	int ans;
};
