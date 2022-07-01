#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>& a)
{
    int n = a.size();
    for(int i = 1; i < n; i ++)
    {
        int j = i - 1, cur = a[i];
        while(j >= 0 && cur < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }
}

int main()
{
    vector<int> a = {1,3,2,9,7};
    insertion_sort(a);
    
}
