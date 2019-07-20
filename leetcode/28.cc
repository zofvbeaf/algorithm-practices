// kmp
class Solution {
public:
    // s    :       A   B   C   D   A   B   D
    // next :   -1  0   0   0  -1   0   2   0 next 的第 0 位被用来做
    // next :   -1  0   0   0   0   1   2   0 next 的第 0 位被用来做
    // eg. A B C D A B C D B D E
    void kmp_make_next(string& pattern, vector<int>& next) {
      int len = pattern.size();
      next.resize(len+1); // need default to be 0
      int i = 0, j = -1;
      next[0] = -1;
      while(i < len) {
        if(j == -1 || pattern[i] == pattern[j]) {
          ++i, ++j;
          next[i] = pattern[i] == pattern[j] ? next[j] : j;
        }
        else {
          j = next[j];
        } 
      }
    }
  
    int kmp_find(string& s, string& p, vector<int>& next) {
      int i = 0, j = 0;
      while(s[j]) {
        if(i == -1 || p[i] == s[j]) ++i, ++j;
        else i = next[i];
        if(i == p.size()) return j-p.size();
      }
      return -1;
    }
  
    int strStr(string haystack, string needle) {
      int n = haystack.size(), m = needle.size();
      if(!m) return 0;
      else if(!n) return -1;
      vector<int> next;
      kmp_make_next(needle, next);
      return kmp_find(haystack, needle, next);
    }
};
