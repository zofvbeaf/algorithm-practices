#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Test{
    string id;
    int score,loca,lrank,grank;
};

vector<Test> tests;
vector<Test> testsss;
bool comp(Test a, Test b){
    if(a.score == b.score) return a.id < b.id;
    else return a.score > b.score;
}

int main()
{
    int n,m,i,j;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>m;
        for(j=0; j<m; j++){
            Test t;
            cin>>t.id;
            cin>>t.score;
            t.loca = i;
            t.lrank = t. grank = 0;
            tests.push_back(t);
        }
        sort(tests.begin(),tests.end(),comp);
        for(j=0; j<m; j++){
            if(j!=0 && tests[j].score == tests[j-1].score) tests[j].lrank = tests[j-1].lrank;
            else tests[j].lrank = j+1;
            Test t = tests[j];
            testsss.push_back(t);
        }
        tests.clear();
    }
    sort(testsss.begin(),testsss.end(),comp);
    cout<<testsss.size()<<endl;
    for(j=0; j<testsss.size(); j++){
        if(j!=0 && testsss[j].score == testsss[j-1].score) testsss[j].grank = testsss[j-1].grank;
        else testsss[j].grank = j+1;
        cout<<testsss[j].id<<" "<<testsss[j].grank<<" "<<testsss[j].loca<<" "<<testsss[j].lrank<<endl;
    }
	return 0;
}
