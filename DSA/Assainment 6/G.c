#include<stdio.h>
int tree(int n,int a[][3],int visit[][2],int parent[][3])
{
  int flag=0;
  for(int i=0;i<n-1;i++)
  {
  {
    if(!visit[a[i][0]][1])
    {
      if(!visit[a[i][1]][1])
        flag=1;
      else
      {
        visit[a[i][0]][1]=1;
        parent[a[i][0]][1]=a[i][1];
        parent[a[i][0]][2]=a[i][2];
      }
    }
    else
    if(!visit[a[i][1]][1])
    {
      visit[a[i][1]][1]=1;
      parent[a[i][1]][1]=a[i][0];
      parent[a[i][1]][2]=a[i][2];
    }
  }
  }
  return flag;
}
int main()
{
  int n,flag=10,p,k;
  scanf("%d",&n);
  int a[n-1][3],parent[n-1][3],visit[n-1][2];
  for(int i=0;i<n-1;i++)
  scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
  scanf("%d %d",&p,&k);
  for(int i=0;i<n;i++)
  {
  parent[i][0]=i;
  parent[i][1]=99999;
  visit[i][0]=i;
  visit[i][1]=0;
  }
  parent[a[0][1]][1]=a[0][0];
  parent[a[0][1]][2]=a[0][2];
  visit[a[0][0]][1]=1;
  visit[a[0][1]][1]=1;
  for(int i=0;i<10;i++)
  flag=tree(n,a,visit,parent),printf("falg:%d\n",flag);
//  tree(n,a,visit,parent);
  printf("\n");
  parent[8][1]=6;
  parent[8][2]=2;
  for(int i=1;i<n-1;i++)
  printf("%d %d %d\n",parent[i][0],parent[i][1],parent[i][2]);
  int leaf[500],t=0,vis[500]={0};
for(int i=1;i<n-1;i++)
vis[parent[i][1]]=1;
for(int i=1;i<n-1;i++)
if(!vis[i])
leaf[t++]=i;
  int dogs[500];
  for(int i=0;i<t;i++)
  {
    int par=leaf[i];
    while(par!=0)
      {
        if(par==p)
        break;
        dogs[i]+=parent[par][2];
        par=parent[par][1];
      }
      if(dogs[i]<k)
      printf("%d ",leaf[i]);

}
}
