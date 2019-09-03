#include <bits/stdc++.h>

using namespace std;

void search(string& ans, string& s, string& t, string& now, int start, int n) {
  cout << now << " : " << ans << " : " << start << endl;
  if(now == t && !ans.empty()) {
    cout << now << " : " << ans << " : " << start << endl;
    for(int i = start; i < n; ++i) ans += " d";
    cout << ans.substr(1) << endl;
    for(int i = start; i < n; ++i) ans.pop_back(), ans.pop_back();
    return;
  } 
  else if(start >= n || now.size() > t.size()) return;
  ans += " d";
  cout << now << " : " << ans << endl;
  search(ans, s, t, now, start+1, n);
  ans.pop_back();
  ans.pop_back();
  ans += " l";
  now = s[start] + now;
  cout << now << " : " << ans << endl;
  search(ans, s, t, now, start+1, n);
  now.pop_back();
  ans.pop_back();
  ans.pop_back();
  ans += " r";
  now = now + s[start];
  cout << now << " : " << ans << endl;
  search(ans, s, t, now, start+1, n);
  now.substr(1);
  ans.pop_back();
  ans.pop_back();
}

int main() {
  freopen("in.txt", "r", stdin);
  std::ios::sync_with_stdio(false);
  int T;
  string s, t, ans, now;
  cin >> T;
  while(T--) {
    cout << "{" << endl;
    cin >> s >> t;
    ans.clear();
    now.clear();
    search(ans, s, t, now, 0, s.size());
    cout << "}" << endl;
  }
  return 0;
}