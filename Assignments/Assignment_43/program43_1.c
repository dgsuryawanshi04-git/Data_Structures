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

void DisplayPerfect(PNODE Head)
{
   int iCnt = 0, iSum = 0;
   PNODE temp = Head;

   while(temp != NULL)
   {
        iSum = 0;
        for(iCnt = 1; iCnt <= (temp->data / 2); iCnt++)
        {
            if((temp->data % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(temp->data == iSum)
        {
            printf("%d ",temp->data);
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
        (*Head) = newn;
    }
    else
    {
        newn->next = (*Head);
        (*Head) = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int main() 
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 6);
    InsertFirst(&First, 240);
    InsertFirst(&First, 28);
    InsertFirst(&First, 230);
    InsertFirst(&First, 61);

    Display(First);

    printf("Perfect numbers are: ");
    DisplayPerfect(First);
    
    return 0;

    
}