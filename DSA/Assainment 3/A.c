#include <stdio.h>
#include <limits.h>

void getAllCounts(int N, int arr[], int count[])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i] == arr[j])
                count[i]++;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    int count[N];

    for(int i = 0; i < N; i++)
    {
        count[i] = 0;
        scanf("%d", &arr[i]);
    }
    
    getAllCounts(N, arr, count);

    int found = 0;

    if(N%2 == 1)
    {
        for(int i = 0; i < N; i++)
        {
            if(count[i] > N/2)
            {
                found = 1;
                printf("%d\n", arr[i]);
                break;
            }
        }
    }
    else
    {
        int max = INT_MIN;
        for(int i = 0; i < N; i++)
        {
            if(count[i] > N/2)
            {
                found = 1;
                printf("%d\n", arr[i]);
                break;
            }

            else if(count[i] == N/2)
            {
                max = arr[i];
                for(int j = 0; j < N; j++)
                {
                    if(arr[j] > arr[i] && count[j] == N/2)
                        max = arr[j];
                }
                found = 1;
                printf("%d\n", max);
                break;
            }
        }
    } 

    if(!found) printf("NO MAJORITY ELEMENT\n");

    return 0;
}