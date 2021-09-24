#include <stdio.h>

void bfs(int src, int N, int gph[][N], int vis[])
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
        {
            gph[i][j] = 0;
        }
    }

    int x, y;
    for(int i = 0; i < M; i++)
    {
        scanf("%d%d", &x, &y);
        gph[x-1][y-1] = 1;
        gph[y-1][x-1] = 1;
    }

    int count = 0, max = 0, maxV[N];
    for(int i = 0; i < N; i++)
    {
        bfs(i, N, gph, vis);

        count = 0;
        for(int i = 0; i < N; i++)
        {
            if(vis[i])
                count++;
        }

        if(count > max)
        {
            max = count;
            for(int i = 0; i < N; i++)
                maxV[i] = vis[i];
        }

        for(int i = 0; i < N; i++)
            vis[i] = 0;
    }

    if(max == N)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", N-max);
    for(int i = 0; i < N; i++)
    {
        if(!maxV[i])
            printf("%d ", i+1);
    }

    printf("\n");

    return 0;
}