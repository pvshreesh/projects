#include<stdio.h>

int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void countDigits(int n)
{
    while(n != 0)
    {
        int d = n%10;
        count[d]++;
        n = n/10;
    }
}

int isPrime(int num)
{
    for(int i = 2; i <= num/i; i++)
    {
        if(num%i == 0) return 0;
    }

    return 1;
}

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);

    for(int i = l; i <= r; i++)
    {
        if(isPrime(i)) countDigits(i);
    }

    int max = 0;
    for(int i = 0; i < 10; i++)
    {
        if(count[i] > max)
            max = count[i];
    }

    for(int i = 0; i < 10; i++)
    {
        if(count[i] == max)
        {
            printf("%d %d\n", i, count[i]);
            return 0;
        }
    }

    return 0;
}