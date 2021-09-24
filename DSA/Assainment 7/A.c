#include <stdio.h>

int heapSize = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left(int i)
{
    return 2*i + 1;
}

int right(int i)
{
    return 2*(i+1);
}

int parent(int i)
{
    if( i%2 == 1)
        return i/2;
    else
        return (i/2)-1;
}

void maxHeapify(int N, int info[][3], int A[], int i)
{
    int largest, pl, pr, lIndex;
    int l = left(i);
    int r = right(i);
    int pi = info[A[i]][0];

    if(l < heapSize)
        pl = info[A[l]][0];

    if(r < heapSize)
        pr = info[A[r]][0];

    if(l < heapSize && pl > pi)
    {
        largest = pl;
        lIndex = l;
    }
    else if(l < heapSize && pl == pi)
    {
        largest = pl;
        /*printf("Hello2 %d\n", A[i]);
        printf("2prep = %d || 4prep = %d\n", info[A[i]][2], info[A[l]][2]);*/ 
        if(info[A[l]][2] < info[A[i]][2])
            lIndex = l;
        else
            lIndex = i;
    }
    else
    {
        largest = pi;
        lIndex = i;
    }
    
    if(r < heapSize && pr > largest)
    {
        largest = pr;
        lIndex = r;
    }
    else if(r < heapSize && pr == largest)
    {
        largest = pr;
        if(info[A[r]][2] < info[A[lIndex]][2])
            lIndex = r;
    }

    if(lIndex != i)
    {
        swap(&A[i], &A[lIndex]);
        maxHeapify(N, info, A, lIndex);
    }
}

void removeMax(int N, int info[][3], int A[])
{
    swap(&A[0], &A[heapSize-1]);
    heapSize--;
    maxHeapify(N, info, A, 0);
}

void insert(int N, int info[][3], int A[], int key)
{
    heapSize++;
    //printf("Here - %d\n", key+1);
    A[heapSize-1] = key;
    
    int i = heapSize-1;
    //printf("In >> %d <= %d\n", info[A[parent(i)]][0], info[A[i]][0]);
    
    while(i > 0 && info[A[parent(i)]][0] <= info[A[i]][0])
    {
        if(info[A[parent(i)]][0] == info[A[i]][0])
        {
            if(info[A[parent(i)]][2] > info[A[i]][2])
                swap(&A[parent(i)], &A[i]);
            else
                break;
        }
        else        
            swap(&A[parent(i)], &A[i]);

        i = parent(i);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];

    int info[N][3]; //0 - priority ;;;; 1 - arrival ;;;; 2 - prepTime
    int trash;
    for(int i = 0; i < N; i++)
        scanf("%d%d%d%d", &trash, &info[i][0], &info[i][1], &info[i][2]);

    int inQueue[N];
    for(int i = 0; i < N; i++)
        inQueue[i] = 0;

    //Using Priority Queue with Max-Heap implementation

    printf("\n");
    int time = 1;
    int done = 0;
    while(done != N)
    {
        for(int i = 0; i < N; i++)
        {
            if(info[i][1] == time && !inQueue[i])
            {
                insert(N, info, A, i);
                inQueue[i] = 1;
            }
        }

        if(heapSize != 0)
            info[A[0]][2]--;

        if(info[A[0]][2] == 0)
        {
            printf("%d %d\n", A[0]+1, time+1);
            removeMax(N, info, A);
            done++;
        }

        time++;
    }   

    return 0;
}
/*
INPUTS
6
1 2 5 3
2 1 5 3
3 6 3 6
4 1 2 2
5 5 7 5
6 3 3 4
*/