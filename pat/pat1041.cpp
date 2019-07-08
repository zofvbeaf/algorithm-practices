#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main(void){
    int n,i,j,re[10001];
    memset(re,0,sizeof(re));
    vector<int> ans;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>j;
        ans.push_back(j);
        re[j]++;
    }
    for(i=0; i<n; i++){
        if(re[ans[i]]==1){
            cout<<ans[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
	return 0;
}
