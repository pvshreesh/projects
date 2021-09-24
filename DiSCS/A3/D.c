#include <stdio.h>

int found = 0;

void printOccurrences(int N, int gph[][N], int weight[][N], int vis[], int root, int query, int sum)
{
	vis[root] = 1;
	if(sum == query)
		printf("%d ", root);
				
	for(int j = 0; j < N; j++)
	{
		if(gph[root][j] == 1 && !vis[j])
		{
			sum += weight[root][j];
			printOccurrences(N, gph, weight,vis, j, query, sum);
			sum -= weight[root][j];
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int gph[N][N];
	int weight[N][N];
	int vis[N];
	
	for(int i =0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
			weight[i][j] = 0;
		}
	}
	
	int x, y;
	char c, trash;
	
	for(int i = 0; i < N-1; i++)
	{
		scanf("%d%d%c%c", &x, &y, &trash, &c);
		gph[x][y] = 1;
		
		if(c == 'L')
			weight[x][y] = -1;
		
			
		else if(c == 'R')
			weight[x][y] = 1;
	}
	
	int query;
	scanf("%d", &query);	
		
	printOccurrences(N, gph, weight, vis, 0, query, 0);
	
	return 0;
}
