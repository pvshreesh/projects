#include <stdio.h>
#include <stdlib.h>

/*void print2DArr(int n, int mat[][n])
{
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}*/

int isReflexive(int n, int mat[][n])
{
	for (int i = 0; i < n; ++i)
	{
		if(mat[i][i] == 0)
		{
			return 0;
		}
	}
	return 1;
}

int isSymmetric(int n, int mat[][n])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(!(mat[i][j] ^ mat[j][i]) == 0)
				return 0;
		}
	}
	return 1;
}

int isTransitive(int n, int mat[][n])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(mat[i][j] && mat[j][k])
					if(!mat[i][k])
						return 0;
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n, nInput;
	scanf("%d%d", &n, &nInput);

	int mat[n][n];
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			mat[i][j] = 0;
		}
	}

	int x, y;

	for(int i = 0; i < nInput; i++)
	{
		scanf("%d%d", &x, &y);
		mat[x-1][y-1] = 1;
	}

	/*printf("\n");
	print2DArr(n, mat);
	printf("\n");*/

	if(isReflexive(n, mat)) printf("Reflexive\n");
	if(isSymmetric(n, mat)) printf("Symmetric\n");
	if(isTransitive(n, mat)) printf("Transitive\n");
	if(isReflexive(n, mat) && isSymmetric(n, mat) && isTransitive(n, mat)) 
		printf("Equivalence\n"); 

	return 0;
}
