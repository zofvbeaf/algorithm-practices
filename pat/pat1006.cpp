#include <iostream>
#include<map>
#include<string.h> //memset
using namespace std;

int main(){
    int n;
    string a,b,c,d,e,f,g,h;
    cin>>n;
    cin>>a>>b>>c;
    g = a;
    h = a;
    n--;
    while(n--){
        cin>>d>>e>>f;
        if(e<b){
            b = e; g = d; //sign in
        }
        if(f>c){
            c = f; h = d; //sign out
        }
    }
    cout<<g<<" "<<h<<endl;
    return 0;
}
