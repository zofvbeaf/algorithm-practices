class Solution {
public:
  int maxTurbulenceSize(vector<int>& A) {
    if(A.size() < 2) return A.size();
    else if(A.size() == 2) return A[0] == A[1] ? 1 : 2;
    int ans = 0, m = 0, x = 0;
    for(int i = 1; i < A.size()-1; ++i) {
      if(A[i-1] != A[i] || A[i+1] != A[i]) x = 1;
      if((A[i-1] > A[i] && A[i+1] > A[i])
        || (A[i-1] < A[i] && A[i+1] < A[i])) ++m;
      else 
        ans = max(ans, m), m = 0;
    }
    ans = max(ans, m);
    if(!ans) return x + 1;
    else return ans + 2;
  }
};
