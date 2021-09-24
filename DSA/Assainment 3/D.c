#include <stdio.h>
#include <string.h>

int checkStr(char str[], char sub[], int index)
{
    int c = 0;
    int l = 0;
    for(int i = index; i < strlen(sub) + index; i++)
    {
        if(str[i] == sub[l++])
            c++;
    }
    if(c == strlen(sub) || c == strlen(sub)-1)
        return 1;
    else
        return 0;
}

int main()
{
    char str[1000];
    scanf("%s", str);
    int count = 0;

    char sub[strlen(str)];
    scanf("%s", sub);

    for(int i = 0; i < strlen(str)-strlen(sub)+1; i++)
    {
        if(checkStr(str, sub, i))
            count++;
    }
    printf("%d\n", count);

    return 0;
}