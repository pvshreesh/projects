#include <stdio.h>

void merge(int shift[], int arr[], int l, int m, int r)
{
    int ll = m-l+1;
    int rl = r-m;

    int L[ll];
    int R[rl];

    int Ls[ll];
    int Rs[rl];

    for(int i = 0; i < ll; i++)
    {
        L[i] = arr[l+i];
        Ls[i] = shift[l+i];
    }
    for(int i = 0; i < rl; i++)
    {
        R[i] = arr[m+i+1];
        Rs[i] = shift[m+i+1];
    }

    int i = 0, j = 0;
    while(i < ll && j < rl)
    {
        if(L[i] <= R[j])
        {
            arr[l+i+j] = L[i];
            shift[l+i+j] = Ls[i];
            i++;
        }
        else
        {
            arr[l+i+j] = R[j];
            shift[l+i+j] = Rs[j];
            j++;
        }
    }

    if(i < ll)
    {
        while(i < ll)
        {
            arr[l+i+j] = L[i];
            shift[l+i+j] = Ls[i];
            i++;
        }
    }
    else
    {
        while(j < rl)
        {
            arr[l+i+j] = R[j];
            shift[l+i+j] = Rs[j];
            j++;
        }
    }
}

void mergeSort(int shift[], int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(shift, arr, l, m);
        mergeSort(shift, arr, m+1, r);
        merge(shift, arr, l, m, r);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int E;
    scanf("%d", &E);

    int shift[N];
    for(int i = 0; i < N; i++)
        shift[i] = i;
    
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];

    if(sum < E)
    {
        printf("NO CHANCE\n");
        return 0;
    }

    sum = 0;
    mergeSort(shift, arr, 0, N-1);

    for(int i = 0; i < N; i++)
    {
        if(sum < E)
        {
            sum += arr[i];
            printf("%d ", shift[i]+1);
        }
    }
    printf("\n");

    return 0;
}