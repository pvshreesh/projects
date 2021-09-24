#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int stops[M];
    for(int i = 0; i < M; i++)
        scanf("%d", &stops[i]);

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {
        int v;
        scanf("%d", &v);

        int min = abs(v-stops[0]);
        for(int i = 1; i < M; i++)
        {
            if(min > abs(v - stops[i]))
                min = abs(v-stops[i]);
        }
        printf("%d\n", min);
    }

    return 0;
}