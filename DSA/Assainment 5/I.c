#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int bFlag = 0;

void binarySearch(int arr[], int val, int l, int r)
{  
    if(l < r)
    {
        int m = (l+r)/2;

        if(val == arr[m])
            bFlag = 1;
        else if(val < arr[m])
            binarySearch(arr, val, l, m);
        else
            binarySearch(arr, val, m+1, r);
    }
}

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

    int q;
    scanf("%d", &q);

    mergeSort(arr, 0, N-1);

    int l = 0;
    int r = INT_MAX;
    int minDiff = INT_MAX;
    int minL, minR;
    int flag = 0;

    for(int i = 0; i < N; i++)
    {
        bFlag = 0;
        int temp = q - arr[i];
        binarySearch(arr, temp, 0, N-1);
        if(bFlag == 1 && temp != arr[i])
        {
            l = arr[i];
            r = temp;
            flag = 1;
        }

        if(abs(r - l) < minDiff)
        {
            minDiff = abs(r-l);
            minL = l;
            minR = r;
        }
    }

    if(flag == 1)
    {
        printf("YES\n");
        if(minL < minR)
            printf("%d %d\n", minL, minR);
        else
            printf("%d %d\n", minR, minL); 
    }
    else
        printf("NO\n");

    return 0;
}