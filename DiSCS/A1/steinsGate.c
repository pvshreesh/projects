#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int n, count, ans;
	int num;
	
	scanf("%d", &n);
	
	for(int i = 0; i < pow(2,n); i++)
	{	 
		count = 0;
		num = i;
		printf("%d: ", i);
		
		for(int j = 0; j < n; j++)
		{
			if(num % 2 == 0)
			{
				ans = i + pow(2, count);
				printf("%d ", ans);
			}
			
			count++;
			num = num/2;
		}
		printf("\n");
    }
}
