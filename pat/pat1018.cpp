#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int cmax,n,sp,m,vis[502],g[502][502],c[502],dist[502],p[502];
int INF = 1<<30;

struct Path{
    int pre,prep,send,back;
}paths[502][502];


void dij(){
    dist[0] = 0;
    p[0] = 1;
    paths[0][0].pre = paths[0][0].prep = -1;
    paths[0][0].send = paths[0][0].back = 0;
    int now = 0,i,j,k,mmin;
    while(!vis[sp]){
        mmin = INF;
        for(i=0; i<=n; i++) if(!vis[i] && mmin > dist[i]) mmin = dist[now=i];

        vis[now] = 1;
        if(now == sp) return; //找到最小标记点
        for(i=1; i<=n; i++) {
            if(g[now][i] && !vis[i] && (dist[i] >= dist[now] + g[now][i])){
                if(dist[i] > dist[now] + g[now][i]) p[i] = 0; //如果相等表示源点同过now和其它某个节点到i的距离相等，不更新p[i]
                dist[i] = dist[now] + g[now][i];
                int temp = abs(c[i] - cmax);
                for(j=0,k=p[i]; j < p[now]; j++,k++){ //now->i,now的每条路对i而言也是i的路，所以同步更新
                    paths[i][k].pre = now;
                    paths[i][k].prep = j;
                    if(c[i] >= cmax) {//back+
                        paths[i][k].back = paths[now][j].back + temp;
                        paths[i][k].send = paths[now][j].send;
                    }
                    else{
                        if(paths[now][j].back >= temp){
                            paths[i][k].back = paths[now][j].back - temp;
                            paths[i][k].send = paths[now][j].send;
                        }
                        else{
                            paths[i][k].back = 0;
                            paths[i][k].send = paths[now][j].send + temp - paths[now][j].back;
                        }
                    }
                }
                p[i] = k; //k为++后的值，所以至少为1
            }
        }
    }
}

int main()
{
    int i,j,k;
    int si,sj,tij;
    int send,back,pre,prep;
    send = back = INF;
    pre = prep = 0;
    cin>>cmax>>n>>sp>>m;
    cmax = cmax/2;

    memset(vis,0,sizeof(vis));
    memset(g,0,sizeof(g));
    memset(c,0,sizeof(c));
    memset(p,0,sizeof(p));

    for(i=1; i<=n; i++) {
        cin>>c[i];
        dist[i] = INF;
        paths[i][n-i+1].pre = paths[i][n-i+1].prep = 0;
        paths[i][n-i+1].back = paths[i][n-i+1].send = 0;
    }

    for(i=0; i<m; i++) {
        cin>>si>>sj>>tij;
        g[si][sj] = g[sj][si] = tij;
    }

    dij();
    for(i=0; i<p[sp]; i++){
        if(send > paths[sp][i].send || (send == paths[sp][i].send && back > paths[sp][i].back)){
            send = paths[sp][i].send;
            back = paths[sp][i].back;
            pre = paths[sp][i].pre;
            prep = paths[sp][i].prep;
        }
    }

    int ans[502];
    for(i=pre,j=prep,k=0; i>=0; ){
        ans[k++] = i;
        pre = paths[i][j].pre;
        prep = paths[i][j].prep;
        i = pre;
        j = prep;
    }
    cout<<send<<" ";
    for(i=k-1; i>=0; i--) cout<<ans[i]<<"->";
    cout<<sp<<" "<<back<<endl;
    return 0;
}









