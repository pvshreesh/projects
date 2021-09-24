#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int len)
{
	int s, temp;
	for(int i = 0; i<len-1; i++)
	{
		for(int j = i+1; j< len; j++)
		{
			if(arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int nitems, gift;
	scanf("%d%d", &nitems, &gift);
	int cost[nitems];
	for(int i=0; i<nitems; i++)
		scanf("%d", &cost[i]);

	//sort(cost, nitems);

	int sum = 0;
	int count = 0;
	int index[nitems];
	int diff = gift, flag = 1;
	int oldDiff = gift;

	while(1)
	{
		for(int i =0; i<nitems; i++)
		{
			if(cost[i] > sum && cost[i] <= gift)
			{	
				sum = cost[i];
				index[count] = i;
			}	
		}
		count++;

		diff = gift - sum;
		flag = (diff < oldDiff)? 1:0;
		oldDiff = diff;

		if(!flag) break;
	}

	printf("%d\n", sum);
	printf("%d\n", count);
	return 0;
}