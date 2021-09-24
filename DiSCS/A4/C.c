#include <stdio.h>
#include <limits.h>

int cost = 0;
int bstBool = 1;

int isBST(int N, int gph[][N], int weight[], int node, int src)
{
	for(int j = 0; j < N; j++)
	{ 
		if(gph[node][j] == -1)
		{
			if(weight[j] >= weight[node])
				bstBool = 0;
		}
		if(gph[node][j] == 1)
		{
			if(weight[j] <= weight[node])
				bstBool = 0;
		}
		if(gph[node][j] == -1 || gph[node][j] == 1)
		{
			isBST(N, gph, weight, j, src);
		}
	}
	
	if(node == src)
	{
		if(bstBool == 0)
			return 0;
		else
			return 1;
	}
} 

int isLeaf(int N, int gph[][N], int node)
{
	int leaf = 1;
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1 || gph[node][j] == -1)
		{
			leaf = 0;
		}
	}
	
	return leaf;
}

void getSubWeight(int N, int gph[][N], int weight[], int subWeight[], int node)
{
	cost += weight[node];
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1 || gph[node][j] == -1)
		{
			getSubWeight(N, gph, weight, subWeight, j);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int weight[N];
	int gph[N][N];
	int subWeight[N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{	
			gph[i][j] = 0;
		}
	}
	
	int x, y; char dir, trash;
	for(int i = 0; i < N-1; i++)
	{
		scanf("%d%d%c%c", &x, &y, &trash, &dir);
		
		if(dir == 'L')
			gph[x][y] = -1;
		else if(dir == 'R')
			gph[x][y] = 1;
	}
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &weight[i]);
	}
	
	for(int i = 0; i < N; i++)
	{
		if(!isLeaf(N, gph, i))
		{
			getSubWeight(N, gph, weight, subWeight, i);
			subWeight[i] = cost;
			cost = 0;
		}
		else
			subWeight[i] = INT_MIN;
	}
	
	int max = INT_MIN;
	int maxIndex = -1;
	int found = 0;
	for(int i = 0; i < N; i++)
	{
		bstBool = 1;
		if(max < subWeight[i] && isBST(N, gph, weight, i, i))
		{
			found = 1;
			max = subWeight[i];
			maxIndex = i;
		}
	}
	
	if(!found)
		printf("No such node\n");
		
	else
		printf("%d\n", maxIndex);
	
	return 0;
}
