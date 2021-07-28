#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
/*
思路：
    1. 广度优先搜索，禁止访问上一层节点得到最短路径
    2. 动态规划记录路径数
关键：
    1.队列模拟广度优先搜索
    2.动态规划递推
下次：
    1.动态规划路径数递推式：dp[son] += dp[fa];dp[1] = 1;
    2.队列模拟广度优先搜索，迭代。
*/
int main()
{
    int  n, m;
    cin >> n >> m;
    vector<vector<int>> tree(n+1);
    vector<int> dp(n + 1, 0);
    vector<int> depth(n+1,0);
    dp[1] = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    queue<int> q;
    q.push(1);
    ll ans = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int son : tree[parent])
        {
            if (depth[son] == 0)
            {
                q.push(son);
                depth[son] = depth[parent] + 1;
            }
            if (depth[son] == depth[parent] + 1)
            {
                dp[son] += dp[parent];
                dp[son] %= mod;
                if (son == n)
                {
                    ans++;
                    ans %= mod;
                }
            }
        }
    }
    cout << dp[n] << '\n';
}
