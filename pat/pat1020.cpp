#include<iostream>
#include<queue>
using namespace std;

struct node{
    int id;
    node * l;
    node * r;
};

queue<node *> result;
vector<int> prin;

node * creatTree(int a[], int b[], int n){
    if(n<=0) return NULL;
    node * root = (node *)malloc(sizeof(node));
    root->id = a[n-1];
    root->l = root->r = NULL;
    int i;
    for(i=0; i<n; i++) if(b[i] == a[n-1]) break;
    root->l = creatTree(a,b,i);
    root->r = creatTree(a+i,b+i+1,n-i-1);
    return root;
}



int main()
{
    int n,a[32],b[32];
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    node * root = creatTree(a,b,n);
    result.push(root);
    while(result.size()){
        if(root->l) result.push(root->l);
        if(root->r) result.push(root->r);
        cout<<root->id;
        result.pop();
        if(result.size()) { cout<<" "; root = result.front();}
    }
    return 0;
}
