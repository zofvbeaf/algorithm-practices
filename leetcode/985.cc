class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> ans;
    int sum = 0, x = 0;
    for(int i = 0; i < A.size(); ++i) if(A[i]%2 == 0) sum += A[i];

    for(int i = 0; i < queries.size(); ++i) {
      x = A[queries[i][1]] + queries[i][0];
      if(A[queries[i][1]]%2 == 0 && x%2) sum -= A[queries[i][1]];
      else if(A[queries[i][1]]%2 && x%2 == 0) sum += x;
      else if(A[queries[i][1]]%2 == 0 && x%2 == 0) sum += queries[i][0];
      A[queries[i][1]] = x;
      ans.push_back(sum);
    }
    return ans;
  }
};
