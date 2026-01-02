
/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayReverse
//  Description :   Display list in reverse.
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

void DisplayReverse(PNODE first)
{
    PNODE temp = NULL, last = NULL;

    while(first != last)
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        printf(" | %d | ->",temp->data);
        last = temp;
    }
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

    InserFirst(&head, 121);
    InserFirst(&head, 111);
    InserFirst(&head, 101);
    InserFirst(&head, 51);
    InserFirst(&head, 21);
    InserFirst(&head, 11);
    
    Display(head);

    printf("Linked List in reverse order:\n");

    DisplayReverse(head);
    
    return 0;
}