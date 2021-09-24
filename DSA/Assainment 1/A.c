#include<stdio.h>
#define twoD(ptr, rows, i, j) (*(ptr + (i)*rows + (j)))

int isSubMatrixAtIndex(int Pr, int* P, int Qr, int Qc, int* Q, int x, int y)
{
    for(int i = 0; i < Qr; i++)
    {
        for(int j = 0; j < Qc; j++)
        {
            if(twoD(P, Pr, x+i, y+j) != twoD(Q, Qr, i, j))
                return 0;
        }
    }

    return 1;
}

int main()
{
    int Pr, Pc;
    scanf("%d%d", &Pr, &Pc);

    int P[Pr][Pc];

    for(int i = 0; i < Pr; i++)
    {
        for(int j = 0; j < Pc; j++)
        {
            scanf("%d", &P[i][j]);
        }
    }

    int Qr, Qc;
    scanf("%d%d", &Qr, &Qc);

    int Q[Qr][Qc];

    for(int i = 0; i < Qr; i++)
    {
        for(int j = 0; j < Qc; j++)
        {
            scanf("%d", &Q[i][j]);
        }
    }

    for(int i = 0; i < Pr; i++)
    {
        for(int j = 0; j < Qr; j++)
        {
            if(isSubMatrixAtIndex(Pr, (int*)P, Qr, Qc, (int*)Q, i, j) == 1)
            {
                printf("YES\n");
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }  

    printf("NO\n");  

    return 0;
}