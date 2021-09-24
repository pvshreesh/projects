#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  char str[500];
  gets(str);
  for(int i=0;i<strlen(str);i++)
  {
    int count=0;
    if(str[i]==str[i+1]-2||str[i]==str[i+1]-1)
    continue;
    else if(str[i]=='['||str[i]=='{')
    while((str[i]!=str[count]-2)&&count<strlen(str))
    count++;
    else if(str[i]=='(')
    while((str[i]!=str[count]-1)&&count<strlen(str))
    count++;
    else
    continue;
    if((i-count-1)%2)
    printf("NO\n",count),exit(0);
    if(count>strlen(str))
    printf("NO\n"),exit(0);
  }
  printf("YES\n");
}
