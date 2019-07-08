class Solution {
public:
  int find(int c) {
    if(pa[c] == c) return pa[c];
    return pa[c] = find(pa[c]);
  }

  bool equationsPossible(vector<string>& equations) {
    for(int i = 0; i < 256; ++i) pa[i] = i;
    for(int i = 0; i < equations.size(); ++i) {
      int x = find(equations[i][0]), y = find(equations[i][3]);
      if(equations[i][1] == '=') pa[x] = y;
    }
    for(int i = 0; i < equations.size(); ++i) {
      int x = find(equations[i][0]), y = find(equations[i][3]);
      if(equations[i][1] == '!' && x == y) return false;
    }

    return true;
  }

  int pa[256];
};
