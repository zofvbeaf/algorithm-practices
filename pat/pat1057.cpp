#include<cstdio>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define MAXN 1000000
struct BinTree{
    vector<int> C;
    BinTree(){ C = vector<int>(MAXN,0);}

    int lowbit(int x){ return x&-x; }
    int sum(int x){
        int ret = 0;
        while(x > 0){ ret += C[x]; x -= lowbit(x); }
        return ret;
    }

    void add(int x, int d){
        while(x <= MAXN){ C[x] += d; x += lowbit(x); }
    }

    int find(int x, int l ,int r){
        if(l==r) return l;
        int mid = (l+r)/2;
        if(sum(mid) < x) return find(x, mid+1, r);
        else return find(x, l, mid);
    }
};
BinTree tree;
int main()
{
    int N,t;
    char s[12];
    stack<int> num;
    scanf("%d",&N);
    while(N--){
        scanf("%s",s);
        if(s[1]=='o'){
            if(num.empty()) printf("Invalid\n");
            else {
                printf("%d\n",num.top());
                tree.add(num.top(),-1);
                num.pop();
            }
        }
        else if(s[1]=='u'){
            scanf("%d",&t);
            num.push(t);
            tree.add(t,1);
        }
        else if(s[1]=='e'){
            if(num.empty()) printf("Invalid\n");
            else{
                t = (num.size()+1)/2;
                printf("%d\n",tree.find(t, 1, MAXN-1));
            }
        }
    }
	return 0;
}
