#include <stdio.h>
#include <math.h>

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);

    int arr[N];
    for(int i = 0; i < N; i++)
        arr[i] = (K >> i) & 1;

    int next[N];
    for(int i = 0; i < (int)pow(2, N); i++)
    {
        for(int j = 0; j < N; j++)
            next[j] = (i >> j) & 1;

        int flag = 1;
        for(int j = 0; j < N; j++)
        {
            if(arr[j] == 1)
            {
                if(next[j] != 1)
                    flag = 0;
            }
        }

        if(flag == 1)
        {
            for(int j = N-1; j >= 0; j--)
                printf("%d", next[j]);

            printf("\n");
        }             
    }

    return 0;
}