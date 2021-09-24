#include <stdio.h>

int totCost[100000];
int path[100000][10];
int count = 0;
int pc = 0;

void dfs(int N, int gph[][N], int vis[], int cost[][N], int curr_node, int dest)
{
	vis[curr_node] = 1;
	for(int j = 0; j < N; j++)
	{
		if(gph[curr_node][j] == 1 && !vis[j])
		{
			printf("curr-%d,  j-%d\n", curr_node+1, j+1);
			if(j == dest)
			{
				//totCost[count] += cost[curr_node][j];
				//path[count][pc++] = j;
				//path[count][pc++] = -7;
				//count++;
				//pc = 0;
				vis[j] = 0;
				return;
			}
			else
			{
				//totCost[count] += cost[curr_node][j];
				//path[count][pc++] = j;
				dfs(N, gph, vis, cost, j, dest);
				vis[j] = 0;
			}
		}
	}
}

int main() 
{ 
	for(int i = 0; i < 100000; i++)
		totCost[i] = 0;
	
	int N, nInputs, src, dest;
	scanf("%d%d%d%d", &N, &nInputs, &src, &dest);
	
	int gph[N][N];
	int cost[N][N];
	for(int i =0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
			cost[i][j] = 0;
		}
	}
	
	int vis[N];
	for(int i =0; i < N; i++)
		vis[i] = 0;
	
	int x, y, c;	
	for(int i =0; i < nInputs; i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		gph[x-1][y-1] = 1;
		gph[y-1][x-1] = 1;
		cost[x-1][y-1] = c;
		cost[y-1][x-1] = c;
	}
	
	dfs(N, gph, vis, cost, src-1, dest-1);
	
	//printf("count - %d\n", count);
	int min = totCost[0];
	int k;
	for(int i = 0; i < count; i++)
	{
		//printf("%d ", totCost[i]);
		if(min > totCost[i])
		{
			min = totCost[i];
			k = i;
		}
	}
	
	//printf("\n%d\n", min);
	printf("\n\n");
	for(int i = 0; i < count; i++)
	{
		int l = 0;
		printf("%d ", src);
		while(path[i][l] != (-7))
		{
			printf("%d ", path[i][l]+1);
			l++;
		}
		printf("\n");
	}
	
	
	/*for(int i =0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%d ", gph[i][j]);
		}
		printf("\n");
	}
*/
	return 0;
}
