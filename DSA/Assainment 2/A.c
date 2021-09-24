#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node* next;
    struct node* prev;
}Node;
Node* head = NULL;
Node* tail = NULL;

void insert(int item)
{
    if(head == NULL)
    {
        head = malloc(sizeof(Node));
        tail = malloc(sizeof(Node));
        head->data = item;
        head->prev = NULL;
        head->next = NULL;
        tail = head;
        return;
    }

    Node* new = malloc(sizeof(Node));
    new->data = item;
    tail->next = new;
    new->prev = tail;
    new->next = NULL;
    tail = new;
}

void rotate(char o, int n)
{
    Node* ptr;
    int temp;
    if(o == 'L')
    {
        for(int i = 0; i < n; i++)
        {
            ptr = head;
            temp = head->data;
            while(ptr->next != NULL)
            {
                ptr->data = ptr->next->data;
                ptr  = ptr->next;;
            }
            tail->data = temp;
        }
    }
    else if(o == 'R')
    {
        for(int i = 0; i < n; i++)
        {
            ptr = tail;
            temp = tail->data;
            while(ptr->prev != NULL)
            {
                ptr->data = ptr->prev->data;
                ptr = ptr->prev;
            }
            head->data = temp;
        }
    }
}

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

int main()
{
    int val; char c = '\0';
    while(c != '\n')
    {
        scanf("%d%c", &val, &c);
        insert(val);
    }

    scanf("%d%c%c", &val, &c, &c);

    rotate(c, val);
    printList();

    return 0;
}