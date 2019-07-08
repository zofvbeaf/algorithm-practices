#include<iostream>
#include<string.h>
using namespace std;
#define INF 1<<30
int n,m,s,t,e[502][502],dist[502],team[502],vis[502],path[502],maxteam[502];

void dij(){
    path[s] = 1;
    maxteam[s] = team[s];
    dist[s] = 0;
    for(int i=0; i<n; i++){
        int p,mmin = INF;
        for(int j=0; j<n; j++) if(vis[j] == 0 && mmin > dist[j]) mmin = dist[p=j]; //找最小标记
        if(mmin==INF || p==t) return;
        vis[p] = 1;
        for(int j=0; j<n; j++)
            if(vis[j]==0){
                int distcost = dist[p]+e[p][j];
                if(dist[j] > distcost){
                    dist[j] = distcost;
                    path[j] = path[p];
                    maxteam[j] = maxteam[p] + team[j];
                }
                else if(dist[j] == distcost){
                    path[j] += path[p];
                   if(maxteam[j] < maxteam[p] + team[j]) maxteam[j] = maxteam[p] + team[j];
                }
            }
    }
}

int main(){
    cin>>n>>m>>s>>t;

    memset(vis,0,sizeof(vis));
    memset(path,0,sizeof(path));
    memset(maxteam,0,sizeof(maxteam));

    for(int i=0; i<n; i++){
        cin>>team[i];
        dist[i] = INF;
        for(int j=0; j<n; j++) e[i][j] = e[j][i] = INF;
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a][b] = e[b][a] = c;
    }
//    cout<<"oooo"<<endl;
    dij();
    cout<<path[t]<<" "<<maxteam[t]<<endl;;
    return 0;
}
