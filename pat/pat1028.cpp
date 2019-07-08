#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Student{
    char name[9];
    int id,grade;
};

bool comp1(Student a, Student b){
    return a.id < b.id;
}

bool comp2(Student a, Student b){
    if(strcmp(a.name,b.name)==0) return a.id < b.id;
    else if(strcmp(a.name,b.name)<0) return 1;
    else return 0;
}

bool comp3(Student a, Student b){
    if(a.grade == b.grade) return a.id < b.id;
    else return a.grade < b.grade;
}

vector<Student> stu;

int main()
{
    stu.clear();
    int n,c,i,j;
    cin>>n>>c;
    Student s;
    for(i=0; i<n; i++){
        cin>>s.id>>s.name>>s.grade;
        stu.push_back(s);
    }
    if(c==1) sort(stu.begin(), stu.end(), comp1);
    else if(c==2) sort(stu.begin(), stu.end(), comp2);
    else if(c==3) sort(stu.begin(), stu.end(), comp3);
    for(i=0; i<n; i++){
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    }
	return 0;
}
