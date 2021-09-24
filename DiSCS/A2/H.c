#include <stdio.h>

int count = 0;
int nodeArr[1000];
int flag = 0;

void dfs(int N, int gph[][N], int vis[], int curr_node, int dest, int p, int q)
{		
	vis[curr_node] = 1;
	if(curr_node == p)
		vis[q] = 1;
		
	for(int j = 0; j < N; j++)
	{
		if(gph[curr_node][j] == 1 && !vis[j])
		{
			if(j == dest)
			{			
				flag = 1;
				printf("YES\n1 ");
			}
			else
				dfs(N, gph, vis, j, dest, p, q);
			
			if(flag == 1)
			{
				nodeArr[count] = j;
				count++;
			}
		}
	}
	if(curr_node == p)
		vis[q] = 0;
}

int main()
{
	int N, nInputs, dest;
	scanf("%d%d%d", &N, &nInputs, &dest);
	
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
		gph[x-1][y-1] = 1;
	}
	
	int p, q;
	scanf("%d%d", &p, &q);
	
	dfs(N, gph, vis, 0, dest-1, p-1, q-1);
	
	if(flag == 0) printf("\nNO");
	
	else if(flag == 1)
		for(int i = count-1; i >= 0; i--)
			printf("%d ", nodeArr[i]+1);
						
	printf("\n");
	return 0;
}
