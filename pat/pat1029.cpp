#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<long int> num;

int main()
{
    long int n,m;
    scanf("%ld",&m);
    while(m--){
        scanf("%ld",&n);
        num.push_back(n);
    }
    scanf("%ld",&m);
    while(m--){
        scanf("%ld",&n);
        num.push_back(n);
    }
    sort(num.begin(), num.end(), less<long int>());
    n = num.size()/2 + num.size()%2;
    cout<<num[n-1]<<endl;
	return 0;
}
