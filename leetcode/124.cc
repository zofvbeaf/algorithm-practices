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
  int traverse(TreeNode* root) {
	  if(!root)	return 0;
	  int x = traverse(root->left), y = traverse(root->right);
	  ans = max(ans, max(root->val+x+y, max(root->val, max(root->val+x, root->val+y))));
	  return max(root->val, max(root->val+x, root->val+y));
  }
	int maxPathSum(TreeNode* root) {
	  ans = 0;
	  traverse(root);
	  return ans;
	}
	int ans;
};
