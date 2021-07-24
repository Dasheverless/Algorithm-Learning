#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;

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
