#include <stdio.h>
#include <string.h>

void rotateStr(int len, char str[])
{
	char temp = str[0];
	for(int i = 0; i < len-1; i++)
		str[i] = str[i+1];
		
	str[len-1] = temp;
}

int isPalindrome(int len, char str[])
{
	for(int i = 0; i < len/2; i++)
	{
		if(str[i] != str[len-i-1])
			return 0;
	}
	return 1;
}

int main()
{
	char inputStr[1000];
	scanf("%[^\n]s", inputStr);
	
	char str[10][100];
	
	int strIndex = 0;
	int y = 0;
	
	for(int i = 0; i < strlen(inputStr); i++)
	{	
		if(inputStr[i] != ' ')
		{
			str[strIndex][y] = inputStr[i];
			y++;
		}
		else
		{
			str[strIndex][y] = '\0';
			strIndex++;
			y = 0;
		}	
	}
	
	
	for(int i = 0; i <= strIndex; i++)
	{
		for(int j = 0; j < strlen(str[i]); j++)
		{
			rotateStr(strlen(str[i]), str[i]);
			if(isPalindrome(strlen(str[i]), str[i]))
				printf("%s ", str[i]);
			
		}
	}
	printf("\n");
	return 0;
}