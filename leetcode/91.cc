class Solution {
public:
  int numDecodings(string s) {
    if(s.empty()) return 0;
    vector<int> f(s.size(), 0);
    f[0] = 1;
    for(int i = 1; i < s.size(); ++i) 
      f[i] = f[i-1] + (s[i] != '0') + (s[i-1] != '0' && atoi(s.substr(i-1, 2).c_str()) <= 26);
    return f.back();
  }
};
