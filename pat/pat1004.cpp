#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
int node[102][102],l=0,n,m,coun[102]={0};
bool dfs(int root, int level){
    bool flag = 1;
    l = l > level ? l : level;
    for(int i=1; i<=n; i++){
        if(node[root][i]){
            flag = 0; //root不是叶子节点
            if(dfs(i,level+1)) coun[level+1]++;
        }
    }
    return flag;
}
int main(){
    memset(node,0,sizeof(node));
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int id,k,p;
        cin>>id>>k;
        for(int j=0; j<k; j++){ cin>>p; node[id][p] = 1; }
    }
    int i;
    if(dfs(1,0)) cout<<"1"<<endl;
    else {
        for(i=0; i<=l-1; i++) cout<<coun[i]<<" ";
        cout<<coun[i]<<endl;
    }
    return 0;
}
