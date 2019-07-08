	#include<cstdio>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    char a[65],b[65],c[65],d[65];
    char DAY[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int lena,lenb,lenc,lend,i,j,coun=0;
    scanf("%s%s%s%s",a,b,c,d);
    lena = strlen(a);
    lenb = strlen(b);
    lenc = strlen(c);
    lend = strlen(d);
    for(i=0,j=0; i<lena && j<lenb; i++,j++) {
        if(b[j]==a[i]){
            if(a[i]>='A' && a[i]<='Z'){
                if(coun==0 && a[i]>='A' && a[i]<='G') printf("%s ",DAY[a[i]-'A']),coun=1;
                else if(coun==1 && a[i]>='A' && a[i]<='N') {printf("%02d:",a[i]-'A'+10);break;}
            }
            else if(coun && a[i]>='0' && a[i]<='9'){ printf("%02d:",a[i]-'0');break;}
        }
    }
    for(i=0,j=0; i<lenc && j<lend; i++,j++) if(c[i]==d[j]){
        if((c[i]>='a' && c[i]<='z') || (c[i]>='A' && c[i]<='Z')){
             printf("%02d\n",i);
             break;
        }
    }


	return 0;
}
