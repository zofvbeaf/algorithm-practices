// luogu-judger-enable-o2
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 50;
int n, m;
char str[maxn];
long long ans, s[maxn];

void solve(char A, char B, char C) {
    int cnt = 0;
    long long sum = 0;
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i ++) {
        s[i + 1] = s[i];
        if (str[i] == C) s[i + 1] ++;
    }
    for (int i = 0; i < n; i ++) {
        if (str[i] == A) {
            cnt ++;
            sum += s[i + 1];
        } else if (str[i] == B) {
            ans += s[i + 1] * cnt - sum;
        }
        if (i >= m && str[i - m] == A) {
            cnt --;
            sum -= s[i - m + 1];
        }
    }
}

void work() {
    scanf("%d", &m);
    m /= 2;
    scanf("%s", str);
    n = strlen(str);
    solve('H', 'I', 'O');
    solve('H', 'O', 'I');
    solve('O', 'I', 'H');
    solve('O', 'H', 'I');
    solve('I', 'H', 'O');
    solve('I', 'O', 'H');
    printf("%lld\n", ans);
}

int main() {
    work();
    return 0;
}

