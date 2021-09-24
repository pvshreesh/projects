#include <stdio.h>

int flag = 0;
int count = 0;
int pathArr[100000];
void dfs(int N, int gph[][N], int vis[][N], int px, int py, int dx, int dy, int len)
{
	vis[px][py] = 1;
	if(px == dx && py == dy)
	{
		flag = 1;
		pathArr[count++] = len;
		return;
	}			
	
	if(!vis[px+1][py] && px+1<N && py<N)
	{
		px = px+1;
		len++;
		dfs(N, gph, vis, px, py, dx, dy, len);
		vis[px][py] = 0; 
	}
	if(!vis[px][py+1] && px<N && py+1<N)
	{
		py = py+1;
		len++;
		dfs(N, gph, vis, px, py, dx, dy, len);
		vis[px][py] = 0; 
	}
	if(!vis[px-1][py] && px-1>=0 && py<N)
	{
		px = px-1;
		len++;
		dfs(N, gph, vis, px, py, dx, dy, len);
		vis[px][py] = 0; 
	}
	if(!vis[px][py-1] && px<N && py-1>=0)
	{
		py = py-1;
		len++;
		dfs(N, gph, vis, px, py, dx, dy, len);
		vis[px][py] = 0; 
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int gph[N][N];
	int vis[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
			vis[i][j] = 0;
		}
	}
			
			
	int sx, sy, dx, dy;
	scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
	
	dfs(N, gph, vis, sx, sy, dx, dy, 0);
		
	if(flag == 0) printf("NO\n");
	else if(flag == 1)
	{
		for(int i = 0; i < count; i++)
		{
			//printf("N*N-1 = %d\n", pathArr[i]);
			if(pathArr[i] == N*N-1)
			{
				printf("YES\n");
				return 0;
			}
		}
		printf("NO\n");
	}	
	return 0;
}	
	
	
	
	
	
	
		
