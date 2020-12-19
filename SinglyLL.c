#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	
};
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));     //Allocate Memory to new node
	newn->data = no;                        //Initialize data
	newn->next = NULL;                      //Initialize pointer
	
	if(*Head == NULL)                       //If Linked List is empty
	{
		*Head = newn;
	}
	
	else                                    //Atleast one node present in a LL
	{
		newn->next = *Head;
		*Head = newn;
	}
	
}

void InserLast(PPNODE Head,int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	
	if(*Head = NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}
	
void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head != NULL)
	{
		*Head = (*Head)->next;
		free(temp);
	}
	
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}	

void InsertAtPos(PPNODE Head,int no,int pos)
{
	int size = 0,i = 0;
	PNODE temp = *Head;
	PNODE newn = NULL;
	
	size = Count(*Head);
	
	if((pos < 1) || (pos > size + 1))
	{
		return;
	}
	else if(pos == 1)
	{
		InsertFirst(Head,no);
	}
	else if(pos == size+1)
	{
		InserLast(Head,no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = no;
		
		for(i = 0; i<pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		
	}
}
void DeleteAtPos(PPNODE Head, int pos)
{
    int size = 0,i = 0;
    size = Count(*Head);
    PNODE temp, temp2;
    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        temp = *Head;
        for(i = 0; i< pos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}
		
void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d\t",Head->data);
		Head = Head->next;
		
	}
}

int Count(PNODE Head)
{
	int iCnt = 0;
	
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}


int main()
{
	printf("Singly Linear Linked List\n");
	
	PNODE First = NULL;  //Address of first node
	int no = 0;
	int iRet = 0;
	int pos = 0;
	
	printf("\nEnter First Element\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	printf("Enter Second Element\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	printf("Enter Third Element\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	printf("Elements in linked list are\n");
	Display(First);
	
	
	printf("\nEnter Fourth Element\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	printf("Enter Fifth Element\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	Display(First);
	
	DeleteFirst(&First);
	printf("\n Linked list after deleting first element\n");
	
	Display(First);
	
	DeleteLast(&First);
	printf("\n Linked list after deleting last element\n");
	
	Display(First);
	
	printf("\n Enter element which is to be added at give position\n");
	scanf("%d",&no);
	
	printf("Enter position\n");
	scanf("%d",&pos);
	
	InsertAtPos(&First,no,pos);
	
	Display(First);
	
	printf("\n Enter position of element which is to be deleted from linked list\n");
	scanf("%d",&pos);
	
	DeleteAtPos(&First,pos);
	
	Display(First);
	
	iRet = Count(First);
	
	printf("\nTotal number of elements in linked list are %d",iRet);

	return 0;
}

	
	
	