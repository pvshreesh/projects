#include <stdio.h>
#include <stdlib.h>

int isInArr(int elem, int n, int arr[])
{
	for (int i = 0; i < n; ++i)
	{
		if(elem == arr[i])
			return 1;
	}
	return 0;
}

void sort(int n, int arr[])
{
	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(n, arr);

	int max[n];
	int maxCount = 0;
	int elem;
	
	for (int i = 0; i < n; i++)
	{
		elem = arr[i];
		for (int j = i+1; j < n; j++)
		{
			if((arr[j] % elem) == 0)
			{
				elem = arr[j];
			} 
		}
		if(!isInArr(elem, maxCount, max))
		{
			max[maxCount++] = elem;
		}		
	}

	printf("\n");
	printf("%d\n", maxCount);
	sort(maxCount, max);

	for (int i = 0; i < maxCount; ++i)
	{
		printf("%d ", max[i]);
	}
	printf("\n");
	return 0;
}