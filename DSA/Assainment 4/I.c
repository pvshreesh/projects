#include <stdio.h>

void merge(int S[], int arr[], int l, int m, int r)
{
    int ll = m-l+1;
    int rl = r-m;

    int L[ll];
    int R[rl];

    int SL[ll];
    int SR[rl];

    for(int i = 0; i < ll; i++)
    {
        L[i] = arr[l+i];
        SL[i] = S[l+i];
    }
    for(int i = 0; i < rl; i++)
    {
        R[i] = arr[m+i+1];
        SR[i] = S[m+i+1];
    }

    int i = 0, j = 0;
    while(i < ll && j < rl)
    {
        if(L[i] <= R[j])
        {
            arr[l+i+j] = L[i];
            S[l+i+j] = SL[i];
            i++;
        }
        else
        {
            arr[l+i+j] = R[j];
            S[l+i+j] = SR[j];
            j++;
        }
    }

    if(i < ll)
    {
        while(i < ll)
        {
            arr[l+i+j] = L[i];
            S[l+i+j] = SL[i];
            i++;
        }
    }
    else
    {
        while(j < rl)
        {
            arr[l+i+j] = R[j];
            S[l+i+j] = SR[j];
            j++;
        }
    }
}

void mergeSort(int S[], int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(S, arr, l, m);
        mergeSort(S, arr, m+1, r);
        merge(S, arr, l, m, r);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int S[N], F[N];
    for(int i = 0; i < N; i++)
        scanf("%d%d", &S[i], &F[i]);

    mergeSort(S, F, 0, N-1);

    int count = 1;
    int tEnd = F[0];
    
    for(int i = 0; i < N; i++)
    {
        if(S[i] > tEnd)
        {
            count++;
            tEnd = F[i];
        }
    }

    printf("%d\n", count);

    return 0;
}