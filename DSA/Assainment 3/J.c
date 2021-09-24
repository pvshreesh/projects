#include <stdio.h>
#include <stdlib.h>

int fx, fy;
int M, N;

void move(int x, int y, int gph[M][N], int vis[M][N])
{
    //printf("IN move - %d, %d\n", x, y);
    if(x == fx && y == fy)
    {
        printf("YES\n");
        exit(0);
    }

    if(x < M && y < N)
    {
        if(gph[x+1][y] == 1 && !vis[x+1][y])
        {
            vis[x+1][y] = 1;
            move(x+1, y, gph, vis);
        }

        if(gph[x][y+1] == 1 && !vis[x][y+1])
        {
            vis[x][y+1] = 1;
            move(x, y+1, gph, vis);
        }

        if(gph[x-1][y] == 1 && !vis[x-1][y])
        {
            vis[x-1][y] = 1;
            move(x-1, y, gph, vis);
        }
        
        if(gph[x][y-1] == 1 && !vis[x][y-1])
        {
            vis[x][y-1] = 1;
            move(x, y-1, gph, vis);
        }
    }
}

int main()
{
    scanf("%d%d", &M, &N);

    int gph[M][N];
    int vis[M][N];
    for(int i = 0 ; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &gph[i][j]);
            vis[i][j] = 0;
        }
    }

    int x, y;
    scanf("%d%d", &x, &y);
    scanf("%d%d", &fx, &fy);

    move(x, y, gph, vis);

    printf("NO\n");

    return 0;
}