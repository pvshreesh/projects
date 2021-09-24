#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

void merge(int shift[], double arr[], int l, int m, int r)
{
    int ll = m-l+1;
    int rl = r-m;

    double L[ll];
    double R[rl];

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
        if(L[i] < R[j])
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

void mergeSort(int shift[], double arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(shift, arr, l, m);
        mergeSort(shift, arr, m+1, r);
        merge(shift, arr, l, m, r);
    }
}

int minV, minX, minY;

double getAngle(int x, int y)
{
    double m = ((double)(y - minY) / (double)(x - minX)) ;
    
    if((x-minX) > 0)
        return atan(m);

    else if((x - minX) == 0)
        return PI/2;

    else
        return (PI + atan(m));
}

int main()
{
    int N;
    scanf("%d", &N);

    // [i][0] -> x coor
    // [i][1] -> y coor
    int coors[N][2];
    int v;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &v);
        scanf("%d%d", &coors[v-1][0], &coors[v-1][1]);
    }

    minY = coors[0][1];
    minX = coors[0][0];
    minV = 0;
    for(int i = 1; i < N; i++)
    {
        if(minY > coors[i][1])
        {
            minY = coors[i][1];
            minX = coors[i][0];
            minV = i;
        }
    }

    double angles[N];

    angles[minV] = 2*PI;

    for(int i = 0; i < N; i++)
    {
        if(i != minV)
            angles[i] = getAngle(coors[i][0], coors[i][1]);
    }

    int shift[N];
    for(int i = 0; i < N; i++)
        shift[i] = i;

    mergeSort(shift, angles, 0, N-1);

    int count = 0;
    for(int i = 0; i < N-1; i++)
    {
        count++;
        if(angles[i] < angles[i+1])
        {
            if(count > 1)
            {
                double lengths[count];
                int temp[count];
                for(int j = 0; j < count; j++)
                    temp[j] = i-j;
                
                for(int j = 0; j < count; j++)
                {
                    int x = coors[shift[i-j]][0];
                    int y = coors[shift[i-j]][1];
                    lengths[j] = abs(x-minX) + abs(y-minY);
                }

                mergeSort(temp, lengths, 0, count-1);

                for(int j = 0; j < count; j++)
                    printf("%d ", shift[temp[j]] + 1);
                
                count = 0;
            }
            else
            {
                count = 0;
                printf("%d ", shift[i]+1);
            }
        }
    }

    printf("\n");

    return 0;
}