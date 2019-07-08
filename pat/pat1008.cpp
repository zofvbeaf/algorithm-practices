#include <iostream>
#include<string.h> //memset
using namespace std;

int main(){
    int n,total,a,b;
    cin>>n>>b;
    total = 5*n + 6*b;
    n--;
    while(n--){
        cin>>a;
        if(a>b)
            total += (a-b) * 6;
        else
            total += (b-a) * 4;
        b = a;
    }
    cout<<total<<endl;
    return 0;
}
