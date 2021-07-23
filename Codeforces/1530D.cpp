#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
/*******
思路：

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
