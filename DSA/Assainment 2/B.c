#include<stdio.h>

int a, b, c, d, e, f;

int minJump(int x, int count) //backtracking from answer to see if we get 0;
{
    if(x == 0)
        return count;

    else if((x-b)%a == 0 && x>0)
    {
        x = (x-b)/a;
        minJump(x, ++count);
    }
    else if((x-d)%c == 0 && x>0)
    {
        x = (x-d)/c;
        minJump(x, ++count);
    }
    else if((x-f)%e == 0 && x>0)
    {
        x = (x-f)/e;
        minJump(x, ++count);
    }
    else
        return -1;


}

int main()
{
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    int q;
    scanf("%d", &q);

    int in;
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &in);
        printf("%d\n", minJump(in, 0));
    }

    return 0;
}