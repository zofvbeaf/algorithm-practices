#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int n,m,i,ans=0,s,e;
    cin>>n;
    int a[n],sum[n+1];
    sum[1] = 0;
    for(i=1; i<=n; i++) {
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
    }
    cin>>m;
    for(i=0; i<m; i++){
        cin>>s>>e;
        if(s < e)
            ans = min(sum[e]-sum[s],a[n]+sum[n]-sum[e]+sum[s]);
        else ans = min(sum[s]-sum[e],a[n]+sum[n]-sum[s]+sum[e]);
        cout<<ans<<endl;
    }
	return 0;
}
