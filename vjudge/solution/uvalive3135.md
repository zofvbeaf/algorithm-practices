#[UVALive3135 Argus](https://vjudge.net/problem/UVALive-3135)
#SOLUTION
+ 维护一个优先队列，使得每次的得以快速找出最早发生的事件，队头time最小
#AC CODE
```c++
#include <cstdio>
#include <queue>
using namespace std;
struct Node {
    int qnum, period, time;
    bool operator < (const Node &a) const {
        return time > a.time || (time == a.time && qnum > a.qnum);
    }   
};
int main()
{
    int k;
    char s[10];
    priority_queue<Node> p;
    while(scanf("%s", s) && s[0] != '#'){
        Node node;
        scanf("%d%d", &node.qnum, &node.period);
        node.time = node.period;
        p.push(node);
    }
    scanf("%d", &k);
    while(k--){
        Node node = p.top();
        p.pop();
        printf("%d\n", node.qnum);
        node.time += node.period;
        p.push(node);
    }
    return 0;
}
```
