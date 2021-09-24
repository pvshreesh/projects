#include<stdio.h>

int flag=0;
void makeZero(int n,int arr[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
}

int equals(int v,int arr1[v][v],int arr2[v][v])
{
	int f=1;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(arr1[i][j]!=arr2[i][j])
				f=0;
		}
	}
	return f;
}

void printFormat(int v,int arr[v])
{
	for(int i=0;i<v;i++)
	{
		printf("%d - %d\n",i,arr[i]);
	}
}

void swap(int v,int arr[v],int i,int start)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[start];
    arr[start] = temp;
}

void permutation(int v,int e,int test[v],int edges[e][2],int arr1[v][v],int arr2[v][v], int start, int end)
{
    if(start==end && flag==0)
    {
    	for(int i=0;i<e;i++)
    	{
    		arr2[test[edges[i][0]]][test[edges[i][1]]]=1;
    		arr2[test[edges[i][1]]][test[edges[i][0]]]=1;
    	}
    	if(equals(v,arr1,arr2)==1)
    	{
    		flag=1;
    		printf("YES\n");
    		printFormat(v,test);
    	}
    	makeZero(v,arr2);
        return;
    }
    for(int i=start;i<=end;i++)
    {
        swap(v,test,i,start);
        permutation(v,e,test,edges,arr1,arr2, start+1, end);
        swap(v,test,i,start);
    }
}
int main()
{
	int e1,v1,e2,v2;
	scanf("%d %d",&v1,&e1);
	int arr1[v1][v1];
	for(int i=0;i<v1;i++)
	{
		for(int j=0;j<v1;j++)
		{
			arr1[i][j]=0;
		}
	}
	int right,left;
	for(int i=0;i<e1;i++)
	{
		scanf("%d %d",&left,&right);
		arr1[left][right]=1;
		arr1[right][left]=1;
	}
	scanf("%d %d",&v2,&e2);
	int edges2[e2][2];
	for(int i=0;i<e2;i++)
	{
		scanf("%d %d",&edges2[i][0],&edges2[i][1]);
	}
	if(v1!=v2 || e1!=e2)
	{
		printf("NO\n");
		return 0;
	}
	int test[v2];
	for(int i=0;i<v2;i++)
	{
		test[i]=i;
	}
	int arr2[v2][v2];
	makeZero(v2,arr2);
	permutation(v2,e2,test,edges2,arr1,arr2, 0, v2-1);
	if(flag==0)
		printf("NO\n");
	return 0;
}	