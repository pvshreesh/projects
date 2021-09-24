#include <stdio.h>

int vertexCount = 0;
int cost = 0;

void getMinWeight(int N, int gph[][N], int weights[][N], int vertexSet[], int vis[], int edgeSet[][N], int ansArr[][2])
{
	int min = 10000000; int startV, endV;
	for(int i = 0; i < vertexCount; i++)
	{
		int s = vertexSet[i];
		for(int j = 0; j < N; j++)
		{
			if(gph[s][j] == 1 && !vis[j])
			{
				if(min > weights[s][j])
				{
					min = weights[s][j];
					startV = s;
					endV = j;
				}
			}
		}
	}
	vis[endV] = 1;
	ansArr[vertexCount-1][0] = startV;
	ansArr[vertexCount-1][1] = endV;
	edgeSet[startV][endV] = 1;
	cost += min;
	vertexSet[vertexCount++] = endV; 
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	int gph[N][N];
	int vis[N];
	int weights[N][N];
	int ansArr[N-1][2];
	
	int vertexSet[N];
	int edgeSet[N][N];
	vertexSet[0] = 0;
	vertexCount = 1;
	
	for(int i = 0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
			weights[i][j] = 0;
			edgeSet[i][j] = 0;
		}
	}
	
	vis[0] = 1;
	int x, y, w;
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		
		gph[x][y] = 1;
		gph[y][x] = 1;
		
		weights[x][y] = w;
		weights[y][x] = w;
	}
	
	for(int i = 0; i < N-1; i++)
	{
		getMinWeight(N, gph, weights, vertexSet, vis, edgeSet, ansArr); 
	}
	
	printf("%d\n", cost);
	for(int i = 0; i < N-1; i++)
	{
		printf("%d %d\n", ansArr[i][0], ansArr[i][1]);
	}
	
	return 0;
}
