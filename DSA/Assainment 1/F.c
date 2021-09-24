#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    char bit;
    struct node* next;
}*addend = NULL, *augend = NULL, *sum = NULL;

typedef struct node Node;

Node* insert(Node* head, char c)
{
    if(head == NULL)
    {
        head = malloc(sizeof(Node));
        head->bit = c;
        head->next = NULL;
        return head;
    }

    Node* ptr = malloc(sizeof(Node));
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    Node* new = malloc(sizeof(Node));
    new->bit = c;
    new->next = NULL;
    ptr->next = new;

    return head;
}

void printList(Node* head)
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        printf("%c", ptr->bit);
        ptr = ptr->next;
    }
    printf("\n");
}

Node* takeInput(Node* head)
{
    char c = '\0';
    while(1)
    {
        scanf("%c", &c);
        if(c != '\n')
            head = insert(head, c);
        else
            break;
    }
    return head;
}

Node* reverseList(Node* head)
{
    if(head->next == NULL)
        return head;

    Node* back = NULL;
    Node* curr = head;
    Node* front = head->next;

    while(front->next != NULL)
    {
        curr->next = back;
        back = curr;
        curr = front;
        front = front->next;
    }

    head = front;
    head->next = curr;
    curr->next = back;

    return head;
}

Node* add(Node* addend, Node* augend)
{
    addend = reverseList(addend);
    augend = reverseList(augend);

    Node* addPtr = addend;
    Node* augPtr = augend;

    int c = 0;
    
    while(addPtr != NULL && augPtr != NULL)
    {
        int a = (int)(addPtr->bit) - 48;
        int b = (int)(augPtr->bit) - 48;

        char tempSum = (char)((a^b)^c + 48);
        c = (a&b)|(c&(a^b));

        sum = insert(sum, tempSum);
        addPtr = addPtr->next;
        augPtr = augPtr->next;
    }


    if(addPtr == NULL)
    {
        while(augPtr != NULL)
        {
            int b = (int)(augPtr->bit -48);

            char tempSum = (char)(b^c + 48);
            c = b&c;

            sum = insert(sum, tempSum);
            augPtr = augPtr->next;
        }
    }

    else
    {
        while(addPtr != NULL)
        {
            int a = (int)(addPtr->bit - 48);

            char tempSum = (char)(a^c + 48);
            c = a&c;
            
            sum = insert(sum, tempSum);
            addPtr = addPtr->next;
        }
    }

    if(c == 1)
        sum = insert(sum, '1');

    return reverseList(sum);
}

int main()
{   
    addend = takeInput(addend);
    augend = takeInput(augend);

    sum = add(addend, augend);
    printList(sum);

    return 0;
}