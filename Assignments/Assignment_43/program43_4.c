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

int SecMaximum(PNODE head)
{
    PNODE temp = NULL;
    int imax = 0;
    temp = head;

    while(temp != NULL)
    {
        if(imax < temp->next->data)
        {
            imax = temp->next->data;   
        }
        temp = temp->next->next;
    }
    return imax;
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
    printf("NULL\n");

}
int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first, 240);
    InsertFirst(&first, 320);
    InsertFirst(&first, 230);
    InsertFirst(&first, 110);

    Display(first);

    iRet = SecMaximum(first);
    printf("Maximum : %d\n", iRet);

    return 0;
}