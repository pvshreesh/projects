#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head = NULL;

typedef struct node Node;

void insert(int item)
{
    if(head == NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->data = item;
        head->next = NULL;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    Node* new = (Node*)malloc(sizeof(Node));
    new->data = item;
    new->next = NULL;
    ptr->next = new;
}

void delete(Node* delPtr)
{
    if(head == delPtr)
    {
        head = head->next;
        free(delPtr);
        return;
    }
    Node* ptr = head;
    while(ptr->next != delPtr)
        ptr = ptr->next;

    ptr->next = delPtr->next;
    free(delPtr);
}


int main()
{
    int n; char c;
    while(c != '\n')
    {
        scanf("%d%c", &n, &c);
        insert(n);
    }


    //printf("%d\n", n);

    Node* curr = head->next;
    Node* prev = head;
    while(curr != NULL)
    {
        if(curr->data == prev->data)
            delete(prev);

        prev = curr;
        curr = curr->next;
    }

    curr = head;
    int count = 0;
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    printf("%d\n", count);
    
    curr = head;    
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}