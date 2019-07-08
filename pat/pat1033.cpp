#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

double cmax,D,Davg,cdmax,remain,cost;
int n, INF = 1<<30;

struct Station{
    double price;
    int dist;
};

vector<Station> stations;

bool comp(Station a, Station b){
    return a.dist < b.dist;
}
int main(){
    int i,j,flag = 0;
    scanf("%lf%lf%lf%d",&cmax,&D,&Davg,&n);
    cdmax = cmax * Davg;
    remain = cost = 0;
    for(i=0; i<n; i++){
        Station s;
        scanf("%lf%d",&s.price,&s.dist);
        stations.push_back(s);
    }
    sort(stations.begin(), stations.end(),comp);
    if(stations[0].dist != 0){ printf("The maximum travel distance = 0.00\n"); return 0; }

    for(i=0; i<n; i++){
        flag = 0;
        if(i==n-1){
            if(stations[i].dist+cdmax < D){ printf("The maximum travel distance = %.2lf\n",stations[i].dist+cdmax); return 0; }
            else{
                if(D-stations[i].dist > remain)
                    cost += (D-stations[i].dist-remain)*stations[i].price/Davg;
                printf("%.2lf\n",cost);
                return 0;
            }
        }
        for(j=i+1; j<n && stations[j].dist<stations[i].dist+cdmax; j++){
            if(stations[j].price<=stations[i].price){
                if(remain < (stations[j].dist-stations[i].dist)){
                    cost += (stations[j].dist-stations[i].dist-remain)*stations[i].price/Davg;
                    remain = stations[j].dist-stations[i].dist;
                }
                flag = 1;
                break;
            }
        }
        if(flag==0){
            if(stations[i].dist+cdmax > D){
                cost += (D-stations[i].dist-remain)*stations[i].price/Davg;
                remain = D-stations[i].dist;
            }
            else{
                cost += (cdmax-remain)*stations[i].price/Davg;
                remain = cdmax;
            }
        }
        remain -= stations[i+1].dist-stations[i].dist;
    }
    printf("%.2lf\n",cost);
	return 0;
}
