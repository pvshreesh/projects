#include <stdio.h>

int ans = -404;

void directGraph(int N, int gph[][N], int vis[], int root)
{
	vis[root] = 1;
	for(int j = 0; j < N; j++)
	{
		if(gph[root][j] == 1 && vis[j] == 0)
		{
			gph[root][j] = 0;
			directGraph(N, gph, vis, j);
		}
	}
}

void closestAncestor(int N, int gph[][N], int vis[], int node)
{
	vis[node] = 1;
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1)
		{
			if(vis[j] == 1)
			{
				ans = j;
				return;
			}
			closestAncestor(N, gph, vis, j);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int gph[N][N];
	int vis[N];
	
	for(int i = 0; i < N; i++)
	{
		vis[N] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[N][N] = 0;
		}
	}
		
	int x, y;
	for(int i =0; i < N-1; i++)
	{	
		scanf("%d%d", &x, &y);
		gph[x][y] = 1;
		gph[y][x] = 1;
	}
	
	int nInputs;
	scanf("%d", &nInputs);
	
	for(int i = 0; i < nInputs; i++)
	{
		int node1, node2;
		scanf("%d%d", &node1, &node2);
		
		directGraph(N, gph, vis, 0);
		
		for(int i = 0; i < N; i++)
			vis[i] = 0;
				
		closestAncestor(N, gph, vis, node1);
		closestAncestor(N, gph, vis, node2);
			
		printf("%d\n", ans);
	}
	return 0;
}
