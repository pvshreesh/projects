# include <stdio.h>
# include <stdlib.h>
int final[45];
int c=0;
int rec(int req[][2],int start,int m);
void main()
		{
      		int n;scanf("%d",&n);
      		int input[n];
      		for(int i=0;i<n;i++)
      		{scanf("%d",&input[i]);}
      		int m; printf("Give m");
      		scanf("%d",&m);
      		int req[m][2];
      		
      		
      		for(int i=0;i<m;i++)
      		{
      		scanf("%d %d",&req[i][0],&req[i][1]);
      		}
      		
      		for(int i=0;i<45;i++)
      		{final[i]=-1;}
      		
      		for(int i=0;i<n;i++)
      		{rec(req,input[i],m);}
      		
      		for(int i=0;i<c; i++)
      		{printf("%d ",final[i]);}

  		}
  		
  		int rec(int req[][2],int start,int m)
  		{
  		
  		 for(int i=0;i<45;i++)
  		 {
  		  if(start==final[i]) {return 0;}
  		 }
  		 
  		 for(int i=0;i<m;i++)
  		 {
  		  if(start==req[i][1]) rec(req,req[i][0],m);
  		 }    final[c++]=start; return 0;
  		    
  		
  		}
