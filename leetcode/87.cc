class Solution {
public:
  bool isScramble(string s1, string s2) {
    if(s1.empty() && s2.empty()) return true;
    if(s1 == s2) return true;
    if(s1.empty() || s2.empty() || s1.size() != s2.size()) return false;
    vector<int> f1(256, 0), f2(256, 0);
    for(auto c : s1) ++f1[c];
    for(auto c : s2) ++f2[c];
    for(int i = 0; i < 256; ++i) if(f1[i] != f2[i]) return false;
    for(int i = 1; i < s1.size(); ++i) 
      if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
          || (isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i)))) 
        return true;
    return false;
  }
};
