#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

struct Node * Create (struct Node *Head, int n)
{
    int data;
    struct Node *temp = NULL;
    for (int i=0;i<n;i++)
    {
        if (Head  ==  NULL)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data: %d: ", i+1);
			scanf("%d", &data);

            temp->Data = data;
            Head = temp;
        }
        else
        {
            temp->Next =  (struct Node *)malloc(sizeof(struct Node));
            temp = temp->Next;
            printf("Enter data: %d: ", i+1);
			scanf("%d", &data);
			temp->Data = data;
        }
        
        if (i == n -1)
        {
            temp->Next = Head;
        }
        else
        {
            temp->Next = NULL;
        }
    }
    return Head;
}

struct Node * Print (struct Node *Head,struct Node *temp, int n)
{
    temp = Head;
    for (int i=0; i<n; i++, temp=temp->Next)
    {
        if (temp == Head)
        {
            printf("\n");
        }
        printf("%d\t",temp->Data);
    }
    printf("\n");   
    return(Head);
}

struct Node * Insert (struct Node *Head,struct Node *temp, int pos)
{
    temp = Head;
    int data;
    struct Node *NewNode;
    for (int i=0; i<pos - 1; i++, temp =temp->Next);
    NewNode = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter data to Insert: ");
    scanf("%d", &data);

    NewNode->Data = data;
    NewNode->Next = temp->Next;
    temp->Next = NewNode;
   
   return(Head);
}


void main()
{
    struct Node *Head = NULL;
    struct Node *Temp = NULL;
    int flag = 0, option,n,pos;

    while (flag ==0)
    {
        printf("CLL Menu\nChoose an option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
	        printf("Enter n: ");
	        scanf("%d", &n);
	        Head = Create(Head, n);

	        printf("\n");     
            break;

            case 2:
            printf("Enter number of elements to print: ");
	        scanf("%d", &n);
	        Head = Print(Head,Temp,n);
            break;

            case 3:
            printf("Enter position to insert: ");
            scanf("%d",&pos);

            Head = Insert(Head, Temp,pos);
        }
    }
}