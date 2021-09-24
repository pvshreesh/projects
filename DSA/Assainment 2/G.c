#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int x, int y)
{
    for(int i = x; i <= (x+y)/2; i++)
    {
        if(str[i] != str[x+y-i])
            return 0;
    }
    return 1;
}

int main()
{
    char str[500];
    scanf("%s", str);
    
    int N = strlen(str);
    int maxL = -1;
    int maxR = -1;
    int max = -1;
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            if(isPalindrome(str, i, j))
            {
                if((j-i) > max)
                {
                    max = j-i;
                    maxL = i;
                    maxR = j;
                }
            }
        }
    }

    printf("%d\n", max+1);
    for(int i = maxL; i <=maxR; i++)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}