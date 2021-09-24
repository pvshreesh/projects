#include <stdio.h>

int colIsAllZero(int ind, int N, int gph[][N])
{
    for(int i = 0; i < N; i++)
    {
        if(gph[i][ind] == 1)
            return 0;
    }
    return 1;
}

void makeRowZero(int ind, int N, int gph[][N])
{
    for(int i = 0; i < N; i++)
        gph[ind][i] = 0;
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
        gph[y-1][x-1] = 1;
    }

    for(int i = 0; i < N; i++)
    {
        if(colIsAllZero(i, N, gph) == 1 && !vis[i])
        {
            vis[i] = 1;
            printf("%d ", i+1);
            makeRowZero(i, N, gph);
            i = 0;
        }
    }

    return 0;
}