#[UVALive3938 "Ray, Pass me the dishes!"](https://vjudge.net/problem/UVALive-3938)
#SOLUTION
+ 线段树，动态区间最大连续和
#AC CODE
```c++
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 500010;

typedef pair<int, int> Interval;
typedef long long LL;

LL prefix_sum[maxn];
int ql, qr;

LL sum(int L, int R) {
    return prefix_sum[R] - prefix_sum[L-1];
}

Interval better(Interval a, Interval b) {
    LL v1 = sum(a.first, a.second);
    LL v2 = sum(b.first, b.second);
    if(v1 != v2) return v1 > v2 ? a : b;
    return a < b ? a : b;
}

struct IntervalTree
{
    Interval max_sub[maxn<<1]; 
    int max_prefix[maxn<<1], max_suffix[maxn<<1];

    void build(int o, int L, int R) {  // 构建树
        if(L == R){
            max_sub[o] = make_pair(L, L); 
            max_prefix[o] = max_suffix[o] = L;  
            return ;
        }
        int M = L + ((R - L)/2);
        int l = o*2, r = o*2 + 1; //左右子节点
        build(l, L, M);  
        build(r, M+1, R);

        LL v1 = sum(L, max_prefix[l]); //左子树的最大前缀和
        LL v2 = sum(L, max_prefix[r]); //右子树的最大前缀和
        if(v1 == v2) max_prefix[o] = min(max_prefix[l], max_prefix[r]);
        else max_prefix[o] = v1 > v2 ? max_prefix[l] : max_prefix[r]; //更新当前节点的最大前缀和

        v1 = sum(max_suffix[l], R); //左子树的最大后缀和
        v2 = sum(max_suffix[r], R); //右子树的最大后缀和
        if(v1 == v2) max_suffix[o] = min(max_suffix[l], max_suffix[r]);
        else max_suffix[o] = v1 > v2 ? max_suffix[l] : max_suffix[r]; //更新当前节点的最大后缀和
        //更新最大子序列
        max_sub[o] = better(max_sub[l], max_sub[r]);
        max_sub[o] = better(max_sub[o], make_pair(max_suffix[l], max_prefix[r]));
    }

    Interval query_prefix(int o, int L, int R) {
        if(max_prefix[o] <= qr) return make_pair(L, max_prefix[o]);
        int M = L + ((R - L)/2);
        int l = o*2, r = o*2 + 1;
        if(qr <= M) return query_prefix(l, L, M);
        Interval v = query_prefix(r, M+1, R);
        v.first = L;  //右半段的前缀和的结果的左端点应当为L
        return better(v, make_pair(L, max_prefix[l])); /////////////////////
    }


    Interval query_suffix(int o, int L, int R) {
        if(max_suffix[o] >= ql) return make_pair(max_suffix[o], R);
        int M = L + ((R - L)/2);
        int l = o*2, r = o*2 + 1;
        if(ql > M) return query_suffix(r, M+1, R);
        Interval v = query_suffix(l, L, M);
        v.second = R;  //左半段的后缀和的结果的右端点应当为R
        return better(v, make_pair(max_suffix[r], R)); /////////////////////
    }

    Interval query(int o, int L, int R) {
        if(ql <= L && R <= qr) return max_sub[o];
        int M = L + ((R - L)/2);
        int l = o*2, r = o*2 + 1;
        if(qr <= M) return query(l, L, M);
        if(M < ql) return query(r, M+1, R);
        //如果区间分布在两个段中
        Interval v1 = query_suffix(l, L, M);
        Interval v2 = query_prefix(r, M+1, R);
        Interval v3 = better(query(l, L, M), query(r, M+1, R));
        return better(make_pair(v1.first, v2.second), v3);
    }


};

IntervalTree tree;

int main()
{
    int n, m, x, cnt = 0;
    Interval ans;
    prefix_sum[0] = 0;
    while(scanf("%d%d", &n, &m)==2) {
        for(int i = 1; i <= n; i++)
            scanf("%d", &x), prefix_sum[i] = prefix_sum[i-1] + x;
        tree.build(1, 1, n);
        printf("Case %d:\n", ++cnt);
        while(m--) {
            scanf("%d%d", &ql, &qr);
            ans = tree.query(1, 1, n);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}
```
