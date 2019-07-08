class Solution {
public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    ans = 0;
    for(int i = 0; i < A.size(); ++i) {
      memset(distinct_nums, 0, sizeof(int)*20005);
      for(int j = i; j < A.size(); ++j) {
        if(distinct_nums.size() < K) {
          distinct_nums.insert(A[j]);
          ans += (distinct_nums.size() == K);
        }
        else if(distinct_nums.count(A[j])) ++ans;
        else break;
      }
    }
    return ans;
  }
  int distinct_nums[20005];
  int ans;
};
