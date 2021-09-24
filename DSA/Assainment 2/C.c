#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;
int length = 0;

void printList()
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
} 

void add(int val)
{
    length++;
    if(head == NULL)
    {
        head = malloc(sizeof(Node));
        head->data = val;
        head->next = NULL;
    }

    else
    {
        Node* ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;

        Node* new = malloc(sizeof(Node));
        new->data = val;
        ptr->next = new;
        new->next = NULL;
    }
    printList();
}

void insert(int val, int pos)
{
    length++;
    if(pos == 1)
    {
        Node* new = malloc(sizeof(Node));
        new->data = val;
        new->next = head;
        head = new;
    }
    else
    {
        Node* ptr = head;
        for(int i = 0; i < pos-2; i++)
            ptr = ptr->next;

        Node* new = malloc(sizeof(Node));
        new->data = val;
        new->next = ptr->next;
        ptr->next = new;
    }

    printList();
}

void deleteSingle(Node* delPtr)
{
    if(delPtr == head)
    {
        head = delPtr->next;
        free(delPtr);
        return;
    }

    Node* ptr = head;
    while(ptr->next != delPtr)
        ptr = ptr->next;

    ptr->next = delPtr->next;
    free(delPtr);
}    

void removeNodes(int val)
{
    Node* bptr = NULL;
    Node* iptr = head;
    Node* fptr = NULL;
    int foundf = 0;
    int foundb = 0;

    while(iptr!=NULL)
    {
        if(iptr->data == val)
        {
            bptr = iptr;
            foundb = 1;
        }
        iptr = iptr->next;
    }

    iptr = head;
    while(iptr!=NULL)
    {
        if(iptr->data == val && iptr != bptr)
        {
            fptr = iptr;
            foundf = 1;
            break;
        }
        iptr = iptr->next;
    }

    if(!foundf && !foundb)
    {
        printf("Element not found\n");
        return;
    }

    if(foundf)
    {
        deleteSingle(fptr);
        length--;
    }

    if(foundb)
    {
        deleteSingle(bptr);
        length--;
    }

    printList();
}

void reverseList()
{
    if(length == 0)
        return;

    Node* prec = NULL;
    Node* curr = head;
    Node* succ = head->next;

    while(succ != NULL)
    {
        curr->next = prec;
        prec = curr;
        curr = succ;
        succ = succ->next;
    }
    curr->next = prec;
    head = curr;
    printList();
}

void fetch(int index)
{
    Node* ptr = head;
    for(int i = 1; i < index; i++)
        ptr = ptr->next;

    printf("%d\n", ptr->data);
}

int main()
{
    int q;
    scanf("%d", &q);

    char str[10];

    int x, y;
    for(int i = 0; i < q; i++)
    {
        scanf("%s", str);
        if(strcmp(str, "add") == 0)
        {
            scanf("%d", &x);
            add(x);
        }
        else if(strcmp(str, "insert") == 0)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
        }
        else if(strcmp(str, "remove") == 0)
        {
            scanf("%d", &x);
            removeNodes(x);
        }
        else if(strcmp(str, "reverse") == 0)
        {
            reverseList();
        }
        else if(strcmp(str, "fetch") == 0)
        {
            scanf("%d", &x);
            fetch(x);
        }
    }

    return 0;
}