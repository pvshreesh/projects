#include <stdio.h>
#include <string.h>

void merge(char str[][52], int l, int m, int r)
{
    int ll = m-l+1;
    int rl = r-m;

    char str1[ll][52];
    char str2[rl][52];

    for(int i = 0; i < ll; i++)
        strcpy(str1[i], str[l+i]);
    for(int i = 0; i < rl; i++)
        strcpy(str2[i], str[m+i+1]);

    int i = 0, j = 0;
    while(i < ll && j < rl)
    {
        if(strcmp(str1[i], str2[j]) <= 0)
        {
            strcpy(str[l+i+j], str1[i]);
            i++;
        }
        else
        {
            strcpy(str[l+i+j], str2[j]);
            j++;
        }
    }

    if(i < ll)
    {
        while(i < ll)
        {
            strcpy(str[l+i+j], str1[i]);
            i++;
        }
    }
    else
    {
        while(j < rl)
        {
            strcpy(str[l+i+j], str2[j]);
            j++;
        }
    }
}

void mergeSort(int N, char str[][52], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(N, str, l, m);
        mergeSort(N, str, m+1, r);
        merge(str, l, m, r);
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

    char posStr[nPos][52];
    char negStr[nNeg][52];

    for(int i = 0; i < nPos; i++)
        strcpy(posStr[i], str[pos[i]]);

    for(int i = 0; i < nNeg; i++)
        strcpy(negStr[i], str[neg[i]]);

    mergeSort(N, posStr, 0, nPos-1);
    mergeSort(N, negStr, 0, nNeg-1);

    for(int i = nPos-1; i>= 0; i--)
        printf("%s\n", posStr[i]);

    for(int i = 0; i < nNeg; i++)
        printf("%s\n", negStr[i]);

    return 0;
}