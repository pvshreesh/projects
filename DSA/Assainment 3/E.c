#include <stdio.h>
#include <stdlib.h>

int length = 0;

typedef struct node
{
    int data;
    struct node* next;
}Node;
Node* head = NULL;

void interconnect()
{
    
    Node* hptr = head;
    Node* ptr = NULL;
    Node* temp = NULL;
    Node* tptr = NULL;

    for(int i = 0; i < length/2; i++)
    {
        ptr = hptr;
        while(ptr->next != tptr)
            ptr = ptr->next;

        tptr = ptr;
        temp = hptr->next;
        hptr->next = tptr;   
        if(tptr != temp) tptr->next = temp;
        else tptr->next = NULL;

        if(temp->next == tptr)
        {
            temp->next = NULL;
            return;
        }
        hptr = temp;

    }
}   

int main()
{
    int val; char c = '\0';

    while(c != '\n')
    {
        scanf("%d%c", &val, &c); 
        if(head == NULL)
        {
            head = malloc(sizeof(Node));
            head->data = val;
            head->next = NULL;
            length++;
        }
        else
        {
            Node* new = malloc(sizeof(Node));
            new->data = val;
            new->next = NULL;
            Node* ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            
            ptr->next = new;
            length++;
        }
    }

    interconnect();

    Node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
    return 0;
}