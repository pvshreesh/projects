#include <stdio.h>

int tos = -1;
int front = 0;
int back = 0;
int level = 0;

int pop(int stack[])
{
	return stack[tos--];
}
int push(int stack[], int item)
{
	stack[++tos] = item;
}

void zigZagTraversal(int N, int gph[][N], int stack[], int Q[])
{
	int l;
	while(level%2 == 0 && tos != -1)
	{
		int elem = pop(stack);
		printf("%d ", elem); 
		l = 0;
		for(int j = 0; j < N; j++)
		{
			if(gph[elem][j] == -1 && l == 0)
			{
				Q[back++] = j;
				j = 0;
				l = 1;
			}
			if(gph[elem][j] == 1 && l == 1)
			{
				Q[back++] = j;
			}
		}
	}
	while(level%2 == 1 && front != back)
	{
		int elem = Q[front++];
		printf("%d ", elem);
		l = 0;    //refreshes l back to zero after every WHILE LOOP
		for(int j = 0; j < N; j++)
		{
			if(gph[elem][j] == -1 && l == 0)
			{
				push(stack, j);
				j = 0;
				l = 1;
			}
			if(gph[elem][j] == 1 && l == 1)
			{
				push(stack, j);
			}
		}
	}
	printf("\n");
	
	level++;
	if(tos != -1 || front != back)
		zigZagTraversal(N, gph, stack, Q);	
}

int main()
{
	int N;
	scanf("%d", &N);
	int gph[N][N];
	int stack[N];
	int Q[N];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			gph[i][j] = 0;
		}
	}
	int x, y; char trash, dir;
	for(int i = 0; i < N-1; i++)
	{
		scanf("%d%d%c%c", &x, &y, &trash, &dir);
		
		if(dir == 'L')
			gph[x][y] = -1;
		else if(dir == 'R')
			gph[x][y] = 1;
	}
	
	push(stack, 0);
	zigZagTraversal(N, gph, stack, Q);	
	
	return 0;
}
