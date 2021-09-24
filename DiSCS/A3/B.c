#include<stdio.h>

int sumArr[1000];
int numPath = 0;
int pathArr[1000][64];
int pathLenArr[1000];

int inParentArr(int node, int N, int parent[])
{
	for(int i = 0; i < N; i++)
	{
		if(node == parent[i])
			return 1;
	}
	return 0;
}

void calculateCost(int N, int gph[][N], int weight[], int node)
{
	sumArr[numPath] += weight[node];
	pathArr[numPath][pathLenArr[numPath]++] = node;
	if(node == 0)
		numPath++;
	
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1)
		{
			calculateCost(N, gph, weight, j);
		}
	}
}

int main()
{
	for(int i = 0; i < 1000; i++)
	{
		sumArr[i] = 0;
		pathLenArr[i] = 0;
	}
	
	int N;
	scanf("%d", &N);
	
	int gph[N][N];
	int weight[N];
	int vis[N];
	
	for(int i = 0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
		}
	}
	
	int parent[N-1];
	for(int i = 1; i < N; i++)
	{
		scanf("%d", &parent[i]);
		gph[i][parent[i]] = 1;
	}
	
	int wt;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &wt);
		weight[i] = wt;
	}
	
	int targetCost;
	scanf("%d", &targetCost);
	
	for(int node = 0; node < N; node++)
	{
		if(!inParentArr(node, N, parent))
		{
			calculateCost(N, gph, weight, node);
		}
	}
	
	for(int i = 0; i < numPath; i++)
	{
		if(sumArr[i] == targetCost)
		{
			for(int j = pathLenArr[i]-1; j >=0 ; j--)
			{
				printf("%d ", pathArr[i][j]);
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
