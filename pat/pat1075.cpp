#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<math.h>
#include<cmath>
#include<functional>
using namespace std;

struct Node{
	int id,*s,tot,perf, flag;
	bool operator < (const Node &a) const{
		if(tot != a.tot) return tot > a.tot;
		else if(perf != a.perf) return perf > a.perf;
		else return id < a.id;
	}
};

int n,k,m;
int p[10],score[100000][10],total[100000],tag[100000];

vector<Node> res;
int main(){
// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,t;
	scanf("%d%d%d",&n, &k, &m);
	memset(score, -1, sizeof(score));
	memset(total, 0, sizeof(total));
	memset(tag, 0, sizeof(tag));
	for(i=1; i<=k; i++) scanf("%d",p+i);
	while(m--){
		scanf("%d%d%d",&i, &j, &t);
		if(t > -1) tag[i] = 1;
		score[i][j] = max(score[i][j], max(t, 0));
	}
	Node temp;
	for(i=1; i<=n; i++){
		if(tag[i]==0) continue;
		temp.id = i;
		temp.s = score[i];
		temp.tot = 0;
		temp.perf = 0;
		for(t=1; t<=k; t++) {
			if(temp.s[t] == p[t]) temp.perf++;
			if(score[i][t] > 0) temp.tot += score[i][t];
		}
		res.push_back(temp);
	}
	sort(res.begin(), res.end());
	j = 1;
	for(i=0; i<res.size(); i++){
		if(i>0 && res[i].tot!=res[i-1].tot) j = i+1;
		printf("%d %05d %d", j, res[i].id, res[i].tot);
		for(t=1; t<=k; t++){
			if(res[i].s[t]==-1) printf(" -");
			else printf(" %d",res[i].s[t]);
		} 
		printf("\n");
	}
	return 0;
}




