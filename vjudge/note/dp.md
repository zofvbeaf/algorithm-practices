#动态规划    

##背包问题    

+ 01背包：  

```
for v : V->c[i]
    dp[v] = max(dp[v], dp[v-c[i]]+w[i])
```

+ 完全背包：  

```
for v : c[i]->V
    dp[v] = max(dp[v], dp[v-c[i]]+w[i])
```

+ 多重背包：
    