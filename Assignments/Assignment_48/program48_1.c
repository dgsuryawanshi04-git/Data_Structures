/////////////////////////////////////////////////////////////////////
//
//  Function Name : ReplaceEven
//  Description :   Replace Even numbers of nodes with 0.
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

void ReplaceEven(PPNODE first)
{
    PNODE temp = NULL;
    
    temp = *first;
    printf("Replace even numbers with 0:\n");
    while(temp != NULL)
    {
        if((temp->data % 2) == 0)
        {
            temp->data = 0;
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

    ReplaceEven(&head);
    
    return 0;
}