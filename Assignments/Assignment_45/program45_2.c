/////////////////////////////////////////////////////////////////////
//
//  Function Name : FirstOccur
//  Description :   return first occurence of the number.
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

int FirstOccur(PNODE first, int no)
{
    PNODE temp = first;
    int iPos = 1;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            return iPos;
        }    
        temp = temp->next;   
        iPos++;

    }
    return -1;
    
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
    int iRet = 0;    

    InsertFirst(&head, 51);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);

    InsertLast(&head, 100);
    InsertLast(&head, 51);
    InsertLast(&head, 122);

    Display(head);


    iRet = FirstOccur(head, 51);
    printf("First occurence is: %d\n",iRet);
    
    
    return 0;
}