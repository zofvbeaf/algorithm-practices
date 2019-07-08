class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int ans = 0;
		for(int i = 0; i < A.size(); ++i) {
	    if(K > 0){
	      if(A[i] < 0) ans -= A[i], --K;
        else {
          if(K%2 == 0) ans += A[i];
          else if(i > 0 & A[i-1] < 0 && A[i] > -A[i-1]) 
            ans += (A[i-1]*2) + A[i];
          else ans -= A[i];
          K = 0;
        }
	    }
      else ans += A[i];
		}
		return ans;
	}
};
