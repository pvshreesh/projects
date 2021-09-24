#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int arr[N][M];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int q;
    scanf("%d", &q);

    int rInd = 0;
    int rFlag = 0;
    for(int i = 1; i < N; i++)
    {
        if(arr[i][0] > q)
        {
            rInd = i-1;
            rFlag = 1;
            break;
        }
    }
    if(rFlag == 0) rInd = N-1;

    for(int i = 0; i < M; i++)
    {
        if(arr[rInd][i] == q)
        {
            printf("YES\n");
            printf("%d %d\n", rInd, i);
            return 0;
        }  
    }

    printf("MISSING\n");

    return 0;
}