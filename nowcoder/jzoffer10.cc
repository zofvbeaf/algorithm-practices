class Solution {
public:
	int Fibonacci(int n) {
	  if(n < 2) return n;
	  int x = 0, y = 1;
    while(--n) {
      int temp = x;
      x = y;
      y += temp;
    }
    return y;
	}
};
