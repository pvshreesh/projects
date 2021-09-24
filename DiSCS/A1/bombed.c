#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str[100000];
	scanf("%s", str);

	int nInput;
	scanf("%d", &nInput);

	char input[nInput][2];
	char trash;

	for(int i=0; i<nInput; i++)
		scanf("%c%c%c%c", &trash, &input[i][0], &trash, &input[i][1]);

	for(int i = 0; i<nInput; i++)
	{
		for (int j = 0; j < strlen(str); ++j)
		{
			if(str[j] == input[i][0])
				str[j] = input[i][1];
		}
	}
	printf("\n\n");
	printf("%s\n", str);
	
	return 0;
}