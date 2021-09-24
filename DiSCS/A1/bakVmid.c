#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Use recursion

int main(int argc, char const *argv[])
{
	int nStudents;
	scanf("%d", &nStudents);

	char students[nStudents-2];
	char trash;
	int teamSize = (nStudents-2)/2;

	for (int i = 0; i < nStudents-2; ++i)
	{
		scanf("%c%c", &trash, &students[i]);
		if(students[i] == 'M' || students[i] == 'B')
			i--;
	}
	
	int len = nStudents - 2;
	
	int table[(int)pow(2, len)][len];
	
	int var = (int)pow(2, len);
	int bit = 1;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < pow(2, len); j++)
		{
			if(j % (var/2) == 0) {bit  = !bit;}
			
			table[j][i] = bit;
		}
		var /= 2;
	}
	
	int c0 = 0;
	int c1 = 0;
	
	for(int i = 0; i < pow(2, len); i++)
	{
		c0 = 0;
		c1 = 0;
		for(int j = 0; j < len; j++)
		{
			if(table[i][j] == 1) c1++;
			else c0++;			
		}
		if(c1 == c0)
		{
			printf("M: ");
			for(int j = 0; j < len; j++)
			{
				if(table[i][j] == 1) printf("%c ", students[j]);
			}
			printf("| B: ");
			for(int j = 0; j < len; j++)
			{
				if(table[i][j] == 0) printf("%c ", students[j]);
			}
			printf("\n");	
		}
	}	
	return 0;
}
