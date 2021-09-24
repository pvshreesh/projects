#include<stdio.h>
#include<string.h>
int function(char str[])
{
  int len=strlen(str),flag=0;
  for(int i=0;i<strlen(str);i++)
  if(str[i]==str[i+1])
  {
    flag=1;
    int count=0,index=i;
    while(str[i]==str[i+count])
    count++;
    for(int j=index+count;j<len;j++)
    str[index++]=str[j];
    str[index]='\0';
    break;
  }
  return flag;
}
int main()
{
  char str[500];
  gets(str);
  int flag=99;
  while(flag!=0)
  flag=function(str);
  printf("%s\n",strlen(str)?str:"VANISHED");
}
