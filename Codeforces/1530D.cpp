#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
/*******
思路：
    1.分为两组，送的和收的
    2.先满足一批，剩下的再重新安排
    3.记录送失败的和收失败的，两两匹配即可
    4.如果碰到一样的就先满足一个，挤出来的再安排剩下的
关键：
    1.理清本质：记录失败的收的和送的即可
    2.碰到一样的怎么办？
下次：
    1.理清头绪再开始写代码，不然越写越乱
    2.步步为营一步一步解决问题。
*******/
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n),b(n,-1), c(n, -1),cnt(n),fail_send,fail_rec;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] --;
            cnt[a[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (c[a[i]] < 0)
            {
                b[i] = a[i];
                c[a[i]] = i;
                ans++;
            }
            else
            {
                fail_send.emplace_back(i);
            }
            if (cnt[n-i-1] == 0)
            {
                fail_rec.emplace_back(n - i - 1);
            }
        }
        for (int i = 0; i < fail_send.size(); i++)
        {
            if (fail_send[i] == fail_rec[i])
            {
                b[fail_send[i]] = a[fail_send[i]];
                b[c[a[fail_send[i]]]] = fail_rec[i];
                continue;
            }
            b[fail_send[i]] = fail_rec[i];
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << b[i] + 1<< ' ';
        }
        cout << '\n';
    }
}
