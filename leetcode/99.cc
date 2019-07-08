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
    void traverse(TreeNode* root) {
      if(!root) return;
      traverse(root->left);
      if(!first && root->val <= last->val) first = last;
      if(first && root->val <= last->val)  second = root;
      last = root;
      traverse(root->right);
    }

    void recoverTree(TreeNode* root) {
      if(!root) return;
      last = new TreeNode(INT_MIN);
      traverse(root);         
      int val = first->val;
      first->val = second->val;
      second->val = val;
    }
    TreeNode *first = NULL, *second = NULL, *last = NULL;
};
