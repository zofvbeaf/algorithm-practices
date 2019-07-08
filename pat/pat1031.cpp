#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int len = s.length();
   int n1 = len/3,n3 = len/3, n2 = len-n1-n3; //不能n1=n2=n3
   if(len%3 == 0) { n1--;n3--;n2 +=2;}
   for(int i=0; i<n1; i++){
        cout<<s[i];
        for(int j=1; j<=n2-2; j++) cout<<" ";
        cout<<s[len-i-1]<<endl;
   }
   for(int i=n1; i<len-n1; i++) cout<<s[i];
   cout<<endl;
   return 0;
}
