#include <stdio.h>

int leaf(int node, int N, int gph[][N])
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        if(gph[node][i] == 1)
            count++;

        if(count > 1)
            return 0;
    }
    return 1;
}      

void bfs(int N, int parent[], int vis[], int gph[][N])
{
    int Q[N]; Q[0] = 0;
    vis[0] = 1;
    int front = 0;
    int back = 1;

    while(front != back)
    {   
        int v = Q[front++];
        for(int i = 0; i < N; i++)
        {
            if(gph[v][i] == 1 && !vis[i])
            {
                parent[i] = v;
                Q[back++] = i;
                vis[i] = 1;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int gph[N][N];
    int vis[N];
    int isLeaf[N];
    int parent[N];
    int lengths[N][N];

    for(int i = 0; i < N; i++)
    {
        vis[i] = 0;
        parent[i] = 0;
        for(int j = 0; j < N; j++)
        {
            gph[i][j] = 0;
            lengths[i][j] = 0;
        }
    }

    int x, y;
    for(int i = 0; i < N-1; i++)
    {
        scanf("%d%d", &x, &y);
        gph[x][y] = 1;
        gph[y][x] = 1;
    }

    for(int i = 0; i < N; i++)
        isLeaf[i] = leaf(i, N, gph);

    bfs(N, parent, vis, gph);

    for(int i = 0; i < N; i++)
    {
        for(int j = N-1; j > i; j--)
        {
            if(i != j && isLeaf[i] && isLeaf[j])
            {
                for(int k = 0; k < N; k++)
                    vis[k] = 0;
                
                int li = 0, lj = 0, lc = 0;
                int v = i;
                while(v != 0)
                {
                    vis[v] = 1;
                    v = parent[v];
                    li++;
                }

                v = j;
                while(v != 0 && !vis[v])
                {
                    v = parent[v];
                    lj++;
                }

                while(v != 0)
                {
                    v = parent[v];
                    lc++;
                }
                lengths[i][j] = li + lj - lc;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(lengths[i][j] > max)
                max = lengths[i][j];
        }
    }

    int maxL;
    int maxR;
    int maxDiff = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = N-1; j > i; j--)
        {
            if(lengths[i][j] == max && (j - i) > maxDiff)
            {
                maxL = i;
                maxR = j;
                maxDiff = (j-i);
            }
        }
    }

    printf("%d\n%d %d\n", max, maxL, maxR);

    return 0;
}