#include <stdio.h>

typedef struct pair
{
    int first;
    int second;
}Pair;

void swap(Pair* a, Pair* b)
{
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int N, Pair arr[], int l, int r)
{
    Pair x = arr[r];
    int i = l-1;
    for(int j = l; j < r; j++)
    {
        if(arr[j].first <= x.first)
        {
            i = i+1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quicksortPair(int N, Pair arr[], int l, int r)
{
    if(l < r)
    {
        int m = partition(N, arr, l, r);
        quicksortPair(N, arr, l, m-1);
        quicksortPair(N, arr, m+1, r);
    }
}
int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Pair arrPos[N];
    int vis[N];
    for(int i = 0; i < N; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
        vis[i] = 0;
    }

    quicksortPair(N, arrPos, 0, N-1);

    int nSwaps = 0;
    for(int i = 0; i < N; i++)
    {
        if(vis[i] || arrPos[i].second == i)
            continue;

        int cycleLen = 0;
        int j = i;
        while(!vis[j])
        {
            vis[j] = 1;
            cycleLen++;
            j = arrPos[j].second;
        }

        if(cycleLen > 0)
            nSwaps += (cycleLen-1);
    }

    printf("%d\n", nSwaps);   

    return 0;
}