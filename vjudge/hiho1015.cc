#include <bits/stdc++.h>

using namespace std;

class KMP {
public:
  KMP(string& p, string& s) : pattern_(p), source_(s) { }
  
  void init() { // make next
    int len = pattern_.size();
    next_.clear();
    next_.resize(len+1, 0);
    int i = 0, j = -1;
    next_[0] = -1;
    while(i < len) {
      if(j == -1 || pattern_[i] == pattern_[j]) {
        ++i, ++j;
        next_[i] = (pattern_[i] == pattern_[j]) ? next_[j] : j;
      }
      else 
        j = next_[j];
    }
  }

  int find() { // 返回出现的次数
    int i = 0, j = 0, cnt = 0;
    while(j < source_.size()) {
      if(i == -1 || pattern_[i] == source_[j]) ++i, ++j;
      else i = next_[i];
      if(i == pattern_.size()) ++cnt;
    }
    return cnt;
  }
private:
  string pattern_;
  string source_;
  vector<int> next_;
};

int main() {
  std::ios::sync_with_stdio(false);
  string p, s;
  vector<int> next;
  int n, ans;
  cin >> n;
  while(n--) {
    cin >> p >> s;
    KMP kmp(p, s);
    kmp.init();
    cout << kmp.find() << endl;
  }
  return 0;
}