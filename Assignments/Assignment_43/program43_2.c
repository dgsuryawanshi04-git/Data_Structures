#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void DisplayPrime(PNODE Head)
{
    int iCount = 0, iCnt = 0;
    PNODE temp = Head;

    while(temp != NULL)
    {
        iCount = 0;
        for(iCnt = 2; iCnt < (temp->data/2); iCnt++)
        {
            if((temp->data % iCnt) == 0)
            {
                iCount++;
                break;
            }
        }
        if(iCount == 0)
        {
                printf("%d ", temp->data);
        }
        temp = temp->next; 
    }
}

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = no;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|->", Head->data);
        Head = Head->next;
    }
    printf("Null\n");
}

int main()
{

    PNODE First = NULL;

    InsertFirst(&First, 89);
    InsertFirst(&First, 22);
    InsertFirst(&First, 41);
    InsertFirst(&First, 17);
    InsertFirst(&First, 20);
    InsertFirst(&First, 11);

    Display(First);

    printf("Prime numbers are:\n");
    
    DisplayPrime(First);

}