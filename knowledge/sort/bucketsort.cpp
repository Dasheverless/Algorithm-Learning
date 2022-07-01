#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> bucketsort(vector<int> a, int k)
{
    int n = a.size();
    int ma = *max_element(a.begin(), a.end());
    int mi = *min_element(a.begin(), a.end());
    int bnum = (ma - mi + 1) / k + 1;
    vector< vector<int> > buckets(bnum);
    for (int i = 0; i < n; i++)
    {
        buckets[(a[i] - mi) / k].emplace_back(a[i]);
    }
    for (int i = 0; i < bnum; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int m = 0;
    for (int i = 0; i < buckets.size(); i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            a[m++] = buckets[i][j];
        }
    }
    return a;
}

int main()
{
    vector<int> b = { 0, 2, 8, 10, 3, 6, 4,8,7 };
    vector<int> a = bucketsort(b, 3);
    for (int i : a)
    {
        printf("%d,", i);
    }
}
