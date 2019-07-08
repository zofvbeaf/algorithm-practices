#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;

struct Node{
	int ge,tot,id;
	int p[7];
};

vector<Node> nodes;
vector<int> res[111000];
int n,m,k;
int qout[111000];

bool equ(int x, int y){
	return nodes[x].tot==nodes[y].tot && nodes[x].ge==nodes[y].ge;
}

bool comp(const Node &a, const Node &b){
	return a.tot==b.tot ? a.ge > b.ge : a.tot > b.tot;
}

int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0; i<m; i++) scanf("%d",&qout[i]);
	for(i=0; i<n; i++){
		Node t;
		scanf("%d%d",&t.ge,&t.tot);
		t.tot += t.ge;
		t.id = i;
		for(j=0; j<k; j++) scanf("%d",&t.p[j]);
		nodes.push_back(t);
	} 
	sort(nodes.begin(), nodes.end(), comp);
	for(i=0; i<n; i++){
		for(j=0; j<k; j++) 
			if(res[nodes[i].p[j]].size() < qout[nodes[i].p[j]] || equ(nodes[i].id, res[nodes[i].p[j]][res[nodes[i].p[j]].size()-1])){
				res[nodes[i].p[j]].push_back(nodes[i].id);
				break;
			}
	}
	for(i=0; i<m; i++){
		if(res[i].empty()){
			printf("\n");
			continue;
		}
		sort(res[i].begin(), res[i].end());
		n = res[i].size();
		for(j=0; j<n; j++) printf("%s%d",j ? " " : "", res[i][j]);
		printf("\n");
	}
	return 0;
}
