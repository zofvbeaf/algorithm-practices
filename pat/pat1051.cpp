#include<cstdio>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    int n,m,k,i,j,flag=1;
    scanf("%d%d%d",&m,&n,&k);
    int a[n+1];
    while(k--){
        stack<int> p;
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        j=1,flag=1;
        for(i=1; i<=n; i++){
            p.push(i);
            if(p.size() > m || a[j] < i ) {
                flag = 0;
                break;
            }
            if(p.top() == a[j]){
                for(;!p.empty() && p.top() == a[j];j++) p.pop();
            }
        }
        if(j<=n) flag=0;
        printf("%s\n",flag? "YES" : "NO");
    }
	return 0;
}
