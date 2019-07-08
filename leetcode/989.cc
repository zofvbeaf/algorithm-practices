class Solution {
public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> ans;
    int x = 0, y = 0;
    for(int i = A.size() - 1; i >= 0; --i) {
      x = (K%10 + A[i] + y)%10;
      y = (K%10 + A[i] + y)/10;
      ans.push_back(x);
      K /= 10;
    }
    K += y;
    while(K) {
      ans.push_back(K%10);
      K /= 10;
    }
    x = ans.size();
    for(int i = 1; 2*i <= x; ++i) {
      y = ans[i-1];
      ans[i-1] = ans[x-i];
      ans[x-i] = y;
    }
    return ans;
  }
};
