#include<bits/stdc++.h>

using namespace std;

const int MAXN= 1000000+1;
bool isPrime_[MAXN];
vector<int> primes;

void init(){
    isPrime_[2] = true;
    for(int i = 2 ; i < MAXN ;  i ++ ){
        isPrime_[i] = true;
    }
    for(int i = 2 ; i < MAXN ; i ++ ){
        if(isPrime_[i]&&i!=2) {
            primes.push_back(i);
            for(int j = i<<1 ; j < MAXN ; j += i ){
                isPrime_[j] = false;
            }
        }
    }
}
bool interesting(int x ){
    int ox= x ;
    int num_2 = 0 ;
    while(x>0&&x%2==0){
        x/=2;
        num_2++;
    }
    int num_o = 1 ; 
    vector<pair<int,int> > facts ;
    int sqrt_ox = sqrt(ox);
    for(int i = 0 ; x>1 && i < primes.size() && primes[i] <= sqrt_ox  && num_o < 10 ; i ++){
        int  t =0  ;
        while( x % primes[i] == 0 ){
            t++ ; 
            x /= primes[i] ; 
        }
        num_o *= t + 1 ; 
    }
    if(x>1){
        num_o *= 2 ;

    }
    return abs(num_2*num_o-num_o) <= 2 ;
}
int main(){
    init();
    int T;
    cin>>T;
    for(int case_ = 1 ; case_ <= T; case_++){
        int L ,R  ; 
        cin>>L>>R;
        int ans = 0 ; 
        for(int x = L ; x <= R ; x ++ ){
            if(interesting(x)) ans ++ ; 
        }
        printf("Case #%d: %d\n",case_,ans);
    }
    return 0 ;
}
