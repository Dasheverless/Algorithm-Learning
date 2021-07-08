#include <iostream>
#include <vector>
using namespace std;

int cnt;
int partition(vector<int>& a, int p, int r)
{
    int i = p - 1;
    for (int j = p; j <= r; j++)
    {
        if (a[j] <= a[r])
        {
            cnt++;
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    return i;
}

void quicksort(vector<int>& a, int p, int r)
{
    while (p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        //quicksort(a, q + 1, r);
        p = q + 1;
    }
}

int main()
{
    vector<int> a = { 1, 3, 2, 7, 5, 6, 4 };
    quicksort(a, 0, a.size() - 1);
    for (int i : a)
    {
        printf("%d,", i);
    }
    printf("\n%d\n", cnt);
}
