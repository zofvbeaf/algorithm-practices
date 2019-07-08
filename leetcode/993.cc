struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool dfs(TreeNode* root, int x, int y, int depth) {
    if(!root) return false;
		if(!px && ((root->left && root->left->val == x)
		        ||(root->right && root->right->val == x))) 
			px = root, x = depth;
		if(!py && ((root->left && root->left->val == y)
		        ||(root->right && root->right->val == y))) 
			py = root, y = depth;
    if(px && py && px != py && x == y) return true;
    return dfs(root->left, x, y, depth + 1) 
          || dfs(root->right, x, y, depth+1);
  }

  bool isCousins(TreeNode* root, int x, int y) {
    if(!root || root->val == x || root->val == y) 
      return false;
    px = py = NULL;
    return dfs(root, x, y, 0);
  }
  TreeNode *px, *py;
};
