#include <stdio.h>
#include <string.h>

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

void radixSort(int n, int ind[], char str[][52], int opt)
{
    int temp[n];
    int L = strlen(str[ind[0]]);
    
    for(int i = L-1; i >= opt; i--)
    {
        for(int j = 0; j < n; j++)
            temp[j] = (int)(str[ind[j]][i] - 48); 

        mergeSort(ind, temp, 0, n-1);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    char str[N][52];
    for(int i = 0; i < N; i++)
        scanf("%s", str[i]);

    int nPos = 0;
    int nNeg = 0;
    for(int i = 0; i < N; i++)
    {
        if(str[i][0] == '-')
            nNeg++;
        else
            nPos++;
    }
    int pos[nPos];
    int neg[nNeg];

    int p = 0, n = 0;
    for(int i = 0; i < N; i++)
    {
        if(str[i][0] == '-')
            neg[n++] = i;
        else
            pos[p++] = i;
    }

    int maxL = 0;
    for(int i = 0; i < nPos; i++)
    {
        if(maxL < strlen(str[pos[i]]))
            maxL = strlen(str[pos[i]]);
    }

    for(int i = 0; i < nPos; i++)
    {
        if(strlen(str[pos[i]]) < maxL)
        { 
            int strL = strlen(str[pos[i]]);
            int  l = strL;
            for(int j = 0; j < maxL-strL; j++)
            {
                for(int k = l; k >= 0; k--)
                    str[pos[i]][k+1] = str[pos[i]][k];
                
                str[pos[i]][0] = (char)(48);
                l++;
            }
        }
    }

    maxL = 0;
    for(int i = 0; i < nNeg; i++)
    {
        if(maxL < strlen(str[neg[i]]))
            maxL = strlen(str[neg[i]]);
    }

    for(int i = 0; i < nNeg; i++)
    {
        if(strlen(str[neg[i]]) < maxL)
        {
            int strL = strlen(str[neg[i]]);
            int l = strL;
            for(int j = 0; j < maxL-strL; j++)
            {
                for(int k = l; k >= 1; k--)
                    str[neg[i]][k+1] = str[neg[i]][k];

                str[neg[i]][1] = (char)(48);
                l++;
            }
        }
    }

    radixSort(nPos, pos, str, 0); //0 does radixSort for +ve nums
    radixSort(nNeg, neg, str, 1); //1 does radixSort for -ve nums

    for(int i = nPos-1; i>= 0; i--)
    {
        int ind = pos[i];
        int l = strlen(str[ind]);
        for(int j = 0; j < l; j++)
        {
            if(str[ind][j] != '0')
                printf("%c", str[ind][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < nNeg; i++)
    {
        int ind = neg[i];
        int l = strlen(str[ind]);
        for(int j = 0; j < l; j++)
        {
            if(str[ind][j] != '0')
                printf("%c", str[ind][j]);
        }
        printf("\n");
    }
    
    return 0;
}