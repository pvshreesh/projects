#include <stdio.h>

void bfs(int src, int N, int vis[], int gph[][N])
{
    int Q[N];
    Q[0] = src; vis[src] = 1;
    int front = 0, back = 1;
    while(front != back)
    {
        int v = Q[front++];
        for(int i = 0; i < N; i++)
        {
            if(gph[v][i] == 1 && !vis[i])
            {
                vis[i] = 1;
                Q[back++] = i;
            }
        }
    }
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int vis[N];
    int gph[N][N];
    for(int i = 0; i < N; i++)
    {
        vis[i] = 0;
        for(int j = 0; j < N; j++)
            gph[i][j] = 0;
    }

    int x, y;
    for(int i = 0; i < M; i++)
    {
        scanf("%d%d", &x, &y);
        gph[x][y] = 1;
        gph[y][x] = 1;
    }

    int src;
    scanf("%d", &src);

    int minV = N+1;
    int minC = N+1;
    int count = 0;

    for(int i = 0; i < N; i++)
    {
        vis[i] = 1;
        bfs(src, N, vis, gph);

        count = 0;
        for(int j = 0; j < N; j++)
            if(vis[j]) count++;

        if(count < minC)
        {
            minC = count;
            minV = i;
        }

        for(int j = 0; j < N; j++)
            vis[j] = 0;
    }

    printf("%d\n", minV);

    return 0;
}