#include <stdio.h>
#include <math.h>
#include <string.h>

void b2gray(int val)
{
    int len = (int)log2(val)+1;

    int b1 = (val >> (len-1)) & 1;
    printf("%d", b1);

    int i = len-1;
    while(i > 0)
    {
        int b2 = (val >> (i-1)) & 1;
        printf("%d", b1^b2);
        b1 = b2;
        i--;
    }
    printf("\n");
}

int g2decimal(char str[])
{
    int b1 = (int)str[0] - 48;
    int dec = 0;
    dec += b1*(int)pow(2, strlen(str)-1);

    for(int i = 1; i < strlen(str); i++)
    {
        int b2 = (int)str[i] - 48;
        b1 = b1^b2;
        dec += b1*(int)pow(2, strlen(str)-i-1);
    }

    return dec;
}

int main()
{
    int q; char x;
    scanf("%d", &q);
    
    for(int i = 0; i < q; i++)
    {
        scanf("%c", &x);
        char c;
        scanf("%c", &c);

        if(c == 'G')
        {
            int val;
            scanf("%d", &val);
            b2gray(val);
        }
        else if(c == 'D')
        {
            char str[32];
            scanf("%s", str);
            printf("%d\n", g2decimal(str));
        }
    }       

    return 0;
}