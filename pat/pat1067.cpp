#include<cstdio>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
struct Node{
    Node *ch[2]; //sub[0] : left  sub[1] : right
    int v;
    int h;
    int cmp(int x) const{
   //     if(x==v) return -1;
    //    else return x > v;  // 1 右边
        return x > v;  // 1 右边
    }
};

int geth(Node* &o){
	if(o==NULL) return 0;
	return o->h;
}

void single_rotate(Node* &o, int d){ //0： RR 1: LL
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->h = max(geth(o->ch[0]), geth(o->ch[1]))+1;
    k->h = max(geth(k->ch[0]), geth(k->ch[1]))+1;
    o = k;
}

void double_rotate(Node* &o, int d){  //0 ：RL 1: LR
    Node* k = o->ch[d^1];  //RL:  o->right
    single_rotate(k,d^1); //RL:  o->right :LL
    o->ch[d^1] = k;
    single_rotate(o,d);
}



int isBalance(Node* &o){
    return abs(geth(o->ch[0]) - geth(o->ch[1]))<2;
}

void insert(Node* &o, int x){
    if(o==NULL) {
        o = new Node();
        o->ch[0] = o->ch[1] = NULL;
        o->v = x;
        o->h = 0;
        o->h = max(geth(o->ch[0]), geth(o->ch[1]))+1;
    }
    else{
        int d = o->cmp(x);
        insert(o->ch[d], x);
        o->h = max(geth(o->ch[0]), geth(o->ch[1]))+1;
//		o->h = max(geth(o->ch[0]), geth(o->ch[1]))+1;
        if(!isBalance(o)){
            if((x < o->ch[d]->v)^d) single_rotate(o,d^1);
            else double_rotate(o,d^1);
        }
    }

}

int main(){
//    freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
    int n,x;
    Node *root = NULL;
    scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		insert(root,x);
	}
    printf("%d",root->v);
    return 0;
}
