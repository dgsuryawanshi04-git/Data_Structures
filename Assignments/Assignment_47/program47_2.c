/////////////////////////////////////////////////////////////////////
//
//  Function Name : CountDigits
//  Description :   Return Count of Digits of the node.
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

void CountDigits(PNODE first)
{
    int iDigit = 0, iCount = 0, num = 0;
    PNODE temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        iCount = 0;
        num = temp->data;
        while(num != 0)
        {
            iDigit = num % 10;
            num = num / 10;
            iCount++;
        }
        printf("count of Digits: %d\n",iCount);
        temp = temp->next;
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


    CountDigits(head);
    
    return 0;
}