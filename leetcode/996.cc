class Solution {
public:
	int numSquarefulPerms(vector<int>& A) {
    std::sort(A.begin(), A.end());
		for(int i = 0; i < A.size(); ++i) {
		  if(unused_num.count(A[i])) ++unused_num[A[i]];
      else unused_num[A[i]] = 1;

      for(int j = i+1; j < A.size(); ++j) {
        int x = (int)std::sqrt((double)(A[i] + A[j]));
        if(x*x == A[i] + A[j]) {
          squareful_pair[A[i]].push_back(A[j]);
          squareful_pair[A[j]].push_back(A[i]);
        }
      }
    }
    res = 0;
    bfs(A);
    return res;
	}
	void bfs(vector<int>& A) {
	  if(ans.size() == A.size()) { 
	    ++res;
	    return;
    }
	  
		for(int i = 0; i < A.size(); ++i) {
		  if(i && A[i] == A[i-1]) continue;
		  if(ans.empty() 
		      || (squareful_pair(ans.back()).find(A[i])
		          && unused_num[A[i]])) {
		    ans.push_back(A[i]);
		    --unused_num[A[i]];
		    bfs(A);
		    ans.pop_back();
		    ++unused_num[A[i]];
      }
		}
	
	}

  std::map<int, std::vector<int> > squareful_pair;
  std::map<int, int> unused_num;
  std::vector<int> ans;
  int res;
};

