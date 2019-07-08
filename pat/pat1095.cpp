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
const int maxn = 10050;
const int INF = 1<<30;

int n,m,mmax=0;
char pl[maxn][10],ch[5];
int num[maxn], tim[maxn], cnt[24*3600+100],v[maxn];
vector<string> res;
map<string, int> ans;

bool comp(const int &a, const int &b){
	return strcmp(pl[a],pl[b])==0 ? tim[a] < tim[b] : strcmp(pl[a],pl[b]) < 0;
}

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%s%d:%d:%d%s",pl[i],&x,&y,&z,ch);
		tim[i] = x*3600 + y*60 + z;
		num[i] = i;
		if(ch[0]=='i') v[i]=0;
		else v[i] = 1;
	}
	sort(num,num+n,comp);
	for(int i=1; i<n; i++){
		if(strcmp(pl[num[i]],pl[num[i-1]])==0){
			if(v[num[i]]==1 && v[num[i-1]]==0){
				cnt[tim[num[i-1]]]++;
				cnt[tim[num[i]]]--;
				mmax = max(mmax, ans[pl[num[i]]] += tim[num[i]] - tim[num[i-1]]);
			}
		}
	}
	for(int i=1; i<=3600*24; i++) cnt[i] += cnt[i-1];
	while(m--){
		scanf("%d:%d:%d",&x,&y,&z);
		printf("%d\n",cnt[x*3600 + y*60 + z]);
	}
	map<string, int>::iterator iter = ans.begin();
	while(iter != ans.end()){
		if(iter->second == mmax) res.push_back(iter->first);
		iter++;
	}
	sort(res.begin(), res.end());
	for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
	printf("%02d:%02d:%02d", mmax/3600, (mmax%3600)/60, mmax%60);
	return 0;
}
