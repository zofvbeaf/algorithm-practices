#include <iostream>
#include <map>
#include <string.h> //memset
using namespace std;

int main(){
    string a;
    map<int,string> t;
    int i,n,m;
    t[0] = "zero";
    t[1] = "one";
    t[2] = "two";
    t[3] = "three";
    t[4] = "four";
    t[5] = "five";
    t[6] = "six";
    t[7] = "seven";
    t[8] = "eight";
    t[9] = "nine";
    cin>>a;
    n = a.length();
    m=0;
    for(i=0; i<n; i++){
        m += a[i] - '0';
    }
    if(m>=100)
        cout<<t[m/100]<<" "<<t[(m/10)%10]<<" "<<t[m%10]<<endl;
    else if(m>=10)
        cout<<t[m/10]<<" "<<t[m%10]<<endl;
    else
        cout<<t[m]<<endl;
    return 0;
}
