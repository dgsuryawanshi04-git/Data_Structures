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

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = no;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

int AdditionEven(PNODE head)
{
    int iCnt =0, iSum = 0;
    PNODE temp = 0;
    temp = head;
    while(temp != NULL)
    {
        if((temp->data % 2) == 0)
        {
            iSum = iSum + temp->data;
        }
        temp = temp->next;
    }
    return iSum;
}

void Display(PNODE head)
{
    while(head != NULL)
    {
        printf("| %d |->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    int iRet = 0;
    PNODE first = NULL;

    InsertFirst(&first, 41);
    InsertFirst(&first, 32);
    InsertFirst(&first, 20);
    InsertFirst(&first, 11);

    Display(first);

    iRet = AdditionEven(first);
    printf("Addition of even elements : %d\n", iRet);

    return 0;
}