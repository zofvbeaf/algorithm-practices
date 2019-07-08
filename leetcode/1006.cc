class Solution {
public:
  int clumsy(int N) {
    int x = 0, y = N;
    bool first = true;
    for(int i = N-1, j = 0; i > 0; --i, j++) {
      if(j%4 == 0) y *= i;
      else if(j%4 == 3) {
        y /= i;
        if(!first) y = last - y, first = false;
        else if(first) last = y;
      }
      else if(j%4 == 2) y += i;
    }
    if(z%4) y += last;
  }
};
