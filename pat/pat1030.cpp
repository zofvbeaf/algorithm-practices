#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct Path{
    int pre,prep,cost;
}paths[502][502];

int n,m,s,d,edist[502][502],ecost[502][502];
int vis[502],dist[502],p[502];
int INF = 1<<30;

void dij(){
    dist[s] = 0;
    p[s] = 1;
    paths[s][0].pre = -1;
    int i,j,k,now,mmin;
    while(!vis[d]){
        mmin = INF;
        for(i=0; i<n; i++)  if(!vis[i] && mmin > dist[i]) mmin = dist[now=i];
        if(now==d || mmin==INF) return;
        vis[now] = 1;
        for(i=0; i<n; i++){
            if(edist[now][i]>0 && !vis[i]){
                if(dist[i] >= dist[now] + edist[now][i]){
                    if(dist[i] > dist[now] + edist[now][i]) p[i] = 0;
                    dist[i] = dist[now] + edist[now][i];
                    for(j=0,k=p[i]; j<p[now]; j++,k++){
                        paths[i][k].pre = now;
                        paths[i][k].prep = j;
                        paths[i][k].cost = paths[now][j].cost + ecost[now][i];
                    }
                    p[i] = k;
                }
            }
        }
    }

}

int main()
{
    int i,j;
    cin>>n>>m>>s>>d;
    for(i=0; i<n; i++) {
        dist[i] = INF;
        vis[i] = p[i] = 0;
        edist[i][n-1-i] = ecost[i][n-1-i] = 0;
        paths[i][n-1-i].pre = paths[i][n-1-i].prep = 0;
        paths[i][n-1-i].cost = 0;
    }
    for(i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cin>>edist[a][b]>>ecost[a][b];
        edist[b][a] = edist[a][b];
        ecost[b][a] = ecost[a][b];
    }
    dij();
    int mmin = INF,now;
    for(i=0; i<p[d]; i++)  if(mmin > paths[d][i].cost) mmin = paths[d][now=i].cost;

    vector<int> result;
    int pre = d,prep = now;
    result.push_back(pre);
    while(pre>=0){
        i = paths[pre][prep].pre;
        j = paths[pre][prep].prep;
        pre = i;
        prep = j;
        result.push_back(pre);
    }
    for(i=result.size()-2; i>=0; i--) cout<<result[i]<<" ";
    cout<<dist[d]<<" "<<mmin<<endl;
    return 0;
}
