#include <cstdio>
#include<math.h>
#include<string.h> //memset
using namespace std;

int main(){
    double a,b,c,n,a1,a2,a3;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a > b && a > c){
        a1 = a;
        printf("W ");
    }
    else if(b > a && b > c){
        a1 = b;
        printf("T ");
    }
    else if(c > a && c > b){
        a1 = c;
        printf("L ");
    }

    scanf("%lf%lf%lf",&a,&b,&c);
    if(a > b && a > c){
        a2 = a;
        printf("W ");
    }
    else if(b > a && b > c){
        a2 = b;
        printf("T ");
    }
    else if(c > a && c > b){
        a2 = c;
        printf("L ");
    }

    scanf("%lf%lf%lf",&a,&b,&c);
    if(a > b && a > c){
        a3 = a;
        printf("W ");
    }
    else if(b > a && b > c){
        a3 = b;
        printf("T ");
    }
    else if(c > a && c > b){
        a3 = c;
        printf("L ");
    }
    n = (a1*a2*a3*0.65-1)*2;
    printf("%.2f\n",n);
    return 0;
}
