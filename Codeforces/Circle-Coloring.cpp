#include <iostream>

int main()
{
	int set_size,num_size;
	std::cin >> set_size;
	int** ans = new int*[set_size];
	int* nums_size = new int[set_size];
	for (int i = 0; i < set_size; i++)
	{
		std::cin >> num_size;
		nums_size[i] = num_size;
		ans[i] = new int[num_size];
		int* a = new int[num_size];
		int* b = new int[num_size];
		int* c = new int[num_size];
		for (int k = 0; k < num_size; k++)
		{
			std::cin >> a[k];
		}
		for (int k = 0; k < num_size; k++)
		{
			std::cin >> b[k];
		}
		for (int k = 0; k < num_size; k++)
		{
			std::cin >> c[k];
		}
		int same = a[0];
		ans[i][0] = same;
		int temp;
		for (int k = 1; k < num_size; k++)
		{
			if (k == num_size - 1)
			{
				if (a[k] != ans[i][0] && a[k] != same)
					ans[i][k] = a[k];
				else if (b[k] != ans[i][0] && b[k] != same)
					ans[i][k] = b[k];
				else if (c[k] != ans[i][0] && c[k] != same)
					ans[i][k] = c[k];
				else
					ans[i][k] = 0;
				break;
			}
			if (same != a[k])
			{
				ans[i][k] = a[k];
				same = a[k];
			}
			else if (same != b[k])
			{
				ans[i][k] = b[k];
				same = b[k];
			}
			else if (same != c[k])
			{
				ans[i][k] = c[k];
				same = c[k];
			}
			else
			{
				ans[i][k] = 0;
				break;
			}
		}
		delete[] a, b, c;
	}
	for (int i = 0; i < set_size; i++)
	{
		for (int j = 0; j < nums_size[i]; j++)
		{
			if (ans[i][j] == 0)
				break;
			std::cout << ans[i][j] <<" ";
		}
		std::cout << "\n";
	}
}
