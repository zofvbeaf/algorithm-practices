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
	char name[15];
	char id[15];
	int grade;
	bool operator < (const Node &a) const{
		return grade > a.grade;
	}
};

vector<Node> nodes;
int n,g1,g2;
int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,flag=1;
	Node t;
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%s %s %d", t.name, t.id, &t.grade),nodes.push_back(t);
	scanf("%d%d", &g1, &g2);
	sort(nodes.begin(), nodes.end());
	for(i=0; i<n; i++){
		if(nodes[i].grade >= g1 && nodes[i].grade <= g2)
			printf("%s %s\n",  nodes[i].name, nodes[i].id), flag = 0;
	}
	if(flag) printf("NONE\n");
	return 0;
}
