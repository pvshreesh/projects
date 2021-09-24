#include <stdio.h>
#include <string.h>

int count = 0;

void checkWord(int N, char str[][N], char inputStr[], int i, int j, int k)
{
	if(inputStr[k] == '\0')
	{
		count++;
		printf("count - %d\n", count);
	}
	
	else
	{	
		if(inputStr[k] == str[i+1][j] && (i+1) < N && j < N) //1
		{
			printf("%cv ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i+1, j, k+1);
			//k--;
		}
		if(inputStr[k] == str[i][j+1] && i < N && (j+1) < N) //2
		{
			printf("%c> ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i, j+1, k+1);
			//k--;
		}
		if(inputStr[k] == str[i+1][j+1] && (i+1) < N && (j+1) < N) //3
		{
			printf("%cv> ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i+1, j+1, k+1);
			//k--;
		}
		if(inputStr[k] == str[i-1][j] && (i-1) >= 0 && j < N) //4
		{
			printf("%c^ ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i-1, j, k+1);
			//k--;
		}
		if(inputStr[k] == str[i][j-1] && i < N && (j-1) >= 0) //5
		{
			printf("%c< ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i, j-1, k+1);
			//k--;
		}
		if(inputStr[k] == str[i-1][j-1] && (i-1) >= 0 && (j-1) >= 0) //6
		{
			printf("%c<^ ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i-1, j-1, k+1);
			//k--;
		}
		if(inputStr[k] == str[i+1][j-1] && (i+1) < N && (j-1) >= 0) //7
		{
			printf("%c<v ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i+1, j-1, k+1);
			//k--;
		}
		if(inputStr[k] == str[i-1][j+1] && (i-1) >= 0 && (j+1) < N) //8
		{
			printf("%c^> ", inputStr[k]);
			//k++;
			checkWord(N, str, inputStr, i+1, j+1, k+1);
			//k--;
		}
	}	
}	

int main()
{
	int N;
	scanf("%d", &N);
	
	char str[N][N];
	for(int i = 0; i < N; i++)
		scanf("%s", str[i]);
		
	int len;
	scanf("%d", &len);
	
	char inputStr[len];
	scanf("%s", inputStr);
	
	for(int i =0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(str[i][j] == inputStr[0])
			{
				//Check if other elements are adjacent to this letter
				//Adjacent can mean common edges and corners
				printf("In if\n");
				checkWord(N, str, inputStr, i, j, 1);
			}
		}
	}
	
	printf("\n%d\n", count);
	return 0;
}
