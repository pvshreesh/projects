#include <stdio.h>

int min(int a, int b)
{
    return a<b ? a:b;
}
int max(int a, int b)
{
    return a>b ? a:b;
}

float getMedian(int l1, int r1, int arr1[], int l2, int r2, int arr2[])
{
    int m1, m2;
    int n = r1-l1+1;
    int mid1 = (l1+r1)/2;
    int mid2 = (l2+r2)/2;

    if(n == 2)
        return ((float)max(arr1[l1], arr2[l2]) + (float)min(arr1[r1], arr2[r2]))/2;

    if(n%2 == 1)
    {
        m1 = arr1[mid1];
        m2 = arr2[mid2];
    }
    else
    {
        m1 = (arr1[mid1] + arr1[mid1+1])/2;
        m2 = (arr2[mid2] + arr2[mid2+1])/2;
    }

    if(m1 < m2)
    {
        if(n%2 == 1)
            return getMedian(mid1, r1, arr1, l2, mid2, arr2);
        else
            return getMedian(mid1, r1, arr1, l2, mid2+1, arr2);
    }
    else
    {
        if(n%2 == 1)
            return getMedian(l1, mid1, arr1, mid2, r2, arr2);
        else
            return getMedian(l1, mid1+1, arr1, mid2, r2, arr2);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr1[N];
    int arr2[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr1[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr2[i]);

    float ans = getMedian(0, N-1, arr1, 0, N-1, arr2);

    if(ans == (int)ans)
        printf("\n%d\n", (int)ans);
    else
        printf("\n%0.1f\n", ans);

    return 0;
}