#include<iostream>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
int n;
string a,b,c;

string change(int x){
    string s="";
    if(x<0) s += "-" , x = -x;
    if(x>10) s += x/10 + '0';
    s += x%10 + '0';
    return s;
}

string get(){
    cin>>c;
    int i,j,nz = -1;
    int len = c.size();
    int p = len;
    string s = "0.";
    for(i=0; c[i]; i++) {
        if(c[i]=='.') p = i;
        else if(c[i]!='0' && nz<0) nz = i;
    }
    if(nz==-1){
        for(i=0; i<n; i++) s += "0";
        s += "*10^0";
        return s;
    }
    if(p==len){
        for(i=0; i<n; i++)
            if(i+nz < p) s += c[i+nz];
            else s += "0";
        s += "*10^" + change(p-nz);
        return s;
    }
    if(p<len){
        for(i=0; s.size() < n+2; i++){
            if(c[i+nz]=='.') continue;
            if(i+nz < len) s += c[i+nz];
            else s += "0";
        }
        s += "*10^" + change(p-nz + (p<=nz));
        return s;
    }

}

int main()
{
    cin>>n;
    a = get();
    b = get();
    if (a == b) cout << "YES " << a << endl;
	else cout << "NO " << a << " " << b << endl;
	return 0;
}
