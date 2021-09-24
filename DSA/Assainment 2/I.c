#include <stdio.h>
#include <string.h>
#include <math.h>

int N; //length of strings

void diff(char max[], char min[])
{
    char ans[N];
    int l = 0;
    int carry = 0;
    for(int i = N-1; i >= 0; i--)
    {
        int sum = carry + max[i] - min[i]; 
        if(sum < 0)
        {
            carry = -1;
            sum = sum+10;
            ans[l++] = (char)(sum+48);
        }
        else
        {
            carry = 0;
            ans[l++] = (char)(sum+48);
        }
    }

    int start = 0;
    for(int i = N-1; i>=1; i--)
    {
        if(ans[i] != '0')
        {
            start = i;
            break;
        }
    } 
    
    for(int i = start; i >= 0; i--)
        printf("%c", ans[i]);

    printf("\n");
}    

int main()
{
    char str[(int)pow(10, 5) + 1];
    scanf("%s", str);
    N = strlen(str);
    char max[N];
    char min[N];
    
    int digStr[10];
    for(int i = 0; i < 10; i++)
        digStr[i] = 0;

    for(int i = 0; i < N; i++)
        digStr[(int)str[i] - 48]++;

    //To get max num
    int l = 0;
    for(int i = 9; i>= 0; i--)
    {
        while(digStr[i]!=0)
        {
            max[l++] = (char)(i+48);
            digStr[i]--;
        }
    }

    //Get number of digits again
    for(int i = 0; i < N; i++)
        digStr[(int)str[i] - 48]++;

    
    //To get min num
    l = 0;
    if(digStr[0] > 0)
    {
        int k = 1;
        while(digStr[k] == 0)
            k++;

        min[0] = (char)(k+48);
        digStr[k]--;
        l = 1;
    }
    for(int i = 0; i < 10; i++)
    {
        while(digStr[i]!=0)
        {
            min[l++] = (char)(i+48);
            digStr[i]--;
        }
    }

    diff(max, min);  
        
    return 0;
}