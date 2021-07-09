#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> merge(vector<int> l, vector<int> r)
{
    auto i = l.begin();
    auto j = r.begin();
    vector<int> a;
    while (i != l.end() && j != r.end())
    {
        if (*i < *j)
        {
            a.emplace_back(*i);
            i++;
        }
        else
        {
            a.emplace_back(*j);
            j++;
        }
    }
    if (j != r.end())
    {
        a.insert(a.end(),j, r.end() );
    }
    else if (i != l.end())
    {
        a.insert(a.end(), i, l.end());
    }
    return a;
}

vector<int> mergesort(vector<int> a, int p, int r)
{
    if (p >= r)
    {
        return vector<int>{a[p]};
    }
    int q = (p + r) / 2;
    vector<int> left = mergesort(a, p, q);
    vector<int> right = mergesort(a, q + 1, r);
    return merge(left, right);
}

int main()
{
    vector<int> b = { 0, 2, 8, 10, 3, 6, 4,8,7 };
    vector<int> a = mergesort(b, 0, 8);
    for (int i : a)
    {
        printf("%d,", i);
    }
}
