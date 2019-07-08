#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int address,data;
    Node(int a, int b){ address = a; data = b; }
    bool operator < (const Node &a)const{
        return data < a.data;
    }
};

int main()
{
    int data[100002],next[100002],address;
    int n,s,i;
    vector<Node> nodes;
    scanf("%d%d",&n,&s);
    for(i=0; i<n; i++){
        scanf("%d",&address);
        scanf("%d%d",&data[address],&next[address]);
    }
    while(s != -1){
        nodes.push_back(Node(s,data[s]));
        s = next[s];
    }
    n = nodes.size();
    if(n==0) { printf("0 -1\n"); return 0; }
    sort(nodes.begin(), nodes.end());
    printf("%d %05d\n",n,nodes[0].address);
    for(i=0; i<n-1; i++)
        printf("%05d %d %05d\n",nodes[i].address, nodes[i].data, nodes[i+1].address);
    printf("%05d %d -1",nodes[n-1].address, nodes[n-1].data);
	return 0;
}
