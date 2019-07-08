#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

bool comp(string a, string b){
    return a+b < b+a;
}

int main(){
    int n,i,j,flag=1;
    cin>>n;
    string a[n];
    for(i=0; i<n; i++) cin>>a[i];
    sort(a,a+n,comp);
    for(i=0; i<n; i++){
        for(j=0; j<a[i].length(); j++){
            if(flag && a[i][j]=='0') continue;
            flag = 0; cout<<a[i][j];
        }
    }
    if(flag) cout<<"0"<<endl;
	return 0;
}
