#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct People{
    int num,re,vip;
};

struct Table{
    int vip,coun,remain;
};

bool comp(People a, People b){
    return a.num < b.num;
}

bool comp2(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int INF = 1<<30;
int n,k,m;
vector<People> peoples;
vector<Table> tables;

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        People p;
        int hh,mm,ss;
        scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&p.re,&p.vip);
        p.num = hh*3600 + mm*60 + ss;
        if(p.num > 21*3600) continue;
        if(p.re > 120) p.re = 120;
        p.re *= 60;
        peoples.push_back(p);
    }
    n = peoples.size();
    sort(peoples.begin(), peoples.end(), comp);
    scanf("%d%d",&k,&m);

    for(i=0; i<k; i++){
        Table t;
        t.vip = 0;
        t.coun = 0;
        t.remain = 0;
        tables.push_back(t);
    }

    for(i=0; i<m; i++){
        scanf("%d",&j);
        tables[j-1].vip = 1;
    }

    int now = 8*3600;
    vector<pair<int,int> > result;
    vector<People> cur;
    vector<People>::iterator it;

    while(now < 21*3600 && !(peoples.empty() && cur.empty())){
        it = peoples.begin();
        while(!peoples.empty() && it->num <= now){  //需要排队
            cur.push_back(peoples[0]);
            peoples.erase(it);
            it = peoples.begin();

        }
        if(cur.empty()){
            if(!peoples.empty()){
                int past = now;
                now = peoples[0].num;
                for(i=0; i<k; i++){
                    tables[i].remain -= now - past;
                    if(tables[i].remain < 0) tables[i].remain = 0;
                }
                continue;
            }
        }

        for(i=0; i<k; i++){
            if(tables[i].remain==0 && tables[i].vip==1){
                it = cur.begin();
                while(it != cur.end()) {
                    if(it->vip == 1) break;
                    it++;
                }
                if(it == cur.end()) break;
                tables[i].remain = it->re;
                tables[i].coun++;
                result.push_back(make_pair(it->num,now));
                cur.erase(it);
            }
        }
        for(i=0; i<k; i++){
            it = cur.begin();
            if(it == cur.end()) break;
            if(tables[i].remain==0){
                tables[i].remain = it->re;
                tables[i].coun++;
                result.push_back(make_pair(it->num,now));
                cur.erase(it);
            }
        }
        int mmin = INF;
        for(i=0; i<k; i++) if(mmin > tables[i].remain) mmin = tables[i].remain;
        now += mmin;
        for(i=0; i<k; i++) tables[i].remain -= mmin;
    }

    sort(result.begin(), result.end(), comp2);
    int hh1,mm1,ss1,hh2,mm2,ss2,wait;
    for(i=0; i<result.size(); i++){
        hh1 = result[i].first/3600;
        mm1 = (result[i].first%3600)/60;
        ss1 = result[i].first%60;
        hh2 = result[i].second/3600;
        mm2 = (result[i].second%3600)/60;
        ss2 = result[i].second%60;
        wait = (result[i].second - result[i].first)/60;
        if((int)(result[i].second - result[i].first)%60 >= 30) wait++;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",hh1,mm1,ss1,hh2,mm2,ss2,wait);
    }
    printf("%d",tables[0].coun);
    for(i=1; i<k; i++) printf(" %d",tables[i].coun);
	return 0;
}
