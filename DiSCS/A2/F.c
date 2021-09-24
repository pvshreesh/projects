#include <stdio.h>

int main()
{
	int N, nInputs;
	scanf("%d%d", &N, &nInputs);	
	
	int vis[N];
	for(int i = 0; i < N; i++)
		vis[i] = 0;
		
	vis[0] = 1;
	 
	int inputs[nInputs][2];
	for(int i = 0; i < nInputs; i++)
	{
		scanf("%d%d", &inputs[i][0], &inputs[i][1]);
		if(vis[inputs[i][0]-1] == 1) vis[inputs[i][1]-1] = 2;
		else if(vis[inputs[i][0]-1] == 2) vis[inputs[i][1]-1] = 1;
		else if(vis[inputs[i][1]-1] == 1) vis[inputs[i][0]-1] = 2;
		else if(vis[inputs[i][1]-1] == 2) vis[inputs[i][0]-1] = 1;
	}
	
	int flag = 1;
	for(int i = 0; i < nInputs; i++)
	{
		if(vis[inputs[i][0]-1] == vis[inputs[i][1]-1])
			flag = 0;
	}
	
	printf("\n");
	if(flag == 0)
		printf("NO\n");
		
	else
	{
		printf("YES\n");
		for(int i = 0; i < N; i++)
		{
			if(vis[i] == 1)
				printf("R");
			else if(vis[i] == 2)
				printf("B");
		}
		printf("\n");
	}	 	 
		
	return 0;
}


//
