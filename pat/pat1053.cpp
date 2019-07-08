#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,s,weight[105],dist[105],pre[105];
vector<int> adj_node[105];
vector<vector<int> > path;
void dfs(int id){
    int i,j,len;
    len = adj_node[id].size();
    for(i=0; i<len; i++){
        dist[adj_node[id][i]] = weight[adj_node[id][i]] + dist[id];
        dfs(adj_node[id][i]);
    }
}

void add_path(int id){
    vector<int> result;
    while(id!=-1){
        result.push_back(weight[id]);
        id = pre[id];
    }
    path.push_back(result);
}

bool comp(vector<int> a, vector<int> b){
    int ia = a.size()-1,ib = b.size()-1,i,j;
    for(i=ia,j=ib; i>=0 && j>=0; i--,j--)
        if(a[i] > b[j]) return 1;
        else if(a[i] < b[j]) return 0;
}

int main()
{
    int i,j,x,num;
    scanf("%d%d%d",&n,&m,&s);
    pre[0] = -1;
    for(i=0; i<n; i++) scanf("%d",weight+i);
    for(i=0; i<m; i++){
        scanf("%d%d",&x,&num);
        while(num--){
            scanf("%d",&j);
            adj_node[x].push_back(j);
            pre[j] = x;
        }
    }
    dist[0] = weight[0];
    dfs(0);
    for(i=0; i<n; i++){
        if(dist[i]==s && adj_node[i].empty()) add_path(i);
    }
    sort(path.begin(), path.end(), comp);
    j = path.size();
    for(x=0; x<j; x++){
        num = path[x].size();
        for(i=num-1; i>0; i--)
            printf("%d ", path[x][i]);
        printf("%d\n",path[x][0]);
    }
	return 0;
}
