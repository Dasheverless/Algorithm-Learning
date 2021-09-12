## 树的标记
```C++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector< vector<ll> >;
using vvi = vector< vector<int> >;
using vvvi = vector<vector< vector<int> >>;
const ll MOD = 1e9 + 7;
const int MAXN = 1e9 + 1;
template <typename T1, typename T2> inline void chmin(T1& x, T2 y) { if (x > y) x = y; }
template <typename T1, typename T2> inline void swapmin(T1& x, T2& y) { if (x > y) swap(x, y); }
template <typename T1, typename T2> inline void chmax(T1& x, T2 y) { if (x < y) x = y; }
template <typename T1, typename T2> inline void swapmax(T1& x, T2& y) { if (x < y) swap(x, y); }

template <typename T1>
T1 gcd(T1 x, T1 y)
{
    return y ? gcd(y, x % y) : x;
}
template <typename T1>
T1 lcm(T1 x, T1 y)
{
    return x * y / gcd(x, y);
}

class BITree
{
public:
    BITree(int n)
        :n(n), tree(n)
    {}
    ll prefixSum(int i)
    {
        ll s = 0;
        while (i >= 1)
        {
            s = (s + tree[i]) % MOD;
            i -= i & -i;
        }
        return s;
    }
    ll rangeSum(int i, int j)
    {
        if (i >= j)
            return 0;
        return (prefixSum(j - 1) - prefixSum(i) + MOD) % MOD;
    }
    void add(int i, ll val)
    {
        while (i <= n)
        {
            tree[i] = (tree[i] + val + MOD) % MOD;
            i += i & -i;
        }
    }
public:
    int n;
    vl tree;
};

int n, timer;
vi st, ed;
vvi graph;
void dfs(int u)
{
    st[u] = timer++;
    for (const int& v : graph[u])
    {
        dfs(v);
    }
    ed[u] = timer;
}

void solve()
{
    cin >> n;
    vector<pair<int, int>> a(n);
    graph.clear();
    graph.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        graph[x].emplace_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    st.clear();st.resize(n + 1);
    ed.clear();ed.resize(n + 1);
    timer = 1;
    dfs(1);
    BITree sub(2 * n + 1), anc( 2 * n + 1);
    ll cur = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = a[i].second;
        cur = 0;
        cur = (cur + sub.rangeSum(st[u], ed[u]) + anc.prefixSum(st[u])) % MOD;
        ans = (ans + cur) % MOD;
        sub.add(st[u], cur + 1);
        anc.add(st[u], cur + 1);
        anc.add(ed[u], -cur - 1);
    }
    printf("%lld\n", ans);
}
int main()
{
    int q = 1;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> q;
    while(q--)
    {
        solve();
    }
}
```
