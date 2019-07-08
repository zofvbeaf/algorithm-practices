#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int change(char *s){
    int ans = s[3]-'0' + (s[2]-'A')*10 + (s[1]-'A')*260 + (s[0]-'A')*26*260;
    return ans;
}

void printback(int x){
    printf("%c", 'A' + x / 6760);
    printf("%c", 'A' + x % 6760 / 260);
    printf("%c", 'A' + x % 260 / 10);
    printf("%c\n", x % 10 + '0');
}

int main(){
    int n,k,i,j,num,temp;
    char name[5];
    scanf("%d%d",&n,&k);
    vector<int> course[k+1];
    for(i=0; i<n; i++){
        scanf("%s %d",name,&j);
        num = change(name);
        while(j--){
            scanf("%d",&temp);
            course[temp].push_back(num);
        }
    }
    for(i=1; i<=k; i++){
        sort(course[i].begin(), course[i].end());
        printf("%d %d\n",i,course[i].size());
        for(j=0; j<course[i].size(); j++)
            printback(course[i][j]);
    }
	return 0;
}
