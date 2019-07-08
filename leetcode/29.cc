class Solution {
public:
  int search(int dividend, int divisor, int x, int base_divisor) {
    if(dividend < base_divisor) return 0;
    if(dividend < divisor + divisor) 
      return x + search(dividend-divisor, base_divisor, 1, base_divisor);
    else if(dividend == divisor) return x+x;
    return search(dividend, divisor+divisor, x+x, base_divisor);
  }

  int divide(int dividend, int divisor) {
    if(!dividend) return 0;
    int flag = 0;
    if(dividend < 0 && divisor > 0) dividend = 0-dividend, flag = 1;
    else if(dividend > 0 && divisor < 0) divisor = 0-divisor, flag = 2;
    if(dividend < divisor) return 0;
    else if(dividend == divisor) return 1;
    int ans = search(dividend, divisor, 1, divisor);
    return flag ? 0-ans : ans;
  }
};


