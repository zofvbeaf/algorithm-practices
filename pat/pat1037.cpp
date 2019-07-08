#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<int> az;
priority_queue<int, vector<int>, greater<int> > af;
priority_queue<int> bz;
priority_queue<int, vector<int>, greater<int> > bf;

int main()
{
    int n,i,coun=0;
    cin>>n;
    while(n--){
        cin>>i;
        if(i>0) az.push(i);
        else if(i<0) af.push(i);
    }
    cin>>n;
    while(n--){
        cin>>i;
        if(i>0) bz.push(i);
        else if(i<0) bf.push(i);
    }

    while(az.size()>0 && bz.size()>0){
        coun += az.top()*bz.top();
        az.pop();
        bz.pop();
    }
    while(af.size()>0 && bf.size()>0){
        coun += af.top()*bf.top();
        af.pop();
        bf.pop();
    }
    cout<<coun<<endl;
	return 0;
}
