#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    char s1[10010],s2[10010];
    int i,tag[300];
    gets(s1);
    gets(s2);
    for(i=0; s2[i]; i++){
        tag[s2[i]]++;
    }
    for(i=0; s1[i]; i++){
        if(tag[s1[i]]==0) printf("%c",s1[i]);
    }
	return 0;
}
