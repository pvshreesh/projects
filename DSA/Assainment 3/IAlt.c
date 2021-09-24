#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int ll = m-l+1;
    int rl = r-m;
    int L[ll], R[rl];

    for(int i = 0; i < ll; i++)
        L[i] = arr[l+i];
    for(int i = 0; i < rl; i++)
        R[i] = arr[m+1+i];

    int i = 0, j = 0;
    while(i < ll && j < rl)
    {
        if(L[i] < R[j])
        {
            arr[l+i+j] = L[i];
            i++;
        }
        else
        {
            arr[l+i+j] = R[j];
            j++;
        }
    }

    if(i < ll)
    {
        while(i < ll)
        {
            arr[l+i+j] = L[i];
            i++;
        }
    }
    else if(j < rl)
    {
        while(j < rl)
        {
            arr[l+i+j] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int digits[N];
    int numZero = 0;   
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &digits[i]);
        if(digits[i] == 0)
            numZero++;
    }

    //largest num %30 and subset of digits

    if(numZero == 0)
    {
        printf("NO NUMBER\n");
        return 0;
    }

    int noZero[2][N - numZero];
    int l = 0;
    for(int i = 0; i < N; i++)
    {
        if(digits[i] != 0)
            noZero[0][l++] = digits[i];
    }

    mergeSort(noZero[0], 0, N-numZero-1);

    for(int i = 0; i < N; i++)
        noZero[1][i] = noZero[0][i] % 3;

    int zN = N-numZero;

    int sum = 0;
    for(int i = 0; i < zN; i++)
        sum += noZero[1][i];

    if(sum % 3 == 0)
    {
        for(int i = zN-1; i>= 0; i--)
            printf("%d", noZero[0][i]);

        for(int i = numZero; i > 0; i--)
            printf("0");

        printf("\n");
    }
    else
    {
        if(sum % 3 == 1)
        {
            int flag1 = 0;
            for(int i = 0; i < zN; i++)
            {
                if(noZero[1][i] == 1)
                {
                    noZero[0][i] = -1;
                    flag1 = 1;
                    break;
                }
            }

            if(flag1 == 0)
            {
                int flag2 = 0;
                for(int i = 0; i < zN; i++)
                {
                    if(noZero[1][i] == 2)
                    {
                        noZero[0][i] = -1;
                        flag2++;
                        if(flag2 == 2)
                            break;
                    }
                }
            }
        }
        else
        {
            int flag2 = 0;
            for(int i = 0; i < zN; i++)
            {
                if(noZero[1][i] == 2)
                {
                    noZero[0][i] = -1;
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)
            {   
                int flag1 = 0;
                for(int i = 0; i < zN; i++)
                {
                    if(noZero[1][i] == 1)
                    {
                        noZero[0][i] = -1;
                        flag1++;
                        if(flag1 == 2)
                            break;
                    }
                }
            }
        }
    }

    int hasElem = 0;
    for(int i = zN-1; i >= 0; i--)
    {
        if(noZero[0][i] != -1)
        {
            hasElem = 1;
            printf("%d", noZero[0][i]);
        }
    }

    if(hasElem == 0)
    {
        printf("0\n");
        return 0;
    }
    
    for(int i = numZero; i > 0; i--)
        printf("0");

    printf("\n");
    return 0;
}