#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
const int maxn = 1e4 + 50;

struct Node{
	char name[10];
	int high;
};

vector<Node> nodes;

bool comp(const Node &a, const Node &b){
	return a.high == b.high  ? strcmp(a.name, b.name) < 0 : a.high > b.high;
}

int n,k;
int res[maxn][maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++){
		Node t;
		scanf("%s%d", t.name, &t.high);
		nodes.push_back(t);
	}
	sort(nodes.begin(), nodes.end(), comp);
	int tot = 0;
	for(int i=k; i>=1; i--){
		int m=n/k, x;
		if(i==k) m += n%k;
		x = m/2+1;
		res[i][x] = tot++;
		for(int j=1; x-j>=1 || x+j<=m; j++){
			if(x-j>=1) res[i][x-j] = tot++;
			if(x+j<=m) res[i][x+j] = tot++;
		}
		for(int j=1; j<=m; j++) printf("%s%s", nodes[res[i][j]].name, j==m ? "\n" : " ");
	}
	
	return 0;
}
