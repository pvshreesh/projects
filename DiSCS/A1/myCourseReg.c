#include <stdio.h>

int final[45];
int count = 0;

void recurse(int elem, int nInputs, int req[][2])
{
	for(int i = 0; i < count; i++)
		if(elem == final[i])
			return;
	for(int i = 0; i < nInputs; i++)
	{
		if(elem == req[i][1])
			recurse(req[i][0], nInputs, req);
	}
	final[count++] = elem;
}

int main()
{
	for(int i = 0; i < 45; i++)
		final[i] = -1;
	int n;
	scanf("%d", &n);
	
	int input[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &input[i]);
	
	int nInputs;
	scanf("%d", &nInputs);
	
	int req[nInputs][2];
	for(int i = 0; i < nInputs; i++)
		scanf("%d%d", &req[i][0], &req[i][1]);
	
	printf("\n");
	
	for(int i = 0; i < n; i++)
		recurse(input[i], nInputs, req);
		
	for(int i = 0; i < count; i++)
		printf("%d ", final[i]);
		
	printf("\n");

	return 0;
}
