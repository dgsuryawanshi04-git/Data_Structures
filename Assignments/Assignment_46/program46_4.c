/////////////////////////////////////////////////////////////////////
//
//  Function Name : ReplaceNegative
//  Description :   Replace negative number with zero.
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

void ReplaceNegative(PPNODE first)
{
    PNODE temp = NULL;

    temp = *first;
    while(temp != NULL)
    {
        if(temp->data < 1)
        {
            temp->data = 0;
        }
        temp = temp->next;
    }
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
    InsertFirst(&head, -111);
    InsertFirst(&head, 101);
    InsertFirst(&head, -51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    ReplaceNegative(&head);

    printf("Replace negative values with zero :\n\n");

    Display(head);

    return 0;
}