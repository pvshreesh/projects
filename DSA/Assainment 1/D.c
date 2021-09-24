#include<stdio.h>
#include<math.h>
#include<string.h>

int isInDone(char c, char done[], int dCount)
{
    for(int i = 0; i < dCount; i++)
    {
        if(c == done[i])
            return 1;
    }
    return 0;
}

int getSubEndIndex(char str[], int i)
{
    int dCount = 1;
    char done[(int)strlen(str)];
    
    done[0] = str[i++];
    while(str[i] != '\0')
    {
        if(!isInDone(str[i], done, dCount))
            done[dCount++] = str[i];
        else
        {
            dCount = 0;
            return i;
        }

        i++;
    }

    return (int)strlen(str);
}
int main()
{
    char str[(int)pow(10, 6)];
    scanf("%s", str);

    int longestSubStr[(int)strlen(str)];

    for(int i = 0; i < (int)strlen(str); i++)
        longestSubStr[i] = getSubEndIndex(str, i);

    int max = longestSubStr[0] - 0;
    int maxI = 0;

    for(int i = 1; i < (int)strlen(str); i++)
    {
        if(max < (longestSubStr[i] - i))
        {
            max = (longestSubStr[i] - i);
            maxI = i;
        }
    }

    printf("%d\n", max);
    for(int i = maxI; i < longestSubStr[maxI]; i++)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}