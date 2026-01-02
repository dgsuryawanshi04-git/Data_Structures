/////////////////////////////////////////////////////////////////////
//
//  Function Name : IncrementAll
//  Description :   Increment LinkedList elements by 1.
//  Input :         -
//  Output :        -
//  Auther :        Digvijay Gokul Suryawanshi
//  Date :          31/12/2025
//
/////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

void IncrementAll(PPNODE first)
{
    PNODE temp = NULL;

    temp = *first;
    printf("Linked List Incremented by 1:\n\n");

    while(temp != NULL)
    {
        temp->data = temp->data + 1;
        printf("| %d | -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL\n\n");

}

int main()
{

    PNODE head = NULL;

    InsertFirst(&head, 121);
    InsertFirst(&head, 111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    IncrementAll(&head);

    return 0;
}