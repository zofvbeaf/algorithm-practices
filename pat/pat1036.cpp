#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Student{
    string name,id;
    int grade;
};

vector<Student> male;
vector<Student> female;
int n;
bool comp1(Student a, Student b){
    if(a.grade == b.grade) return a.name < b.name;
    return a.grade < b.grade;
}

bool comp2(Student a, Student b){
    if(a.grade == b.grade) return a.name < b.name;
    return a.grade > b.grade;
}

int main()
{
    cin>>n;
    while(n--){
        Student s;
        char c;
        cin>>s.name>>c>>s.id>>s.grade;
        if(c=='M') male.push_back(s);
        else if(c=='F') female.push_back(s);
    }
    sort(male.begin(), male.end(), comp1);
    sort(female.begin(), female.end(), comp2);
    if(male.size()==0 || female.size()==0){

        if(male.size()==0){
            cout<<female[0].name<<" "<<female[0].id<<endl;
            cout<<"Absent"<<endl;
        }
        else {
            cout<<"Absent"<<endl;
            cout<<male[0].name<<" "<<male[0].id<<endl;
        }
        cout<<"NA"<<endl;
        return 0;
    }
    cout<<female[0].name<<" "<<female[0].id<<endl;
    cout<<male[0].name<<" "<<male[0].id<<endl;
    cout<<(female[0].grade - male[0].grade)<<endl;

    return 0;
}
