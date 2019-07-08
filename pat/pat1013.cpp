#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

bool g[1002][1002],gg[1002][1002],vis[1002];
int n,m,k,coun;

void dfs(int i){
    vis[i] = 1;
    for(int j=1; j<=n; j++) if(gg[i][j] && vis[j] == 0){
        dfs(j);
    }
    return;
}

void renew(int s){
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i!=s  && j!=s){
        gg[i][j] = g[i][j];
    }
}

int main()
{
    int s,t;
    coun = 0;
    memset(g,0,sizeof(g));
    memset(gg,0,sizeof(gg));
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        cin>>s>>t;
        g[s][t] = g[t][s] = 1;
    }
    while(k--){
        cin>>s;
        renew(s);
        for(int j=1; j<=n; j++) if(vis[j] == 0){
            dfs(j);
            coun++;
        }
        cout<<coun-2<<endl;
        coun = 0;
        memset(gg,0,sizeof(gg));
        memset(vis,0,sizeof(vis));
    }

    return 0;
}
