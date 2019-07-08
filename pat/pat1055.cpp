#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Person{
    char name[10];
    int age,worth;
};

vector<Person> people;

bool comp(Person a, Person b){
    if(a.worth==b.worth && a.age==b.age){
        if(strcmp(a.name,b.name) < 0) return 1;
        else return 0;
    }
    else if(a.worth==b.worth) return a.age < b.age;
    else return a.worth > b.worth;
}

int main()
{
    int n,k,i,j,m,amin,amax,flag;
    Person p;
    scanf("%d%d",&n,&k);
    for(i=0; i<n; i++) scanf("%s %d %d",p.name,&p.age,&p.worth),people.push_back(p);
    sort(people.begin(), people.end(), comp);
    for(i=1; i<=k; i++){
        flag = 1;
        printf("Case #%d:\n",i);
        scanf("%d%d%d",&m,&amin,&amax);
        for(j=0; j<n && m; j++){
            if(people[j].age>=amin && people[j].age<=amax){
                printf("%s %d %d\n",people[j].name,people[j].age,people[j].worth);
                m--;
                flag = 0;
            }
        }
        if(flag) printf("None\n");
    }
	return 0;
}
