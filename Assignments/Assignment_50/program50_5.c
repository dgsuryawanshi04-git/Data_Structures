
/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayX
//  Description :   Display nodes at Nth position.
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

void DisplayX(PNODE first, int pos)
{
    int iCnt = 0;
    for(iCnt = 1; iCnt <= pos; iCnt++)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
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

    DisplayX(head, 4);
   

    return 0;
}