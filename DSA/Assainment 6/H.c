#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(int i=0;i<n;i++)
  for(int j=i+1;j<n;j++)
  if(a[i]>a[j])
  {
    int x=a[i];
    a[i]=a[j];
    a[j]=x;
  }
  int max=0;
  for(int i=0;i<n;i++)
  if(a[i]*(n-i)>=max)
  max=a[i]*(n-i);
  printf("%d",max);
}
