#include<map>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<2) return 0;
    if(n<=3) return 1;
    for(int i=2; i<=sqrt((double)n); i++) if(n%i==0)
        return 0;
    return 1;
}

int tra(int n, int d){ //按d进制将n反转,n和反转结果均为10进制
    double m = (log((double)n+1) / log((double)d)) > (ceil)(log((double)n+1) / log((double)d)) ? (ceil)(log((double)n+1) / log((double)d))+1 : (ceil)(log((double)n+1) / log((double)d));
    int result=0;
    for(int i=0; i<m; i++){ //共m位
        result += (n%d) * (int)pow(d,m-1-i);
        n = n / d;
    }
    return result;
}

int main()
{
    int n,d;
    cin>>n;
    while(n>=0){
        cin>>d;
        if(n<=1){
            cout<<"Yes"<<endl;
            cin>>n;
            break;
        }
        if(isPrime(n) && isPrime(tra(n,d))){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        cin>>n;
    }
	return 0;
}
