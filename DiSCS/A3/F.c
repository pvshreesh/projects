#include <stdio.h>

int pathArr[1000][10];
int pathLen[1000];
int numPath = 0;
int max = 0;
int count = 0;

void dfs(int N, int gph[][N], int vis[], int node, int dest)
{
	pathArr[numPath][count++] = node;
	vis[node] = 1;
	
	if(node == dest)
	{
		pathLen[numPath++] = count;
		return;
	}
		
	for(int j = 0; j < N; j++)
	{
		if(gph[node][j] == 1 && !vis[j])
		{
			dfs(N, gph, vis, j, dest);
			vis[j] = 0;
			count--;
		}
	}
}
	

int main()
{
	for(int i = 0; i < 1000; i++)
	{
		pathLen[i] = 0;
	}
	
	int N, M;
	scanf("%d%d", &N, &M);
	
	int vis[N];
	int gph[N][N];
	
	for(int i = 0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
		}
	}
	
	int x, y;
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		
		gph[x][y] = 1;
		gph[y][x] = 1;
	}
	
	int src, dest;
	scanf("%d%d", &src, &dest);
	
	dfs(N, gph, vis, src, dest);
	
	for(int i =0; i < numPath; i++)
	{
		if(max < pathLen[i])
			max = pathLen[i];
	}
	
	for(int i =0 ; i < numPath; i++)
	{
		if(pathLen[i] == max)
		{
			for(int j = 0; j < pathLen[i]; j++)
			{
				printf("%d ", pathArr[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
	
