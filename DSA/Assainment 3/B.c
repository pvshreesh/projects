#include <stdio.h>

int count = 0;

int collatz(int elem)
{
    if(elem == 1)
    {
        count++;
        return count;
    }

    else if(elem%2 == 0)
    {
        count++;
        collatz(elem/2);
    }

    else if(elem%2 == 1)
    {
        count++;
        collatz(3*elem + 1);
    }
}

int main()
{   
    int N;
    scanf("%d", &N);

    int maxSeed = -1;
    int max = -1;
    for(int i = N; i >= 1; i--)
    {
        count = 0;
        int val = collatz(i);
        if(val > max)
        {
            max = val;
            maxSeed = i;
        }
    }

    printf("%d %d\n", maxSeed, max);


    return 0;
}