#include <stdio.h>

int ind1 = 0;
int ind2 = 0;

void inorder(int N, int gph[][N], int node, int inArr[], int weights[], int indexArr[])
{
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == -1)
			inorder(N, gph, j, inArr, weights, indexArr);
	}
	
	indexArr[ind1++] = node;
	inArr[ind2++] = weights[node];	
	
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1)
			inorder(N, gph, j, inArr, weights, indexArr);
	}
}	

int main()
{
	int N;
	scanf("%d", &N);
	
	int gph[N][N];
	int weights[N];
	for(int i = 0; i < N; i++)
	{
		weights[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
		}
	}	
	
	int x, y; char trash, dir;
	for(int i = 0; i < N-1; i++)
	{
		scanf("%d%d%c%c", &x, &y, &trash, &dir);
		
		if(dir == 'L')
			gph[x][y] = -1;
		else
			gph[x][y] = 1;
	}
	
	for(int i =0; i < N; i++)
		scanf("%d", &weights[i]);
	
	int inArr[N];
	int indexArr[N];
	
	inorder(N, gph, 0, inArr, weights, indexArr);
	
	int first = -1, mid = -1, last = -1;
	int curr; int bool1 = 0;
	
	for(curr = 1; curr < N; curr++)
	{
		if(inArr[curr] < inArr[curr-1])
		{
			if(bool1 == 0)
			{
				first = curr-1;
				mid = curr;
				bool1 = 1;
			}
			else
			{
				last = curr;
			}
		}
	}
	
	if(last == -1)
		printf("%d %d\n", indexArr[first], indexArr[mid]);
		
	else 
		printf("%d %d\n", indexArr[first], indexArr[last]);			
	
	return 0;
}
