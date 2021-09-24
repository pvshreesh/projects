#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*fn; //global variable fn;

struct node* makeTree(int n, int arr[], int l, int r)
{
    if(l >= r) return NULL;

    struct node* node1 = (struct node*)malloc(sizeof(struct node));

    int mid = (l+r)/2;
    node1->data = arr[mid];

    node1->left = makeTree(n, arr, l, mid);
    node1->right = makeTree(n, arr, mid+1, r);

    return node1;
}

void findNode(struct node* n1, int item)
{
    if(n1->data == item)
    {
        fn = n1;
        return;
    }
    if(n1->left == NULL) return;

    findNode(n1->left, item);
    findNode(n1->right, item);
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];  //arr[] = {1, 4, 2, 0, 6, 7, 5};

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    struct node* head = makeTree(N, arr, 0, N);

    int nInputs;
    scanf("%d", &nInputs);
    int q;
    for(int i = 0; i < nInputs; i++)
    {
        scanf("%d", &q);
        findNode(head, q);
        if(fn->left == NULL)
        {
            printf("Left: NULL\nRight: NULL\n");
        }
        else
        {
            printf("Left: %d\n", fn->left->data);
            printf("Right: %d\n", fn->right->data);
        }
    }

    return 0;
}