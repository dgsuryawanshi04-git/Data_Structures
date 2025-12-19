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

void SumDigit(PNODE head)
{
    PNODE temp = NULL;
    int iDigit = 0, iSum = 0, num = 0;
    temp = head;

    while(temp != NULL)
    {
        num = temp->data;
        iSum = 0;

        while(num != 0 )
        {
            iDigit = num % 10;
            iSum = iSum + iDigit;
            num = num / 10;    
        }
        printf(" %d ", iSum);
        temp = temp->next;
    }    
}
void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

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

void Display(PNODE head)
{
    while(head != NULL)
    {
        printf("| %d |->", head->data);
        head = head->next;
    }
    printf(" NULL\n ");
}
int main()
{
    PNODE first = NULL;

    InsertFirst(&first, 640);
    InsertFirst(&first, 240);
    InsertFirst(&first, 20);
    InsertFirst(&first, 230);
    InsertFirst(&first, 110);

    Display(first);

    SumDigit(first);

    return 0;
}