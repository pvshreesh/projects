#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int swap(int i, int j)
{
	int temp = i;
	i = j;
	j = temp;
}

int main()
{
	int n, gift;
	scanf("%d%d", &n, &gift);

	int wishlist[n];
	for(int i=0; i<n; i++)
		scanf("%d", &wishlist[i]);

	int table[(int)pow(2, n)][n];
	int bit = 1;
	int b=(int)pow(2, n)/2;
	
	//Making a truth table
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < pow(2, n); j++)
		{
			if(j % b == 0) bit = !bit;

			table[j][i] = bit;
		}
		b /= 2;
	}

	int totalCost[(int)pow(2, n)];
	//Intialising all values in cost to zero
	for (int i = 0; i < pow(2, n); ++i)
	{
		totalCost[i] = 0;
	}

	//Finding costs of all possible subsets
	for(int i = 0; i < pow(2, n); i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(table[i][j])
			{
				totalCost[i] += wishlist[j];
			}
		}
	}

	int maxCost = 0;
	for (int i = 0; i < pow(2, n); ++i)
	{
		if(totalCost[i] <= gift && totalCost[i] > maxCost)
			maxCost = totalCost[i];
	}

	int maxIndex;
	for (int i = 0; i < pow(2, n); ++i)
	{
		if(totalCost[i] == maxCost)
		{
			maxIndex = i;
			break;
		}

	}
	int numberOfItems = 0;
	//Now printing what are the elements we need to choose
	for(int j = 0; j<n; j++)
	{
		if(table[maxIndex][j])
			numberOfItems++;
	}

	printf("\n");
	printf("%d\n", numberOfItems);
	for(int j = 0; j<n; j++)
	{
		if(table[maxIndex][j])
			printf("%d ", j+1);
	}
	printf("\n");

	return 0;
}