#include <iostream>
#include<string.h> //memset
using namespace std;

int main(){
    int sum,i,k,n,m,s,t,si,flag,start;
    cin>>n;
    cin>>k;
    si = k;
    s = k;
    t = k;
    sum = k;
    m = k;
    start = k;
    flag = 0;
    if(k>=0) flag =1;
    for(i = 1; i < n; i++){
        cin>>k;
        if(k>=0) flag =1;
        if(sum <= 0){
            si = k;
            sum = 0;
        }
        sum += k;
        if(sum > m){
            s = si;
            m = sum;
            t = k;
        }
    }
    if(flag)
        cout<<m<<" "<<s<<" "<<t<<endl;
    else
        cout<<"0"<<" "<<start<<" "<<k<<endl;
    return 0;
}
