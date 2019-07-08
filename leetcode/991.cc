class Solution {
public:
  int brokenCalc(int X, int Y) {
    if(X >= Y) return X-Y;
    int ans = 0;
    while(X < Y) {
      X *= 2;
      ++ans;
    }
    X -= Y;
    Y = ans;
    while(X && Y) {
      ans += X%2;
      X /= 2;
      --Y;
    }
    return ans+X;
  }
};
