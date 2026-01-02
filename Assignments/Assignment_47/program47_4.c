/////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayPrime
//  Description :   Display prime numbers.
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

void DisplayPrime(PNODE first)
{
    int iCnt = 0, iCount = 0;
    
    while(first != NULL)
    {
        iCount = 0;
        for(iCnt = 2; iCnt < (first->data / 2); iCnt++)
        {
            if((first->data % iCnt) == 0)
            {
                iCount++;
                break;
            }
        }
          
        if(iCount == 0)
        {
            printf(" %d \n", first->data);
        }
        first = first->next;
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

    printf("Prime numbers are:\n");

    DisplayPrime(head);

    
    return 0;
}