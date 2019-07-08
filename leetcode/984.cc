class Solution {
public:
  string strWithout3a3b(int A, int B) {
    string ans;
    int n = A < B ? A : B;
    int m = A < B ? B-A : A-B;
    char c = A < B ? 'b' : 'a';
    if(m > 0) ans += c, --m;
    for(int i = 0; i < n; ++i) {
      ans += "ab";
      if(m > 0) ans += c, --m;
    }
    if(m > 0 && c == 'b') ans = 'b' + ans;
    else while(m > 0) ans += c, --m;
    return ans;
  }
};
