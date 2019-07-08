#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

string turn(string a){
    int len = a.length();
    string b = "";
    for(int i=0; i<len; i++){
        b = b + a[len-1-i];
    }
    return b;
}

string add(string a, string b){
    int carry = 0,len = a.length(),temp=0;
    char c[len];
    while(len--){
        temp = a[len] + b[len] - '0' - '0' + carry;
        c[len] = temp%10 + '0';
        carry = temp/10;
    }
    string cc = "";
    for(int i=0; i<a.length(); i++) cc = cc + c[i];
    if(carry) {
        char t = carry + '0';
        cc = t + cc;
    }

    return cc;
}

bool comp(string a){
    int i,len = a.length();
    for(i=0; i<len; i++){
        if(a[i] != a[len-1-i]) return 0;
    }
    return 1;
}

int main()
{
    string a,b;
    int k,i=0;
    cin>>a>>k;
    int len = a.length();
    for(i=0; i<k; i++){
        if(comp(a)) break;
        a = add(a,turn(a));
    }
    cout<<a<<endl;
    cout<<i<<endl;
	return 0;
}
