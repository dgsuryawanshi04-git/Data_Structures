/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayOdd
//  Description :   Display odd number from the LinkedList.
//  Input :         -
//  Output :        -
//  Auther :        Digvijay Gokul Suryawanshi
//  Date :          30/12/2025
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
typedef struct node* PNODE;
typedef struct node** PPNODE;

void DisplayOdd(PNODE first)
{
    PNODE temp = first;
    int iCount = 0;

    printf("Odd numbers are:\n");
    while(temp != NULL)
    {
        if((temp->data % 2) != 0)
        {
            printf("%d\n",temp->data);
        }    
        temp = temp->next;        
    }
    printf("\n");
    
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

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf(" | %d | ->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int main()
{
    PNODE head = NULL;
    

    InsertFirst(&head, 51);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);

    InsertLast(&head, 100);
    InsertLast(&head, 111);
    InsertLast(&head, 122);

    Display(head);
    DisplayOdd(head);
    
    return 0;
}