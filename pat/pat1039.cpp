#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
vector<int> names[300000];
int n,k;
int change(char *s){
    int ans = s[3]-'0' + (s[2]-'A')*10 + (s[1]-'A')*260 + (s[0]-'A')*26*260;
    return ans;
}
int main(){
    int i,j=0,id,num;
    char name[5];
    scanf("%d%d",&n,&k);
    for(i=0; i<k; i++){
        scanf("%d%d",&id,&num);
        while(num--){
            scanf("%s",name);
            j = change(name);
            names[j].push_back(id);
        }

    }

//    cout<<names.size()<<endl;
    for(i=0; i<n; i++){
        scanf("%s",name);
        j = change(name);
        if(names[j].empty()) printf("%s 0\n",name);
        else {
            sort(names[j].begin(),names[j].end(),less<int>());
            printf("%s %d",name,names[j].size());
            for(num=0; num<names[j].size(); num++){
                printf(" %d",names[j][num]);
            }
            cout<<endl;
        }
    }
	return 0;
}
