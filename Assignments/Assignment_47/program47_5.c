/////////////////////////////////////////////////////////////////////
//
//  Function Name : CountPrime
//  Description :   Return count of prime numbers.
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

int CountPrime(PNODE first)
{
    int iCnt = 0, iCount1 = 0, iCount2 = 0;
    
    while(first != NULL)
    {
        iCount1 = 0;
        for(iCnt = 2; iCnt < (first->data / 2); iCnt++)
        {
            if((first->data % iCnt) == 0)
            {
                iCount1++;
                break;
            }
        }
          
        if(iCount1 == 0)
        {
            iCount2++;
        }
        first = first->next;
    }
    return iCount2;
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

    InserFirst(&head, 121);
    InserFirst(&head, 111);
    InserFirst(&head, 101);
    InserFirst(&head, 51);
    InserFirst(&head, 21);
    InserFirst(&head, 11);
    
    Display(head);

    iRet = CountPrime(head);
    printf("Count of prime numbers : %d\n", iRet);

    
    return 0;
}