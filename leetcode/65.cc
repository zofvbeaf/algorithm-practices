class Solution {
public:
  bool isNumber(string s) {
    int p = 0, n = s.size(); 
    bool point = false;
    while(p < n && s[p] == ' ') ++p;
    if(p >= n) return false;
    if(s[p] == '-' || s[p] == '+') ++p;
    if(p >= n) return false;
    if(s[p] == '.') ++p, point = true;
    if(p >= n) return false;
    if(s[p] < '0' || s[p] > '9') return false;
    while(p < n && s[p] >= '0' && s[p] <= '9') ++p;
    if(p >= n) return true;
    if(!point && s[p] == '.') ++p;
    if(p >= n) return true;
    while(p < n && s[p] >= '0' && s[p] <= '9') ++p;
    if(((s[p-1] >= '0' && s[p-1] <= '9') || s[p-1] == '.') && s[p] == 'e') { 
      ++p;
      if(p >= n) return false;
      if(s[p] == '-' || s[p] == '+') ++p;
      if(p >= n || s[p] < '0' || s[p] > '9') return false;
    }
    while(p < n && s[p] >= '0' && s[p] <= '9') ++p;
    while(p < n && s[p] == ' ') ++p;
    return p == n;
  } 
};

