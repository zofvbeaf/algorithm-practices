#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,num[1010],tree[1010],tot=0;

void dfs(int x){
    if(x > n) return; //x从1开始
    dfs(x << 1);  //先使a[0]成为根，再确定a[1],a[2]...的位置
    tree[x] = num[tot++];
    dfs(x<<1 | 1);
}

void bfs(int x){
    queue<int> q; q.push(x);
    while(!q.empty()){
        x = q.front();
        q.pop();
        printf("%d%s",tree[x],x==n ? "\n" : " ");
        if((x<<1) <= n) q.push(x<<1);
        if((x<<1|1) <= n) q.push(x<<1 | 1);
    }
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",num+i);
    sort(num,num+n);
    dfs(1);
    bfs(1);
    return 0;
}
