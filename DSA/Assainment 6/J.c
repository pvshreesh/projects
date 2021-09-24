#include<stdio.h>
void sort(int a[][3],int n)
{
  for(int i=0;i<n;i++)
  for(int j=i+1;j<n;j++)
  {if(a[i][1]>a[j][1])
  for(int k=0;k<3;k++)
  {
    int x=a[i][k];
    a[i][k]=a[j][k];
    a[j][k]=x;
  }
  else if(a[i][1]==a[j][1])
  {
    if(a[i][0]>a[j][0])
    for(int k=0;k<3;k++)
    {
      int x=a[i][k];
      a[i][k]=a[j][k];
      a[j][k]=x;
    }
  }
}
}
int main()
{
  int n;
  scanf("%d",&n);
  int a[n][3],time[500]={0};
  for(int i=0;i<n;i++)
  scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]),time[a[i][0]]=a[i][2];
  sort(a,n);
  int clk=0,que[500],t=0,vis[500]={0},finish[500]={0};
while(1)//for clock
{
  for(int j=n-1;j>=0;j--)
  if(a[j][1]<=clk&&!vis[a[j][0]])
  {que[t++]=a[j][0];
    vis[a[j][0]]=1;
  }
  {time[que[t-1]]--;
  if(!time[que[t-1]])
  {finish[que[t-1]]=clk+1;t--;}
  }
    clk++;
    if(t==0)
    break;
  }
  for(int i=0;i<n;i++)
  printf("%d %d\n",a[i][0],finish[a[i][0]]);
}
