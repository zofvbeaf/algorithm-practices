#include<iostream>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct Edge{
    int s,e,len;
};

map<string,int> names;
vector<Edge> edges;



int ufs_f(int a,int *ufs){
    while(ufs[a] != -1) a = ufs[a];
    return a;
}

void ufs_u(int a, int b,int *ufs,int* nodes,int *coun){
    int aa = ufs_f(a,ufs);
    int bb = ufs_f(b,ufs);
    if(aa != bb) {
        if(nodes[aa] > nodes[bb]){
            ufs[bb] = aa;
            coun[aa] += coun[bb];
        }
        else{
            ufs[aa] = bb;
            coun[bb] += coun[aa];
        }
    }
}

int main(){
    int n,k;
    names.clear();
    cin>>n>>k;
    int i,j=0;
    string name1,name2;
    int len;
    Edge e;
    set<pair<string,int> > result;
    for(i=0; i<n; i++){
        cin>>name1>>name2>>len;
        if(names.count(name1)==0){names[name1] = ++j; }
        if(names.count(name2)==0){names[name2] = ++j; }
        e.s = names[name1];
        e.e = names[name2];
        e. len = len;
        edges.push_back(e);
    }
    int ufs[j+1],coun[j+1],nodes[j+1],total[j+1];

    memset(ufs,-1,sizeof(ufs));
    memset(nodes,0,sizeof(nodes));
    memset(total,0,sizeof(total));
    for(i=0; i<n; i++){
        nodes[edges[i].s] += edges[i].len;
        nodes[edges[i].e] += edges[i].len;
        coun[edges[i].s] = coun[edges[i].e] = 1;
    }
    for(i=0; i<n; i++){
        ufs_u(edges[i].s,edges[i].e,ufs,nodes,coun);
    }
    for(i=0; i<n; i++){
        int r = ufs_f(edges[i].s,ufs);
        total[r] += edges[i].len;
    }
    map<string,int>::iterator it = names.begin();
    while(it != names.end()){
        if(ufs[it->second]==-1 && total[it->second] > k && coun[it->second] > 2)
            result.insert(make_pair(it->first,coun[it->second]));
        it++;
    }
    cout<<result.size()<<endl;
    set<pair<string,int> >::iterator iter = result.begin();
    while(iter != result.end()){
        cout<<iter->first<<" "<<iter->second<<endl;
        iter++;
    }
	return 0;
}
