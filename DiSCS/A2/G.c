#include <stdio.h>

int count = 0;

void checkCycle(int N, int gph[][N], int vis[], int curr_node)
{
	if(vis[curr_node] == 0) vis[curr_node] = 1;
	else if(vis[curr_node] == 1) vis[curr_node] = 2;
	for(int j = 0; j < N; j++)
	{ 
		if(gph[curr_node][j] == 1 && vis[j] != 2)
		{
			checkCycle(N, gph, vis, j);
		}
	}
	if(vis[curr_node] == 1) vis[curr_node] = 0;
}

int main()
{
	int N, nInputs;
	scanf("%d%d", &N, &nInputs);
	
	int vis[N];
	for(int i = 0; i < N; i++)
		vis[i] = 0;
	
	int gph[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			gph[i][j] = 0;
			
	int x, y;
	
	for(int i = 0; i < nInputs; i++)
	{
		scanf("%d%d", &x, &y);
		gph[y][x] = 1;
	}
	
	for(int i = 0; i < N; i++)
	{
		if(vis[i] == 0)
			checkCycle(N, gph, vis, i);
	}
	
	int cycleCount = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(vis[i] == 2)
			cycleCount++;
	}
	//printf("cycleCount = %d\n", cycleCount);
	
	if(cycleCount == 0)
	{
		printf("\nNo Deadlock\n");
		return 0;
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(gph[i][j] == 1 && vis[i] == 2)
				vis[j] = 2;
		}
	}
				
	
	/*for(int i = 0; i < N; i++)
		printf("%d ", vis[i]);	*/
		
		
	printf("\n\nDeadlock\n");
	for(int i = 0; i < N; i++)
	{	
		if(vis[i] == 2)
			printf("%d ", i);
	}
	
	printf("\n");
	
	return 0;
}