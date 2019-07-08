class Solution {
public:
  bool check(string s) {
    int n = s.size();
    for(int i = 0, j = n-1; i < j; ++i, --j)
      if(s[i] != s[j]) return false;
    return true;
  }

  void search(vector<string>& temp, string s) {
    for(int i = 0; i < s.size(); ++i) {
      string subs = s.substr(0, i+1);
      if(check(subs)) {
        temp.push_back(subs);
        if(i == s.size()-1) ans.push_back(temp);
        else search(temp, s.substr(i+1));
        temp.pop_back();
      }
    }
  }

	vector<vector<string>> partition(string s) {
    vector<string> temp;
    search(temp, s);
    return ans;
	}
	vector<vector<string>> ans;
};
