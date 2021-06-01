#include <iostream>
using namespace std;

void max_heapify(int a[], int len, int i)
{
	int l = i << 1;
	int r = i << 1 | 1;
	int largest = 1;
	if (l <= len && a[l] > a[i])
	{
		largest = l;
	}
	else
		largest = i;
	if (r <= len && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a, len, largest);
	}
}
void buildheap(int a[], int len)
{
	for (int i = len / 2; i >= 1; i--)
	{
		max_heapify(a, len, i);
	}
}

void heapsort(int a[], int len)
{
	int size = len;
	buildheap(a, len);
	for (int i = 2; i <= size; i++)
	{
		int temp = a[len];
		a[len] = a[1];
		a[1] = temp;
		len--;
		max_heapify(a, len, 1);
	}
}
int main()
{
	int a[] = {0,7,4,9,6,8};
	heapsort(a, 5);
	for (int i = 1; i <= 5; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");
}
