#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<math.h>
#include<functional>
using namespace std;

struct Node{
	int add,data,next;
};

vector<Node> nodes;

int np[1000000],pn[1000000],nn[1000000];



int main(){
	int start,n,k;
	int i,j;
	int add,data,nex;
	Node t;
	scanf("%d%d%d",&start, &n, &k);
	
	
	for(i=0; i<n; i++){
		scanf("%d%d%d",&add, &data, &nex);
		np[data] = add;
		pn[add] = data;
		nn[add] = nex;
	}
	
	for(i=0; i<n && start!=-1; i++){
		t.add = start;
		t.data = pn[start];
		t.next = nn[start];
		nodes.push_back(t);
		start = nn[start];
	}
	n = nodes.size();
	j = 0;
	while(n>=k){
		for(i=j+k-1; i>j; i--) printf("%05d %d %05d\n",nodes[i].add,nodes[i].data,nodes[i-1].add);
		printf("%05d %d ",nodes[j].add,nodes[j].data);
		if(j+k==nodes.size()) printf("-1\n");
		else if(j+k+k<=nodes.size()) printf("%05d\n",nodes[j+k+k-1].add);
		else printf("%05d\n",nodes[j+k].add);	
		j += k;
		n -= k;
	}
	for(i=j; i<j+n; i++){
		printf("%05d %d ",nodes[i].add,nodes[i].data);
		if(i==j+n-1) printf("-1\n");
		else printf("%05d\n",nodes[i].next);	
	} 
	
	return 0;
}