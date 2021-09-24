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
    int N, M, L;
    scanf("%d%d%d", &N, &M, &L);

    int src, dest, a, b, r;
    scanf("%d%d%d%d%d", &src, &dest, &a, &b, &r);

    int tolls[M];
    for(int i = 0; i < M; i++)
        scanf("%d", &tolls[i]);

    int fCap[L];
    for(int i = 0; i < L; i++)
        scanf("%d", &fCap[i]);

    mergeSort(tolls, 0, M-1);
    mergeSort(fCap, 0, L-1);

    int p = 0;
    for(int i = 0; i < M; i++)
    {
        if(tolls[i] == src)
        {
            p = i;
            break;
        }
    }

    unsigned long tot = 0;

    //the mileage is aZ+b; Z is the fuel in car

    while(tolls[p] != dest)
    {
        int dist = tolls[p+1] - tolls[p];

        int z = (dist-b)/a;
        if((dist-b) % a != 0) z = z+1;

        int flag = 0;
        for(int i = 0; i < L; i++)
        {
            if(fCap[i] >= z)
            {
                tot += fCap[i];
                flag = 1;
                break;
            }
        }

        if(flag == 0)   
        {
            printf("NOT POSSIBLE\n");
            return 0;
        }
        p++;
    } 

    printf("%lu\n", tot*r);

    return 0;
}