#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int ll = m-l+1;
    int rl = r-m;

    int L[ll];
    int R[rl];

    for(int i = 0; i < ll; i++)
        L[i] = arr[l+i];
    for(int i = 0; i < rl; i++)
        R[i] = arr[m+1+i];

    int i = 0, j = 0;
    while(i < ll && j < rl)
    {
        if(L[i] <= R[j])
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

    while(i < ll)
    {
        arr[l+i+j] = L[i];
        i++;
    }
    while(j < rl)
    {
        arr[l+i+j] = R[j];
        j++;
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

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, N-1);

    int count = 1;
    int tot = 0;

    for(int i = 0; i < N-1; i++)
    {
        tot += count;
        if(arr[i+1] > arr[i])
            count++;
    }
    tot += count;
    printf("%d\n", tot);
    return 0;
}