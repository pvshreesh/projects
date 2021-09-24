#include <stdio.h>

int dist[10000];
int numPath = 0;
int cost = 0;

void getMinDist(int N, int gph[][N], int weights[][N], int vis[], int node, int dest)
{
	vis[node] = 1;
	
	if(node == dest)
	{
		dist[numPath++] = cost;
		return;
	}
		
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1 && !vis[j])
		{
			cost += weights[node][j];
			getMinDist(N, gph, weights, vis, j, dest);
			cost -= weights[node][j];
			vis[j] = 0;
		}
	}
}

int main()
{
	for(int i = 0; i < 10000; i++)
	{
		dist[i] = 0;
	}
	
	int N, M;
	scanf("%d%d", &N, &M);
	
	int vis[N];
	int gph[N][N];
	int weights[N][N];
	
	for(int i =0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
			weights[i][j] = 0;
		}
	}
	
	int x, y, c;
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		
		gph[x][y] = 1;
		gph[y][x] = 1;
		
		weights[x][y] = c;
		weights[y][x] = c;
	}
	
	int finalCost = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j++)
		{	
			if(i!=j)
			{
				getMinDist(N, gph, weights, vis, i, j);
				
				int min = dist[0];
				for(int k = 0; k < numPath; k++)
				{
					if(min > dist[k])
						min = dist[k];
				}
				finalCost += min;
				
				for(int k = 0; k < 10000; k++)
					dist[k] = 0;
					
				for(int k = 0; k < N; k++)
					vis[k] = 0;
					
				numPath = 0;
				cost = 0;
			}
		}
	}

	printf("%d\n", finalCost);
		
	return 0;
}
