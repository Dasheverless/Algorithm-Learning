#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> countingsort(const vector<int>& a, int k)
{
    k++;
    vector<int> C(k,0),B(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        C[a[i]] ++;
    }
    for (int i = 1; i < k; i++)
    {
        C[i] = C[i - 1] + C[i];
    }
    for (int i = 0; i < a.size(); i++)
    {
        B[C[a[i]]-1] = a[i];
        C[a[i]] --;
    }
    return B;
}

int main()
{
    vector<int> b = { 5, 9, 0, 18, 2, 2, 4 };
    vector<int>::iterator m = max_element(b.begin(),b.end());
    vector<int> a = countingsort(b, *m);
    for (int i : a)
    {
        printf("%d,", i);
    }
}
