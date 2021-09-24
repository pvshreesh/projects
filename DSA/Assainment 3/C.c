#include <stdio.h>

const int rem = 998244353;

unsigned long getFact(int l, int r)
{
    if(l == 0)
        return 1;

    else if(l == r)
        return l;

    else if(l == r+1)
        return (l*r);

    else
    {
        int m = (l+r)/2;
        return ((getFact(l, m) % rem) * (getFact(m-1, r) % rem)) % rem;
    }
}

unsigned long getProd3(unsigned long a, unsigned long b, unsigned long c)
{
    return (((a*b) % rem) * (c % rem)) % rem;
}

unsigned long getInverse(unsigned long val)
{
    for(unsigned long i = 1; i < rem; i++)
    {
        if(((val*i) % rem) == 1)
            return i;
    }

    return -1;
}

int main()
{
    int x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d", &x1, &y1, &z1);
    scanf("%d%d%d", &x2, &y2, &z2);

    int x = (x2-x1)>0 ? (x2-x1) : (x1-x2);
    int y = (y2-y1)>0 ? (y2-y1) : (y1-y2);
    int z = (z2-z1)>0 ? (z2-z1) : (z1-z2);

    //must compute (x+y+z)! / (x! * y! * z!)
    //(a*b) mod r = ((a mod r)*(b mod r)) mod r

    // val mod m = (a! mod m  * b! mod m * c! mod m) mod m
    //printf("%d %d %d\n", x, y, z);

    unsigned long val = getProd3(getFact(x, 1), getFact(y, 1), getFact(z, 1));
    //printf("%lu\n", val);

    unsigned long inv = getInverse(val); 

    unsigned long ans = (getFact((x+y+z), 1) * inv) % rem;
    printf("%lu\n", ans);  

    return 0;
}