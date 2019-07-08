#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
int data[100010],nex[100010],tag[10050];
vector<int> ans;
int main(){
//	freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int start,n,add;
	memset(tag, 0, sizeof(tag));
	scanf("%d%d",&start,&n);
	while(n--){
		scanf("%d",&add);
		scanf("%d%d",&data[add],&nex[add]);
	}
	add = start;
	while(start!=-1){
		if(tag[abs(data[start])]==0){
			tag[abs(data[start])] = 1;
			if(start != add) printf("%05d\n",start);
			printf("%05d %d ", start, data[start]);
		}
		else{
			ans.push_back(start);
		}
		start = nex[start];
	}
	printf("-1\n");
	n = ans.size();
	for(int j=0; j<n; j++){
		printf("%05d %d ", ans[j], data[ans[j]]);
		if(j==n-1) printf("-1\n");
		else printf("%05d\n", ans[j+1]);
	}
	return 0;
}
