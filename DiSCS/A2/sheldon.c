#include<stdio.h>
int n;
int ptr=0;
int l=0;
int count=0;
int num;
void fun(char arr[],int x,int y,char mat[n][n])
{
	//printf("%d %d\n",x,y);
	ptr++;
	if(ptr<num)
	{
		if(x>0 && mat[x-1][y]==arr[ptr])
		{
		//ptr++;
		fun(arr,x-1,y,mat);
		//ptr--	;
		}
		
		if(y>0 && mat[x][y-1]==arr[ptr])
		{
		//ptr++;
		fun(arr,x,y-1,mat);	
		//ptr--;
		}
		
		if(x<n-1 && mat[x+1][y]==arr[ptr])
		{
		//ptr++;
		fun(arr,x+1,y,mat);
		//ptr--;	
		}
		
		if(y<n-1 && mat[x][y+1]==arr[ptr])
		{
		//ptr++;
		fun(arr,x,y+1,mat);
		//ptr--;	
		}
		
		if(x< n-1 && y < n-1  && mat[x+1][y+1]==arr[ptr])
		{
		//ptr++;
		fun(arr,x+1,y+1,mat)	;
		//ptr--;
		}
		
		
		if(x>0 && y>0 && mat[x-1][y-1]==arr[ptr])
		{
		//ptr++;
		fun(arr,x-1,y-1,mat);
		//ptr--;	
		}
		
		if(x<n-1&& y>0 && mat[x+1][y-1]==arr[ptr])
		{
		//ptr++;
		fun(arr,x+1,y-1,mat);
		//ptr--;	
		}
		
		if(y<n-1 && x>0 && mat[x-1][y+1]==arr[ptr])
		{
		//ptr++;
		fun(arr,x-1,y+1,mat);
		//ptr--;	
		}
	}
	
	if(ptr==num)
		count++;
	
	ptr--;
}



void main()
{
	char garb;
	scanf("%d",&n);
	char mat[n][n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%c",&garb);
		for(int j=0;j<n;j++)
		{
			scanf("%c",&mat[i][j]);
		}
	}
	//scanf("%c",&garb);
	scanf("%d",&num);
	char arr[num];
	/*scanf("%c",&garb);
	for(int i=0;i<num;i++)
	{
		scanf("%c",&arr[i]);
	}
	scanf("%c",&garb);*/
	scanf("%s",arr);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j]==arr[0])
			{
				fun(arr,i,j,mat);
				
			}
		}
	}
	printf("%d",count);
}
