#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>

int allLettersFound(int len, int wFill[])
{
    for(int i = 0; i < len; i++)
    {
        if(!wFill[i])
            return 0;
    }
    return 1;
}

void findLetter(char c, char word[], int wFill[])
{
    for(int i = 0; i < strlen(word); i++)
    {
        if(c == word[i] && !wFill[i])
        {
            wFill[i] = 1;
            return;
        }
    }
}

int lenUntilAllEnc(int i, char str[], char word[], int wFill[])
{
    if(i >= strlen(str))
    {
        return INT_MAX;
    }

    while(str[i] != '\0')
    {
        findLetter(str[i], word, wFill);
        if(allLettersFound(strlen(word), wFill))
        {
            for(int i = 0; i < strlen(word); i++)
                wFill[i] = 0;

            return i;
        }
        i++;
    }

    for(int i = 0; i < strlen(word); i++) //Resent filled elements...
        wFill[i] = 0;                     //...after every return.

    return INT_MAX;
}


int main()
{
    char str[(int)pow(10, 6)];
    scanf("%[^\n]s", str);  //Scans all characters until return character is encountered.

    char trash; scanf("%c", &trash);

    char word[(int)pow(10, 6)];
    scanf("%[^\n]s", word);

    int wFill[strlen(word)];
    for(int i = 0; i < strlen(word); i++)
        wFill[i] = 0;

    int lenToEnd[strlen(str)];

    for(int i = 0; i < strlen(str); i++)
        lenToEnd[i] = lenUntilAllEnc(i, str, word, wFill);

    int allEmpty = 1;
    for(int i = 0; i < strlen(str); i++)
    {
        if(lenToEnd[i] != INT_MAX)
        {
            allEmpty = 0;
            break;
        }
    }
    if(allEmpty)
    {
        printf("NO WINDOW\n");
        return 0;
    }

    int min = lenToEnd[0] - 0;
    int minI = 0;
    for(int i = 1; i < strlen(str); i++)
    {
        if(min > (lenToEnd[i] - i))
        {
            min = (lenToEnd[i] - i);
            minI = i;
        }
    }

    printf("%d %d\n", minI, lenToEnd[minI]);
    for(int i = minI; i <= lenToEnd[minI]; i++)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}