#include <stdio.h>

void dfs(int N, int gph[][N], int vis[], int curr_node)
{
	vis[curr_node] = 1;
	for(int j = 0; j < N; j++)
	{
		if(gph[curr_node][j] == 1 && !vis[j])
		{
			dfs(N, gph, vis, j);
		}
	}
}

int main()
{
	int N, nInput, nVirus;
	scanf("%d%d%d", &N, &nInput, &nVirus);
	
	int gph[N][N];
	int x, y;
	int vis[N];
	int count = 0;
	
	for(int i = 0; i < N; i++)
		vis[i] = 0;
		
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			gph[i][j] = 0;
	
	for(int i = 0; i < nInput; i++)
	{
		scanf("%d%d", &x, &y);
		gph[x-1][y-1] = 1;
	}
	
	int root;
	for(int i = 0; i < nVirus; i++)
	{
		scanf("%d", &root);
		dfs(N, gph, vis, root-1);
	}
	
	for(int i = 0; i < N; i++)
	{
		if(vis[i] == 0)
			count++;
	}
	
	printf("\n");
	if(count == 0)
		printf("Black Out\n");
		
	else
	{
		printf("%d\n", count);
		
		for(int i = 0; i < N; i++)
		{
			if(vis[i] == 0)
				printf("%d ", i+1);
		}
		
		printf("\n");
	}		
	
	return 0;
}
