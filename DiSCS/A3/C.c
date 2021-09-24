#include<stdio.h>
void recurse(int n,int g[][n][2],int v[],int s,int *out,int k,int l)
{
	if(v[s]==0)
	{
		//printf("%d ",s);
		l++;
		v[s]=1;
		for(int i=0;i<n;i++)
		{
			if(g[s][i][0]==1 && l!=n);
			{					
				k = k + g[s][i][1];
				//printf("%d ",k);
				recurse(n,g,v,i,out,k,l);
				//printf("%d\n",c);	
				k=k-g[s][i][1];			
			}
		}
		
		if(l==n && g[s][0][0]==1)
		{
			//printf("%d\n",g[s][0][1]);
			k = k + g[s][0][1];
			if(k<=(*out))
			{
				(*out) = k;				
				//printf("%d\n",(*out));
			}
			k=k-g[s][0][1];
		}
		v[s]=0;
		l--;
	}
}
	
void main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[m][3];
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	int g[n][n][2],v[n];
	for(int i=0;i<n;i++)
	{
		v[i]=0;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				g[i][j][k]=0;
			}
		}
	}

	for(int i=0;i<m;i++)
	{
		int x = a[i][0];
		int y = a[i][1];
		g[x][y][0]= 1;
		g[x][y][1]=a[i][2];
		g[y][x][0]= 1;
		g[y][x][1]=a[i][2];
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",g[i][j][1]);
		}
		printf("\n");
	}*/
	int outc=1000000;
	int *out = &outc;
	int l =0;
	int c=0;
	recurse(n,g,v,0,out,c,l);
	printf("%d\n",outc);
}
	
	
	
/////
