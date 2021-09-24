#include <stdio.h>

int pathArr[1000][1000];
int pathLenArr[1000];
//void bfs(int N, int gph[][N], int vis[], int parent[], int src){}
int inParentArr(int N, int parent[], int item)
{
	for(int i = 1; i < N; i++)
	{
		if(item == parent[i])
			return 1;
	}
	return 0;
}

int main()
{
	for(int i =0; i < 1000; i++)
	{
		pathLenArr[i] = 0;
	}
	
	int N;
	scanf("%d", &N);
	
	int vis[N];
	//int bparent[N];
	int gph[N][N];
	
	for(int i =0; i < N; i++)
	{
		vis[i] = 0;
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
		}
	}
	
	int parent[N];
	for(int i = 1; i < N; i++)
	{
		scanf("%d", &parent[i]);
		gph[parent[i]][i] = 1;
	}
	
	int temp;
	int numPath = 0;
	for(int i = 0; i < N; i++)
	{
		if(!inParentArr(N, parent, i))
		{
			temp = i;
			do
			{
				pathArr[numPath][pathLenArr[numPath]++] = temp;
				temp = parent[temp];
			}
			while(temp!=0);
			numPath++;
		}
	}
	
	int min = pathLenArr[0];
	for(int i = 0; i < numPath; i++)
	{
		if(min > pathLenArr[i])
			min = pathLenArr[i];
	}
	
	for(int i = 0; i < numPath; i++)
	{
		if(pathLenArr[i] == min)
		{
			printf("%d ", pathArr[i][0]);
		}
	}
	printf("\n");
	return 0;
}
