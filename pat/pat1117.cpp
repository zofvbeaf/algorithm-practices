#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;

int n,a[100005];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1; i<=n; i++){
		if(a[i] <= i){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}
