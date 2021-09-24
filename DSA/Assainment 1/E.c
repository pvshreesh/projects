#include <stdio.h>
#include <math.h>
#include <string.h>

int isPalindrome(char str[], int l, int r)
{
    for(int i = l; i <=(r+l)/2; i++)
    {
        if(str[i] != str[r+l-i])
            return 0;
    }
    return 1;
} 

void reverse(char str[], int prev, int end)
{
    for(int i = end; i >= prev; i--)
        printf("%c", str[i]);

    printf(" ");
}

int main()
{
    char str[(int)pow(10, 6)];
    scanf("%[^\n]s", str);

    int split[(int)pow(10, 5)][2];
    int sCount = 0;

    int prev = 0;
    for(int i = 0; i <= (int)strlen(str); i++)
    {
        if(str[i] == ' ' || i == (int)strlen(str))
        {
            reverse(str, prev, i-1);
            split[sCount][0] = prev;
            split[sCount++][1] = i-1; 
            prev = ++i;
        }
    }
    printf("\n");

    int hasPalindrome = 0;

    for(int i = 0; i < sCount; i++)
    {
        if(isPalindrome(str, split[i][0], split[i][1]))
        {
            hasPalindrome = 1;
            for(int j = split[i][0]; j <= split[i][1]; j++)
                printf("%c", str[j]);

            printf("\n");
        }
    }

    if(!hasPalindrome)
        printf("NO PALINDROMES\n");

    return 0;
}

