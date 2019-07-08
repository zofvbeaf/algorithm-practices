#include<iostream>
#include<string.h>
using namespace std;

int change(int n){
    return 1<<n;
}

int main()
{
    string s;
    cin>>s;
    int len = s.length(),num1=0,num2=0,carry=0,temp=0;
    while(len--){
        num1 += change(s[len] - '0'); //二进制某位为1表示相应位代表的数字已经使用
        temp = (s[len] - '0') * 2;
        s[len] = (temp + carry)%10 + '0';
        num2 += change(s[len] - '0');
        carry = (temp + carry)/10;
    }
    if(num1 == num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(carry) cout<<carry;
    cout<<s<<endl;
	return 0;
}
