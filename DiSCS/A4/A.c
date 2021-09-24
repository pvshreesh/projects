#include <stdio.h>

int subWeight = 0;

int getSubWeight(int N, int gph[][N], int vis[], int weights[], int node, int src)
{
	subWeight += weights[node];
	vis[node] = 1;
	
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1 && !vis[j])
		{
			getSubWeight(N, gph, vis, weights, j, src);
		}
	}
	
	if(node == src)
	{
		return subWeight;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int gph[N][N];
	int vis[N];
	int weights[N];
	int subWeights[N];
	
	for(int i = 0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
		}
	}
	
	int x, y;
	for(int i = 0; i < N-1; i++)
	{
		scanf("%d%d", &x, &y);
		
		gph[x][y] = 1;
	}
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &weights[i]);
	}
	
	for(int i = 0; i < N; i++)
	{
		subWeights[i] = getSubWeight(N, gph, vis, weights, i, i);
		subWeight = 0;
		
		for(int i =0; i < N; i++)
			vis[i] = 0;
	}
	
	int min = subWeights[0];
	int minIndex = 0;
	
	for(int i =0; i < N; i++)
	{
		if(min > subWeights[i])
		{
			min = subWeights[i];	
			minIndex = i;
		}
	}
	
	printf("%d %d\n", minIndex, subWeights[minIndex]);
	
	return 0;
}


