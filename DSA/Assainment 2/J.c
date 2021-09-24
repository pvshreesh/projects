#include<stdio.h>
#include<limits.h>
#include<math.h>

unsigned long xorer = 0;

int isPrime = 1;
int yes = 0;

void xorPrimes(unsigned long n)
{
    while(n%2 == 0)
    {
        isPrime = 0;
        n = n/2;
        yes = 1;
    }
    if(yes) xorer ^= 2;

    for(long unsigned i = 3; i <= sqrt(n); i += 2)
    {
        yes = 0;
        while(n%i == 0)
        {
            isPrime = 0;
            n = n/i;
            yes = 1;
        }
        if(yes) xorer ^= i;
    }
    if(n > 2)
        xorer ^= n;
}

int main()
{   
    unsigned long val;
    scanf("%lu", &val);

    xorPrimes(val);
    if(isPrime) printf("%lu\n", val);
    else printf("%lu\n", xorer);

    return 0;
}