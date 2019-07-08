#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,a[55],b[55],c[55],d[55];
    char card[5] = {'S','H','C','D','J'};
    cin>>n;
    for(i=1; i<=54; i++){ cin>>a[i]; c[a[i]] = i;d[i] = i; b[i] = a[i];}
    n--;
    while(n--){
        for(i=1; i<=54; i++)   b[a[i]] = d[i];
        for(i=1; i<=54; i++)   d[i] = b[i];
    }
    cout<<card[(c[d[1]]-1)/13]<<((c[d[1]]-1)%13+1);
    for(i=2; i<=54; i++){
        cout<<" "<<card[(c[d[i]]-1)/13]<<((c[d[i]]-1)%13+1);
    }
	return 0;
}
