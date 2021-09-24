#include <stdio.h>

const int rem = 1000000007;
int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    unsigned long sum = 0;

    for(int i = 0; i < 32; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(((arr[j] >> i) & 1) == 1)
                count++;
        }
        sum += (unsigned long)((count)*(N-count));
    }       

    printf("%lu\n", (2*sum) % rem);


    return 0;
}