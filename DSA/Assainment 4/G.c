#include <stdio.h>
#include <stdlib.h>

int length = 0;

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;

void split(Node* mHead, Node** l, Node** r)
{
    Node* fast;
    Node* slow;
    slow = mHead;
    fast = mHead->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *l = mHead;
    *r = slow->next;
    slow->next = NULL;
}

Node* sortedMerge(Node* l, Node* r)
{
    Node* result = NULL;
    
    if(l == NULL)
        return r;
    else if(r == NULL)
        return l;

    if(l->data <= r->data)
    {
        result = l;
        result->next = sortedMerge(l->next, r);
    }
    else
    {
        result = r;
        result->next = sortedMerge(l, r->next);
    }
    return result;
}

void mergeSort(Node** headRef)
{
    Node* l;
    Node* r;
    Node* mHead = *headRef;

    if(mHead == NULL || mHead->next == NULL)
        return;

    split(mHead, &l, &r);

    mergeSort(&l);
    mergeSort(&r);

    *headRef = sortedMerge(l, r);
}        

int main()
{
    char c = '\0';
    int val;
    while(c != '\n')
    {
        scanf("%d%c", &val, &c);
        if(head == NULL)
        {
            head = malloc(sizeof(Node));
            head->data = val;
            head->next = NULL;
        }
        else
        {
            Node* ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;

            Node* new = malloc(sizeof(Node));
            new->data = val;
            ptr->next = new;
            new->next = NULL;
        }
    }

    mergeSort(&head);

    Node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    printf("\n");
    return 0;
}