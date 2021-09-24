#include <stdio.h>
#include <math.h>

int check(int x, int y, int n, int global[])
{
	for(int i = 0; i < n; i++)
	{
		if((x^y) == global[i]) //The brackets across the XOR is essential or else some shit happens
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int edges = n*pow(2, n-1);
	printf("\n%d\n", edges);
	
	int global[n];
	for(int i = 0; i < n; i++)
	{
		global[i] = pow(2, i);
	}
	
	for(int i = 0; i < pow(2, n); i++)
	{
		printf("%d: ", i);
		for(int j = i+1; j < pow(2, n); j++)
		{
			if(check(i, j, n, global) == 1)
			{
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	
	return 0;
}
