#include <stdio.h>

int isLeafNode(int node, int N, int gph[][N])
{
    int count = 0;
    for(int i= 0; i < N; i++)
    {
        if(gph[node][i] == 1 && count == 0)
            count = 1;
        else if(gph[node][i] == 1 && count == 1)
            return 0;
    }

    return 1;
}

void bfs(int N, int gph[][N], int vis[], int parent[])
{
    int Q[N];
    Q[0] = 0; vis[0] = 1;
    int front = 0, back = 1;
    while(front != back)
    {
        int v = Q[front++];
        for(int i = 0; i < N; i++)
        {
            if(gph[v][i] == 1 && !vis[i])
            {
                Q[back++] = i;
                vis[i] = 1;
                parent[i] = v;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int vis[N];
    int gph[N][N];
    int isLeaf[N];
    int parent[N];
    int lengths[N];

    for(int i = 0; i < N; i++)
    {
        vis[i] = 0;
        parent[i] = -1;
        lengths[i] = -1;
        for(int j = 0; j < N; j++)
            gph[i][j] = 0;
    }

    int x, y;
    for(int i = 0; i < N-1; i++)
    {
        scanf("%d%d", &x, &y);
        gph[x][y] = 1;
        gph[y][x] = 1;
    }

    for(int i = 0; i < N; i++)
        isLeaf[i] = isLeafNode(i, N, gph);

    bfs(N, gph, vis, parent);

    int dist = 0;
    for(int i = 0; i < N; i++)
    {
        if(isLeaf[i])
        {
            dist = 0;
            int v = i;
            while(v != 0)
            {
                v = parent[v];
                dist++;
            }
            lengths[i] = dist;
        }
    }

    int min = N+1;
    int minI = N+1;
    for(int i = N-1; i >= 0; i--)
    {
        if(lengths[i] != -1 && min >= lengths[i])
        {
            min = lengths[i];
            minI = i;
        }
    }

    int num = 0;
    for(int i = 0; i < N; i++)
    {
        if(min == lengths[i])
            num++;
    }

    printf("%d\n%d\n", num, minI); 

    return 0;
}