#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int n,l,h;
struct Person{
    int id,v,t,tot;
};

bool comp(Person a, Person b){
    if(a.tot == b.tot){
        if(a.v == b.v) return a.id < b.id;
        else return a.v > b.v;
    }
    else return a.tot > b.tot;
}

vector<Person> sage;
vector<Person> noble;
vector<Person> fool;
vector<Person> small;

int main()
{
    int i,j;
    Person p;
    scanf("%d%d%d",&n,&l,&h);
    for(i=0; i<n; i++){
        scanf("%d %d %d",&p.id,&p.v,&p.t);
        if(p.v<l || p.t<l) continue;
        p.tot = p.v + p.t;
        if(p.v>=h && p.t>=h) sage.push_back(p);
        else if(p.v>=h && p.t<h) noble.push_back(p);
        else if(p.v >= p.t) fool.push_back(p);
        else small.push_back(p);
    }
    n = sage.size() + noble.size() + fool.size() + small.size();
    printf("%d\n",n);
    sort(sage.begin(), sage.end(), comp);
    sort(noble.begin(), noble.end(), comp);
    sort(fool.begin(), fool.end(), comp);
    sort(small.begin(), small.end(), comp);
    for(i=0; i<sage.size(); i++) printf("%08d %d %d\n",sage[i].id,sage[i].v,sage[i].t);
    for(i=0; i<noble.size(); i++) printf("%08d %d %d\n",noble[i].id,noble[i].v,noble[i].t);
    for(i=0; i<fool.size(); i++) printf("%08d %d %d\n",fool[i].id,fool[i].v,fool[i].t);
    for(i=0; i<small.size(); i++) printf("%08d %d %d\n",small[i].id,small[i].v,small[i].t);

	return 0;
}
