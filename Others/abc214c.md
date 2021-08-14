## 思路
### What?
n个人围成一圈顺时针传递宝石。对于其中某个人i，他会在收到宝石之后延迟S[i]秒传递给下一个人。每个人会在T[i]时刻获得一块额外分发的宝石。  
### 目标
求每个人拿到宝石的最早时间。
## 思维模型
### 充分必要性
充分性：从题意背景思考场景特点，思考可以推导出什么。如每个人的宝石可以来自于左边，右边以及自己  
必要性：从目标出发思考求解问题的特点，思考必要条件是什么。其值为获得左边，右边及自己的宝石的最小值。然而右边本质上也是来自于左边。故需要比较左边和自己的最小值。  
难点是无法保证左边那个人的宝石一定是最小值。因为左边的最小值由来自于更左边和左边自己宝石的最小值。
### 体验法
根据分析到的条件模拟从已知条件到目标的全过程  
## 分析
如何保证左边的是最小值呢？那肯定是T[i]中的最小值了。T[min]可以保证左边的值不会比自身小。  
故从T[min]开始更新
所以对每个人来说需要来自两边的值，然而右边的值难以更新，故首先需要更新一圈左值。更新完后每个人都和来自其左边的宝石更新过了。当再更新一遍时就成了环。
```C++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector< vector<ll> >;
using vvi = vector< vector<int> >;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
template <typename T1, typename T2> inline void chmin(T1& x, T2 y) { if (x > y) x = y; }
template <typename T1, typename T2> inline void chmax(T1& x, T2 y) { if (x < y) x = y; }
int main()
{
    int n;
    cin >> n;
    vi S(n), T(n), ans(n), vis(n, 0);
    vvi index(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    for(int t = 0; t < 2; t++)
        for (int i = 0; i < n; i++)
        {
            int j = (i - 1 + n) % n;
            chmin(T[i], T[j] + S[j]);
        }
    for (const int& a : T)
    {
        printf("%d\n", a);
    }
}
```
