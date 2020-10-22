#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[6] = {4,8,15,16,23,42};
	int b[6];
	int times[15] = { 32,60,64,92,168,120,128,184,336,240,345,630,368,672,966 };
	int order[6];
	for (int i = 0; i < 4; i++ )
	{
		printf("? %d %d\n", i + 1, i + 2);
		cin >> b[i];
	}
	int x = 0, y = 0;
	int o1 = -1, o2 = -1,same;
	for (int i = 0; i < 4; i++)
	{
		x = 0;
		y = 0;
		for (int j = 0; j < 15; j++)
		{
			y++;
			if (y > 5)
			{
				x++;
				y = x + 1;
			}
			if (b[i] == times[j])
			{
				if (o1 == y)
				{
					order[i] = y;
					if (i == 1)
						order[i - 1] = o2;
					else if (i == 3)
						order[i + 1] = x;
				}
				else if (o1 == x)
				{
					order[i] = x;
					if (i == 1)
						order[i - 1] = o2;
					else if (i == 3)
						order[i + 1] = y;
				}
				else if(o2 == y)
				{
					order[i] = y;
					if (i == 1)
						order[i - 1] = o1;
					else if (i == 3)
						order[i + 1] = x;
				}
				else if(o2 == x)
				{
					order[i] = x;
					if (i == 1)
						order[i - 1] = o1;
					else if (i == 3)
						order[i + 1] = y;
				}
				o1 = x;
				o2 = y;
				break;
			}
		}
	}
	int sum = 15;
	std::cout << "!";
	for (int i = 0; i < 5; i++)
	{
		sum -= order[i];
		std::cout << " " << a[order[i]];
	}
	std::cout << " " << a[sum]<<"\n";
}
