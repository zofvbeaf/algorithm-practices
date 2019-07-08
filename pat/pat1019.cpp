#include<iostream>
#include<math.h>
#include<string.h> //memset
using namespace std;

int main(){
    int n,b;
    int flag,i,m,r[100];
    memset(r,0,sizeof(r));
    cin>>n>>b;
    if(n<b || n==0){
        cout<<"Yes"<<endl;
        cout<<n<<endl;
        return 0;
    }
    m = (int)(log((double)n+1) / log((double)b)) + 1;
    for(i=0; i<m; i++){
        r[i] = n % b;
        n = n / b;
    }
    flag = 0;
    for(i=0; i<m; i++){
        if(r[i] != r[m-1-i]){
            flag = 1;
            break;
        }

    }
    if(flag)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    cout<<r[m-1];
    for(i=m-2; i>=0; i--){
        cout<<" "<<r[i];
    }
    cout<<endl;
    return 0;
}
