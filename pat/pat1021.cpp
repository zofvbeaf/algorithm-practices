#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
using namespace std;

int n;
vector<int> graph[10002];
int ufs[10002]; //并查集,用于找连通分量个数
map<int,vector<int>,greater<int> > dis_nodes;

int ufs_f(int a){ //为ufs[a]为-1表示a为根节点
    return ufs[a] == -1 ? a : ufs_f(ufs[a]);
}

void ufs_u(int a, int b){
    a = ufs_f(a);
    b = ufs_f(b);
    if(a != b)  ufs[a] = b;
}

int bfs(int s){
    int dist[10002];
    memset(dist,-1,sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    int dmax = 0;

    while(!q.empty()){
        s = q.front();
        int d = dist[s];
        q.pop();
        for(int i=0; i<graph[s].size(); i++){
            if(dist[ graph[s][i] ] == -1){
                dist[ graph[s][i] ] = d + 1;
                q.push(graph[s][i]);
            }
        }
        dmax = d > dmax ? d : dmax;
    }
    return dmax;
}

int main()
{
	memset(ufs,-1,sizeof(ufs));
    cin>>n;
    for(int i=1; i<n; i++) {
        int a,b;
        cin>>a>>b;
        ufs_u(a,b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int coun=0;
    for(int i=1; i<=n; i++){
        if(ufs[i] == -1) coun++; //找根节点个数，即连通分量的个数
    }

    if(coun != 1){ cout<<"Error: "<<coun<<" components"<<endl; return 0;  }
    for(int i=1; i<=n; i++){
        dis_nodes[bfs(i)].push_back(i);
    }
    int dis = dis_nodes.begin()->first;
    for(int i=0; i<dis_nodes[dis].size(); i++){
        cout<<dis_nodes[dis][i]<<endl;
    }
	return 0;
}
