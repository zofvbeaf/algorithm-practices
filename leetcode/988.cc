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
  void bfs(TreeNode* root) {
    if(!root) return;

    now_seq.push_back(root->val);

    if(root->left == NULL && root->right == NULL) {
      bool flag = true;
      if(now_seq.size() <= min_seq.size()) {
        for(int i = now_seq.size()-1, j = min_seq.size()-now_seq.size(); i >= 0; --i) {
          if(now_seq[i] < min_seq[i+j]) break;
          if(now_seq[i] > min_seq[i+j]) {
            flag = false;
            break;
          }
        }
      }
      else if(now_seq.size() > min_seq.size()) {
        for(int i = min_seq.size()-1, j = now_seq.size()-min_seq.size(); i >= 0; --i) {
          if(now_seq[i+j] < min_seq[i]) break;
          if(now_seq[i+j] > min_seq[i]) {
            flag = false;
            break;
          }
        }
      }
      if(flag) {
        min_seq.clear();
        min_seq = now_seq;
      }
    }
    else {
      bfs(root->left);
      bfs(root->right);
    } 
    now_seq.pop_back();
  }

  string smallestFromLeaf(TreeNode* root) {
    string ans;
    bfs(root); 
    for(int i = min_seq.size()-1; i >= 0; --i) 
      ans += (char)(min_seq[i] + 'a');
    return ans;
  }

  vector<int> min_seq;
  vector<int> now_seq;
};
