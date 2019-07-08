#include<cstdio>
#include<set>
#include<algorithm> ////set_intersection 函数
#include <iterator>		//inserter函数
using namespace std;

int main(){
    int n,m,i,j,k;
    scanf("%d",&n);
    set<int> num[n];
    for(i=0; i<n; i++){
        scanf("%d",&m);
        while(m--) scanf("%d",&j),num[i].insert(j);
    }
    set<int> ans;
    scanf("%d",&k);
    for(i=0; i<k; i++){
        scanf("%d%d",&n,&m);
        n--, m--;
        set_intersection(num[n].begin(), num[n].end(), num[m].begin(), num[m].end(), inserter(ans, ans.begin()));
        printf("%.1f%%\n",(ans.size()*100.0)/(num[n].size() + num[m].size() - ans.size()));
        ans.clear();
    }
    return 0;
}
