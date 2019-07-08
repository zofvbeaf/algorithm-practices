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
	vector<int> postorderTraversal(TreeNode* root) {
	  stack<TreeNode*> nodes;	
	  vector<int> ans;
	  if(root) nodes.push(root);
	  while(!nodes.empty()) {
	    TreeNode* top = nodes.top();
      if(top->left) {
	      nodes.push(top->left);
	      top->left = NULL;
      }
      else if(top->right) {
	      nodes.push(top->right);
	      top->right = NULL;
	    }
      else {
        ans.push_back(top->val);
        nodes.pop();
      }
	  }
		return ans;
	}
};
