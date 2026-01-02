
/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayAlternate
//  Description :   Display Alternate elements of the list.
//  Input :         -
//  Output :        -
//  Auther :        Digvijay Gokul Suryawanshi
//  Date :          02/01/2026
//
/////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void DisplayAlternate(PNODE first)
{
    while(first != NULL)
    {
        printf(" | %d | -> ",first->data);
        first = first->next->next;
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
    printf("NULL\n");

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

    DisplayAlternate(head);
   

    return 0;
}