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
  
  struct Point {
    int val;
    int x;
    int y;
    Point(int v, int a, int b): val(v), x(a), y(b) {}
    bool operator<(const Point& rhs) {
      if(x == rhs.x) {
        if(y == rhs.y) return val < rhs.val;
        else return y > rhs.y;
      }
      return x < rhs.x;
    }
  };

  void dfs(TreeNode* root, int x, int y) {
    if(!root) return;
    points.push_back(Point(root->val, x, y));
    dfs(root->left, x-1, y-1);
    dfs(root->right, x+1, y-1);
  }

  vector<vector<int>> verticalTraversal(TreeNode* root) {
    dfs(root, 0, 0);  
    vector<vector<int>> res;
    vector<int> temp;

    sort(points.begin(), points.end());

    int x = 0;
    for(int i = 0; i < points.size(); ++i) {
      if(temp.empty()) { 
        temp.push_back(points[i].val);
        x = points[i].x;
      }
      else if(points[i].x != x) {
        res.push_back(temp);
        temp.clear();
        temp.push_back(points[i].val);
        x = points[i].x;
      }
      else temp.push_back(points[i].val);
    }
    if(!temp.empty()) res.push_back(temp);
    return res;
  }
  vector<Point> points;
};
