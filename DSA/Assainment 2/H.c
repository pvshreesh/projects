#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int parent[N];
    parent[0] = 0;
    for(int i = 1; i < N; i++)
        scanf("%d", &parent[i]);

    int K;
    scanf("%d", &K);

    int nodes[N];
    int num = 0;
    int level = 0;
    int v;
    for(int i = 1; i < N; i++)
    {
        level = 0;
        v = i;
        while(v != 0)
        {
            v = parent[v];
            level++;
        }
        if(level == K)
            nodes[num++] = i;
    }

    if(num == 0)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", num);
    for(int i =0; i < num; i++)
        printf("%d ", nodes[i]);

    printf("\n");

    return 0;
}
        
