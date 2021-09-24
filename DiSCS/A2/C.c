#include <stdio.h>
// A = 65, Z = 90
int ans[26][26];
int count = 0;
int len[26];
void dfs(int N, int gph[][N], int vis[], int curr_node)
{
	vis[curr_node] = 1;
	ans[count][len[count]++] = curr_node;//printf("%c", (char)(curr_node+65));
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
	for(int i = 0; i < 26; i++)
		len[i] = 0;
	
	int N, nInput;
	scanf("%d%d", &N, &nInput);
		
	int vis[N];
	for(int i = 0; i < N; i++)
		vis[i] = 0;
		
	int gph[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			gph[i][j] = 0;
	
	char trash;
	char x, y;
	
	for(int i = 0; i < nInput; i++)
	{
		scanf("%c%c%c%c", &trash, &x, &trash, &y);
		gph[(int)(x)-65][(int)(y)-65] = 1;
		gph[(int)(y)-65][(int)(x)-65] = 1;	
	}
	
	printf("\n");
	
	for(int i = 0; i < N; i++)
	{
		if(vis[i] == 0)
		{
			dfs(N, gph, vis, i);
			count++;
		}
	}
	
	printf("%d\n", count);
	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < len[i]; j++)
		{
			printf("%c", (char)(ans[i][j]+65));
		}
		printf("\n");
	}
	
	return 0;
}
