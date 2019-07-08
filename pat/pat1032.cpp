#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
    int s1,s2,n,nodes[100002],a,i,b,temp,tnodes[100002];
    char c;
    memset(nodes, -1, sizeof(nodes));
    memset(tnodes, 0, sizeof(tnodes));

    scanf("%d %d %d",&s1,&s2,&n);
    for(i=0; i<n; i++){
        scanf("%d %c %d",&a,&c,&b);
        nodes[a] = b;
    }
    while(nodes[s1] != -1){
        tnodes[s1] = 1;
        s1 = nodes[s1];
    }
    while(nodes[s2] != -1){
        if(tnodes[s2]){printf("%05d\n",s2);return 0;};
        s2 = nodes[s2];
    }
    printf("-1\n");
    return 0;
}
