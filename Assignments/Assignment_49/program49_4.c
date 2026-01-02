/////////////////////////////////////////////////////////////////////
//
//  Function Name : CountDivByFive
//  Description :   Count of nodes that are divisible by five.
//  Input :         -
//  Output :        -
//  Auther :        Digvijay Gokul Suryawanshi
//  Date :          01/01/2026
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

int CountDivByFive(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        if((first->data % 5) == 0)
        {
            iCount++;
        }
        first = first->next;
    }
    return iCount;
     
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
    int iRet = 0;

    InsertFirst(&head, 121);
    InsertFirst(&head, 150);
    InsertFirst(&head, 101);
    InsertFirst(&head, 55);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = CountDivByFive(head);
    printf("Count of nodes that are divisible by five: %d\n",iRet);

    return 0;
}