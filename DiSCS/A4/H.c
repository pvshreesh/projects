#include <stdio.h>
#include <string.h>

int isSameAsAnyOther(int N, int n, char myStr[], char strings[][10000])
{
	for(int i = 0; i < N; i++)
	{
		if(strcmp(myStr, strings[i]) != 0)
		{	
			if(strncmp(myStr, strings[i], n) == 0)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	char strings[N][10000];
	
	for(int i = 0; i < N; i++)
	{
		scanf("%s", strings[i]);
	}
	
	char myStr[10000];
	int lenReq[N];
	
	int isSame = 0;
	
	for(int i = 0; i < N; i++)
	{
		strcpy(myStr, strings[i]);		
		for(int j = 1; j <= strlen(myStr); j++)
		{
			if(!isSameAsAnyOther(N, j, myStr, strings))
			{
				lenReq[i] = j;
				break;
			}						
		}			
	
	}
	
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < lenReq[i]; j++)
		{
			printf("%c", strings[i][j]);
		}
		printf("\n");
	}	
		
	return 0;
}
