class Solution {
public:
	int minKBitFlips(vector<int>& A, int K) {
	  int ans = 0;
		for(int i = 0; i+K <= A.size(); ++i) {
      if(!A[i]) {
        ++ans;
        for(int j = i; j < i+K; ++j)
          A[j] = 1 - A[j];
      }
    }
		for(int i = 0; i < A.size(); ++i) 
		  if(!A[i]) return -1;
		return ans;
	}
};
