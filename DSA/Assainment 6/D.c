#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  char str[n][500];
  int a[n],stack[5000],t=-1;
  for(int i=0;i<n;i++)
  {
    scanf("%s",str[i]);
    if(str[i][1]=='u')
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++)
  {

    if(str[i][1]=='u')
    {
      stack[++t]=a[i];
      printf("OK PUSHED %d\n",stack[t]);
    }
    else if(str[i][3]=='k')
    {
      if(t<0)
      printf("STACK UNDERFLOW\n");
      else
      printf("%d\n",stack[t]);
    }
    else if(str[i][1]=='o')
    {
      if(t<0)
      printf("STACK UNDERFLOW\n");
      else
      printf("OK POPPED %d\n",stack[t--]);
    }
    else if(str[i][0]=='g')
    {
      if(t<0)
      printf("STACK UNDERFLOW\n");
      else
      {
      int min=99999;
      for(int j=0;j<=t;j++)
      if(stack[j]<min)
      min=stack[j];
      printf("%d\n",min);
      }
    }
  }
}
