#include <stdio.h>

void inorderToTree(int N, int gph[][N], int inorder[], int l, int r)
{
	if(l != r)
	{
		int mid = (l+r)/2;
		int lmid = (l+mid)/2;
		int rmid = (mid+1+r)/2;
		gph[inorder[mid]][inorder[lmid]] = -1;
		gph[inorder[mid]][inorder[rmid]] = 1;
		
		inorderToTree(N, gph, inorder, l, mid-1);
		inorderToTree(N, gph, inorder, mid+1, r);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int inorder[N];
	
	for(int i = 0; i < N; i++)
		scanf("%d", &inorder[i]);
		
	int n = 0;
	for(int i = 0; i < N; i++)
	{
		if(inorder[i] > n)
			n = inorder[i];
	}
	
	n = n+1; //because we need index n, so size in now n+1
		
	int gph[n][n];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			gph[i][j] = 0;
		}
	}
		
	inorderToTree(n, gph, inorder, 0, N-1);
	
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", gph[i][j]);
		}
		printf("\n");
	}*/
	
	int q;
	scanf("%d", &q);
	
	int found = 0;
	int x, left, right;
	for(int i =0; i < q; i++)
	{
		scanf("%d", &x);
		
		found = 0;
		for(int j = 0; j < n; j++)
		{
			if(gph[x][j] == -1)
			{
				left = j;
				//printf("Left: %d\n", j);
				found = 1;
			}
			if(gph[x][j] == 1)
			{
				right = j;
				//printf("Right: %d\n", j);
			}
		}
		if(!found)
		{
			printf("Left: NULL\n");
			printf("Right: NULL\n");
		}
		else
		{
			printf("Left: %d\n", left);
			printf("Right: %d\n", right);
		}
		printf("\n");
	}
				
	
	return 0;
}
