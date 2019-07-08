#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seq;
vector<int> mirror;
vector<int> pre;
vector<int> post;

struct Node{
    int id;
    Node* l;
    Node* r;
};


void TreeInsert(Node* &t,int id){
    if(t == NULL){
        t = (Node *)malloc(sizeof(Node));
        t->id = id;
        t->l = NULL;
        t->r = NULL;
        return ;
    }
    if(id < t->id)
        TreeInsert(t->l,id);
    else TreeInsert(t->r,id);
}

void preorder(Node* &t){
    if(t == NULL) return;
    pre.push_back(t->id);
    preorder(t->l);
    preorder(t->r);
}

void mirrorpre(Node* &t){
    if(t == NULL) return;
    mirror.push_back(t->id);
    mirrorpre(t->r);
    mirrorpre(t->l);
}

void postrder(Node* &t){
    if(t == NULL) return;
    postrder(t->l);
    postrder(t->r);
    post.push_back(t->id);
}

void change(Node* &t){
    if(t == NULL) return;
    Node* temp = t->l;
    t->l = t->r;
    t->r = temp;
    change(t->l);
    change(t->r);
}

int main()
{
    Node* tree = NULL;
    int n,i,j;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>j;
        seq.push_back(j);
        TreeInsert(tree,j);
    }
    preorder(tree);
    mirrorpre(tree);
    if(seq == pre){
        cout<<"YES"<<endl;
        postrder(tree);
        cout<<post[0];
        for(i=1; i<n; i++) cout<<" "<<post[i];
    }
    else if(mirror == seq){
        cout<<"YES"<<endl;
        change(tree);
        postrder(tree);
        cout<<post[0];
        for(i=1; i<n; i++) cout<<" "<<post[i];
    }
    else cout<<"NO"<<endl;
	return 0;
}
