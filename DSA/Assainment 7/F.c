#include <stdio.h>

void bfsVariant(int N, int src, int vis[], int tree[][N])
{
    int Q[N];
    int front = 0, back = 1;
    Q[0] = src;
    vis[src] = 1;
    while(front != back)
    {
        int flag = 0;
        int v = Q[front++];
        for(int j = 0; j < N; j++)
        {
            if(tree[v][j] == 1 && !vis[j])
            {
                Q[back++] = j;
                vis[j] = 1;
                flag = 1;
                printf("%d ", j);
            }
        }
        if(flag == 1)
            printf("\n");
    }
}    

int main()
{
    int N;
    scanf("%d", &N);

    int tree[N][N];
    int vis[N];
    for(int i = 0; i < N; i++)
    {
        vis[i] = 0;
        for(int j = 0; j < N; j++)
        {
            tree[i][j] = 0;
        }
    }

    int val; char trash;
    for(int i = 0; i < N; i++)
    {
        while(1)
        {
            scanf("%d%c", &val, &trash);
            tree[i][val] = 1;
            if(trash == '\n')
                break;
        }
    }

    printf("\n0\n");
    bfsVariant(N, 0, vis, tree); 

    return 0;
}