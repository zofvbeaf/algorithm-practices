#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 100005;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a/gcd(a, b)*b; }

int main() {
  int a, b;
  while(~scanf("%d%d", &a, &b)) {
    printf("%d\n", lcm(a, b));
  }
  return 0;
}
