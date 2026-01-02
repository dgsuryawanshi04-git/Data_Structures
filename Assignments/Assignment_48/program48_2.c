/////////////////////////////////////////////////////////////////////
//
//  Function Name : ReplaceOdd
//  Description :   Replace odd numbers of nodes with 1
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

void ReplaceOdd(PPNODE first)
{
    PNODE temp = NULL;
    
    temp = *first;
    printf("Replace odd numbers with 1 :\n");
    while(temp != NULL)
    {
        if((temp->data % 2) != 0)
        {
            temp->data = 1;
        }
        printf("| %d | -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
          
}

void InserFirst(PPNODE first, int no)
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
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int main()
{

    PNODE head = NULL;
    int iRet = 0;

    InserFirst(&head, 124);
    InserFirst(&head, 111);
    InserFirst(&head, 100);
    InserFirst(&head, 51);
    InserFirst(&head, 22);
    InserFirst(&head, 11);
    
    Display(head);

    ReplaceOdd(&head);
    
    return 0;
}