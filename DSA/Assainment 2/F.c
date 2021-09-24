#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node *fHead = NULL, *fTail = NULL;
Node *sHead = NULL, *sTail = NULL;
Node *finalH = NULL, *finalT = NULL;

void add(int item)
{
    if(finalH == NULL)
    {
        finalH = malloc(sizeof(Node));
        finalH->prev = NULL;
        finalH->next = NULL;
        finalH->data = item;
        finalT = finalH;
        return;
    }

    Node* new = malloc(sizeof(Node));
    new->data = item;
    new->prev = finalT;
    new->next = NULL;
    finalT->next = new;
    finalT = new;
} 

void printList(Node* head)
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void merge()
{
    Node* fPtr = fHead;
    Node* sPtr = sHead;
    while(fPtr != NULL && sPtr != NULL)
    {
        if((fPtr->data) < (sPtr->data))
        {
            add(fPtr->data);
            fPtr = fPtr->next;
        }
        else
        {
            add(sPtr->data);
            sPtr = sPtr->next;
        }
    }

    if(fPtr == NULL)
    {
        while(sPtr != NULL)
        {
            add(sPtr->data);
            sPtr = sPtr->next;
        }
    }
    else
    {
        while(fPtr != NULL)
        {
            add(fPtr->data);
            fPtr = fPtr->next;
        }
    }   
}

int main()
{
    int val; char c = '\0';

    while(c != '\n')  //for first list
    {
        scanf("%d%c", &val, &c);

        if(fHead == NULL)
        {
            fHead = malloc(sizeof(Node));
            fHead->data = val;
            fHead->prev = NULL;
            fHead->next = NULL;
            fTail = fHead;
        }
        else
        {
            Node* new = malloc(sizeof(Node));
            fTail->next = new;
            new->data = val;
            new->prev = fTail;
            new->next = NULL;
            fTail = new;
        }
    }

    c = '\0';
    while(c != '\n') //for second list
    {
        scanf("%d%c", &val, &c);

        if(sHead == NULL)
        {
            sHead = malloc(sizeof(Node));
            sHead->data = val;
            sHead->prev = NULL;
            sHead->next = NULL;
            sTail = sHead;
        }
        else
        {
            Node* new = malloc(sizeof(Node));
            sTail->next = new;
            new->data = val;
            new->prev = sTail;
            new->next = NULL;
            sTail = new;
        }
    }

    merge();
    printList(finalH);      

    return 0;
}