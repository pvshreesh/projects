#include <stdio.h>
#include <string.h>

int swap(int init, int final, char str[])
{
	char temp = str[init];
	str[init] = str[final];
	str[final] = temp;
}

void permute(int l, int r, char str[])
{
	if(l == r)
	{
		printf("%s\n", str);
	}
	
	for(int i = l; i <= r; i++)
	{
		swap(l, i, str);
		permute(l+1, r, str);
		swap(l, i, str);
	}
}

int main()
{
	char str[10];
	
	scanf("%s", str);
	printf("\n");
	permute(0, strlen(str)-1, str);	
	
	return 0;
}
