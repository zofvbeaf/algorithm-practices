#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;
typedef long long LL;
const int INF = 1<<30;

struct Node{
	Node* l;
	Node* r;
	int id;
	Node(){ l=NULL; r=NULL; }
};
stack<int> st;
int n;
int po[50], pos[50], pu[50], pus[50];
Node* root = NULL;
queue<int> res;

void Creat(int left, int right, Node* &t){
	if(left>n || right<=0 || left>right) {t=NULL; return;}
	int p=left;
	for(int i=left; i<=right; i++){
		if(pus[po[p]] > pus[po[i]]) p=i;
	}
	t = (Node*)malloc(sizeof(Node));
	t->id = po[p];
	if(left==right) { t->l=NULL, t->r=NULL; return; }
	Creat(left, p-1, t->l);
	Creat(p+1, right, t->r);
}

void postorder(Node* &t){
	if(t==NULL) return ;
 	postorder(t->l);
	postorder(t->r);
	n--;
	printf("%d%s", t->id, n ? " " : "\n");

}


int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,totu=1, toto=1;
	char s[5];
	
	scanf("%d",&n);
	for(i=0; i<2*n; i++){
		scanf("%s",s);
		if(s[1]=='u'){
			scanf("%d",&j);
			st.push(j);
			pu[totu] = j;
			pus[j] = totu;
			totu++;
		}
		else {
			po[toto] = st.top();
			pos[st.top()] = toto;
			toto++;
			st.pop();
		}
	}
	Creat(1, n, root);
	postorder(root);
	return 0;
}
