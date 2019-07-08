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
const int maxn = 1e3 + 50;
int n,cnt,ans[maxn];

struct Node{
	int data;
	Node* l;
	Node* r;
};

void insert(int x, Node* &t){
	if(t==NULL){
		t = (Node*)malloc(sizeof(Node));
		t->data = x;
		t->l = NULL;
		t->r = NULL;
		return;
	} 
	else if(x > t->data) insert(x,t->r);
	else insert(x,t->l);	
}

void dfs(Node* &t, int level){
	if(t==NULL) return;
	if(cnt < level) cnt = level;
	ans[level]++;
	dfs(t->l, level+1); 
	dfs(t->r, level+1);
}

int main(){
	Node* root = NULL;
	scanf("%d",&n);
	for(int i=0,x; i<n; i++) scanf("%d",&x),insert(x,root);
	dfs(root,1);
	printf("%d + %d = %d\n",ans[cnt], ans[cnt-1],ans[cnt]+ans[cnt-1]);
	return 0;
}
