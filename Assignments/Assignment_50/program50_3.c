
/////////////////////////////////////////////////////////////////////
//
//  Function Name : CheckSorted
//  Description :   check LinkedList is sorted or not (Ascending order).
//  Input :         -
//  Output :        -
//  Auther :        Digvijay Gokul Suryawanshi
//  Date :          02/01/2026
//
/////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

#pragma pack(1)
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

BOOL CheckSoerted(PNODE first)
{
    if((first == NULL) || (first->next == NULL))
    {
        return TRUE;
    }

    while (first->next != NULL)
    {
        if(first->data > first->next->data)
        {
            return FALSE;
        }     
        first = first->next;   
    }
    return TRUE;    
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
    BOOL bRet = FALSE;

    InsertFirst(&head, 121);
    InsertFirst(&head, 111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    bRet = CheckSoerted(head);

    if(bRet == TRUE)
    {
        printf("Linked list is sorted\n");
    }
    else
    {
        printf("Linked list is not sorted\n");
    }

    return 0;
}