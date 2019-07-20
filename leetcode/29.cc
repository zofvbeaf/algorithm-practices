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

class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor == -1 && dividend == INT_MIN) return INT_MAX;
		bool is_neg = ((dividend < 0) ^ (divisor < 0));
		long dd = dividend < 0 ? 0-(long)dividend : dividend;
		long dr = divisor < 0 ? 0-(long)divisor : divisor;
		long ans = 0;
		while(dd >= dr) {
			long temp_dr = dr, temp_res = 1;
			while(dd >= (temp_dr<<1)) {
				temp_dr <<= 1;
				temp_res <<= 1;
			}
			dd -= temp_dr;
			ans += temp_res;
		}
		return is_neg ? 0-ans : ans;
	}
};
