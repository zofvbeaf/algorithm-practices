#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
char ch(int a){
    if(a<10) return a+'0';
    else if(a==10) return 'A' ;
    else if(a==11) return 'B' ;
    else if(a==12) return 'C' ;
}
int main()
{
    int a,b=3;
    cout<<"#";
    while(b--){
        cin>>a;
        cout<<ch(a/13)<<ch(a%13);
    }
    cout<<endl;
}
