#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Stu{
    int id,C,M,E,A;
};

bool sortByC(Stu a, Stu b) { return a.C > b.C; }
bool sortByM(Stu a, Stu b) { return a.M > b.M; }
bool sortByE(Stu a, Stu b) { return a.E > b.E; }
bool sortByA(Stu a, Stu b) { return a.A > b.A; }

int main(){
    vector<Stu> students;
    map<int,char> mtype;
    map<int,int> mrank;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        Stu s;
        cin>>s.id>>s.C>>s.M>>s.E;
        s.A = (s.C + s.M + s.E) /3;
        students.push_back(s);
    }

    int score = -1, ran = 0;
    sort(students.begin(),students.end(),sortByA);
    for(int i=0; i<n; i++){
        if(students[i].A != score) ran = i+1;
        score = students[i].A;
        mtype[students[i].id] = 'A';
        mrank[students[i].id] = ran;
    }

    score = -1, ran = 0;
    sort(students.begin(),students.end(),sortByC);
    for(int i=0; i<n; i++){
        if(students[i].C != score) ran = i+1;
        score = students[i].C;
        if(ran < mrank[students[i].id]){
            mtype[students[i].id] = 'C';
            mrank[students[i].id] = ran;
        }
    }

    score = -1, ran = 0;
    sort(students.begin(),students.end(),sortByM);
    for(int i=0; i<n; i++){
        if(students[i].M != score) ran = i+1;
        score = students[i].M;
        if(ran < mrank[students[i].id]){
            mtype[students[i].id] = 'M';
            mrank[students[i].id] = ran;
        }
    }

    score = -1, ran = 0;
    sort(students.begin(),students.end(),sortByE);
    for(int i=0; i<n; i++){
        if(students[i].E != score) ran = i+1;
        score = students[i].E;
        if(ran < mrank[students[i].id]){
            mtype[students[i].id] = 'E';
            mrank[students[i].id] = ran;
        }
    }

    while(m--){
        int q;
        cin>>q;
        if(mtype.count(q)) cout<<mrank[q]<<" "<<mtype[q]<<endl;
        else cout<<"N/A"<<endl;
    }
    return 0;
}
