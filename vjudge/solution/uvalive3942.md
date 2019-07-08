#[UVALive3942 Remember the Word](https://vjudge.net/problem/UVALive-3942)
#SOLUTION
+ trie
#AC CODE
```c++
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1<<30;

struct Trie
{
    int ch[400010][26], val[400010];
    int sz; //节点总数

    void clear() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }   //初始时只有一个根节点
    int idx(char c) { return c - 'a'; }  //字符c的编号

    // 插入字符串s,附加信息为v,注意v必须非0，因为0代表“本结点不是单词结点”
    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if(!ch[u][c]) { //节点不存在
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0; // 中间节点的附加信息为0
                ch[u][c] = sz++;
            }
            u = ch[u][c]; //往下走
        }
        val[u] = v; // 字符串的最后一个字符的附加信息为v
    }

    // 找字符串s的长度不超过len的前缀
    void find_prefixes(char *s, int len, vector<int>& ans) {
        int u = 0;
        for(int i = 0; i < len && s[i]; i++) {
            int c = idx(s[i]);
            if(!ch[u][c]) break;
            u = ch[u][c];  //往下走
            if(val[u] != 0) ans.push_back(val[u]); // 找到一个前缀
        }
    }

}trie;

int main()
{
    char text[300010], word[110];
    int n, cnt = 1;
    int len[4010], d[300010];  //单词长度
    while(~scanf("%s%d", text, &n)) {
        trie.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%s", word);
            len[i] = strlen(word);
            trie.insert(word, i);
        }   
        memset(d, 0, sizeof(d));
        int L = strlen(text);
        d[L] = 1;
        for (int i = L-1; i >= 0; i--) {
            vector<int> p;
            trie.find_prefixes(text+i, L-i, p);
            for(int j = 0; j < p.size(); j++)
                d[i] = (d[i] + d[i + len[p[j]]]) % 20071027;
        }
        printf("Case %d: %d\n", cnt++, d[0]);
    }
    return 0;
}
```
