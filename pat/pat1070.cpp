#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

struct Cake{
    double p,price,num;
    bool operator < (const Cake &a)const{
        return p > a.p;
    }
};

int main(){
//  freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
    int n,i,j;
    double d;
    double ans = 0;
    scanf("%d%lf",&n,&d);
    vector<Cake> cakes;
    Cake a;
    for(i=0; i<n; i++) scanf("%lf", &a.num), cakes.push_back(a);
    for(i=0; i<n; i++) scanf("%lf", &cakes[i].price), cakes[i].p = cakes[i].price/cakes[i].num;
    sort(cakes.begin(), cakes.end());
    for(i=0; i<n; i++){
        if(cakes[i].num >= d){
            ans += cakes[i].price*d / cakes[i].num;
            break;
        }
        ans += cakes[i].price;
        d -= cakes[i].num;
    }
    printf("%.2lf\n",ans);
	return 0;
}
