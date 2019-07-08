#include<cstdio>
#include<algorithm>
#include<string.h>
#include<functional>
#include<math.h>
#include<vector>
using namespace std;
int a[10010],dp[10010][110],tag[10010][110];
bool comp(vector<int> a, vector<int> b){
    int lena = a.size()-1;
    int lenb = b.size()-1;
    for(;lena>=0 && lenb>=0; lena--,lenb--){
        if(a[lena]==b[lenb]) continue;
        else return a[lena] < b[lenb];
    }
}
int main(){
//    freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
    int n,m,i,j,flag=1,sec;
    vector<int> ans;
    memset(dp, 0, sizeof(dp));
    memset(tag, 0, sizeof(tag));
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++) scanf("%d",a+i);
    sort(a+1, a+n+1, greater<int>());
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(j < a[i]) sec = 0;
            else sec = dp[i-1][j-a[i]]+a[i];
            if(dp[i-1][j] > sec) dp[i][j] = dp[i-1][j];
            else dp[i][j] = sec, tag[i][j] = 1;
        }
        if(dp[i][m]==m) flag = 0;
    }
    if(flag) { printf("No Solution\n"); return 0; }
    while(m){
        while(!tag[n][m]) n--;
        ans.push_back(a[n]);
        m -= a[n];
        n--;
    }
    n = ans.size();
    for(i=0; i<n; i++) printf("%d%s",ans[i], i==n-1 ? "\n" : " ");
	return 0;
}
