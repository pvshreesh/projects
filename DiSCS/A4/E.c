#include <stdio.h>
#include <stdlib.h>

int preIndex = 0;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* ansNode = NULL;

struct node* buildBinaryTree(int N, int inorder[], int preorder[], int l, int r)
{
	if(l > r)
		return NULL;
		
	struct node* tnode = (struct node*)malloc(sizeof(struct node));
	tnode->data = preorder[preIndex++];
	tnode->left = NULL;
	tnode->right = NULL;
	
	if(l == r)
		return tnode;
		
	int mid = l;
	
	while(inorder[mid] != tnode->data)
		mid++;
		
	tnode->left = buildBinaryTree(N, inorder, preorder, l, mid-1);
	tnode->right = buildBinaryTree(N, inorder, preorder, mid+1, r);
	
	return tnode;	//Only there to return to "root" in main()
}

void getNode(struct node* tnode, int item)
{
	if(tnode == NULL)
		return;
		
	if(tnode->data == item)
		ansNode = tnode;
	
	getNode(tnode->left, item);
	getNode(tnode->right, item);
}
		 
int main()
{
	int N;
	scanf("%d", &N);	
	
	int inorder[N];
	int preorder[N];
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &inorder[i]);
	}
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &preorder[i]);
	}
	
	struct node* root = buildBinaryTree(N, inorder, preorder, 0, N-1);
	
	int q;
	scanf("%d", &q);
	
	int item;
	for(int i = 0; i < q; i++)
	{
		scanf("%d", &item);
		getNode(root, item);
		
		if(ansNode->left == NULL)
			printf("X ");
		else 
			printf("%d ", ansNode->left->data);
			
		if(ansNode->right == NULL)
			printf("X\n");
		else
			printf("%d\n", ansNode->right->data);
			
		ansNode = NULL;
	}		
	
	return 0;
}
