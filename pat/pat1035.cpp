#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,coun=0,ans[1002],i,j;
    char a[1002][12],b[1002][12];
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    int len,flag=0;
    char *p;
    for(i=0; i<n; i++){
        flag=0;
        scanf("%s %s",&a[i],&b[i]);
        len = strlen(b[i]);
        p = b[i];
        for(j=0; j<len; j++){
            if(*p=='1' || *p=='0' || *p=='l' || *p=='O') {
                if(*p=='1') *p = '@';
                else if(*p=='0') *p = '%';
                else if(*p=='l') *p = 'L';
                else if(*p=='O') *p = 'o';
                flag=1;
            }
            p++;
        }
        if(flag){coun++; ans[i]=1;}
    }
    if(coun==0){
        if(n==1)
            printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n",n);
        return 0;
    }
    printf("%d\n",coun);
    for(i=0; i<n; i++){
        if(ans[i])
        printf("%s %s\n",a[i],b[i]);
    }
	return 0;
}
