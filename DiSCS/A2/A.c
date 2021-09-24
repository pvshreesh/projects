#include <stdio.h>

void bfs(int N, int gph[][N], int vis[], int parent[], int src)
{
	int Q[N], front = 0, back = 0;
	Q[back++] = src;
	
	while(front!=back)
	{
		int curr_node = Q[front++];
		vis[curr_node] = 1;
		for(int j = 0; j < N; j++)
		{
			if(gph[curr_node][j] == 1 && !vis[j])
			{
				Q[back++] = j;
				vis[j] = 1;
				parent[j] = curr_node;
			}
		}
	}
}

int main()
{
	int N, nInputs;
	scanf("%d%d", &N, &nInputs);
	
	int parent[N];
	int vis[N];
	for(int i = 0; i < N; i++)
	{
		parent[i] = -1;
		vis[i] = 0;
	}
	
	int gph[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			gph[i][j] = 0;
			
	int x, y;
	for(int i = 0; i < nInputs; i++)
	{
		scanf("%d%d", &x, &y);
		gph[x-1][y-1] = 1;
		gph[y-1][x-1] = 1;
	}
	
	int src, dest;
	scanf("%d%d", &src, &dest);
	
	bfs(N, gph, vis, parent, src-1);
	
	int ans[N];
	int count = 0;
	int crawl = dest-1;
	//printf("%d\n", crawl);
	int l = 0;
	while(crawl != src-1)
	{
		ans[count++] = crawl;
		crawl = parent[crawl];
		l++;
	}
	ans[count] = crawl;
	
	if(vis[dest-1] == 0)
	{
		printf("\n-1\n");
		return 0;
	}
	
	printf("\n%d\n", count);	
	for(int i = count; i >= 0; i--)
		printf("%d ", ans[i]+1);
	
	printf("\n");
	
	return 0;
}