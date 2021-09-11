## 每次问自己：这样对吗？只能这样吗？这样就够了吗？这样之后呢？
```C++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector< vector<ll> >;
using vvi = vector< vector<int> >;
using vvvi = vector<vector< vector<int> >>;
const ll MOD = 998244353;
const int MAXN = 400;
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

ll qpow(ll a, ll b)
{
    ll ans = 1;
    b %= MOD;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = ( a * a ) % MOD;
        b >>= 1;
    }
    return ans;
}

ll fac[MAXN + 1], ifac[MAXN + 1];
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (i * fac[i - 1]) % MOD;
    }
    ifac[MAXN] = qpow(fac[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--)
    {
        ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
    }
}

ll C(int n, int k)
{
    if (k > n)
        return 0;
    ll inv = (ifac[n - k] * ifac[k]) % MOD;
    return (fac[n] * inv) % MOD;
}

ll modMulti(ll a, ll b, ll c = 1, ll d = 1)
{
    return (((((a * b) % MOD) * c ) % MOD ) * d ) % MOD;
}
int n, m;
void solve()
{
    cin >> n >> m;
    n = 2 * n;
    vvl pair(n + 1, vl(n + 1));
    vvl dp(n + 1, vl(n + 1));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pair[a][b] = pair[b][a] = 1;
    }
    for (int r = 1; r <= n; r++)
    {
        dp[r][r-1] = 1;
        for (int l = r - 1; l >= 1; l -= 2)
        {
            if (pair[l][r])
            {
                dp[l][r] = dp[l + 1][r - 1];
            }
            for (int k = l + 1; k <= r - 2; k += 2) if(pair[l][k])
            {
                dp[l][r] = (dp[l][r] + modMulti(dp[l+1][k-1], dp[k + 1][r], C((r - l + 1) / 2, (k - l + 1) / 2))) % MOD;
            }
        }
    }
    printf("%lld\n", dp[1][n]);
}
int main()
{
    int q = 1;
    cin.tie(0);
    ios::sync_with_stdio(0);
    init();
    //cin >> q;
    while (q--)
    {
        solve();
    }
}
```
