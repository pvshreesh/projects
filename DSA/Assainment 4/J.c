#include <stdio.h>
#define lu unsigned long

lu getSqrt(lu x, lu l, lu r)
{
    //printf("l = %lu ;;; r = %lu\n", l, r);
    if(x == 0 || x == 1)
        return x;

    else if(l == r)
        return l-1;

    else if(l < r)
    {
        lu mid = l + (r-l)/2;
        if(mid == x/mid)
            return mid;

        else if(mid > x/mid)
            getSqrt(x, l, mid);
        else
            getSqrt(x, mid+1, r);
    }
}

            
    

int main()
{        
    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {
        lu x;
        scanf("%lu", &x);
        printf("%lu\n", getSqrt(x, 0, x-1));
    }

    return 0;
}