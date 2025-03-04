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

struct Node * InsertBegorEnd (struct Node *Head, struct Node *temp)
{
    struct Node *nn;
    int data;
    for(temp = Head;temp->Next != Head; temp = temp->Next);
    nn = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter data: ");
	scanf("%d", &data);
    nn->Data = data;
    nn->Next = Head;
    temp->Next = nn;
    Head = nn;
    return(Head);
}

struct Node * Delete (struct Node *Head, struct Node *temp, int pos)
{
    temp = Head;
    struct Node *tnext;
    tnext = temp -> Next;
    for(int i=1; i +1 != pos; i++,temp = temp->Next, tnext = tnext->Next);
    temp->Next = tnext->Next;
    return(Head);
}

struct Node * DeleteBeg (struct Node *Head,struct Node *temp)
{
   
    for(temp = Head; temp->Next != Head; temp = temp->Next);
    Head = Head->Next;
    temp->Next = Head;
    return(Head);
}

struct Node * DeleteEnd(struct Node *Head,struct Node *temp)
{
    struct Node *tnext = NULL;
    for(temp = Head, tnext = temp->Next; tnext->Next != Head; temp = temp->Next, tnext = tnext->Next);
    temp->Next = Head;
    free(tnext);
    return(Head);
}

void main()
{
    struct Node *Head = NULL;
    struct Node *Temp = NULL;
    int flag = 0, option,n,pos,key;

    while (flag ==0)
    {
        printf("CLL Menu\n1:Create\n2:Display\n3:Insert\n4:Insert at Beginning or End\n5:Delete\n6:Delete at Beginning\n7:Delete at End\nChoose an option: ");
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
            break;

            case 4:
            Head = InsertBegorEnd(Head, Temp);
            break;

            case 5:
            printf("Enter position to Delete: ");
            scanf("%d",&pos);

            Head = Delete(Head,Temp,pos);
            break;

            case 6:
            Head = DeleteBeg(Head, Temp);
            break;

            case 7:
            Head = DeleteEnd(Head, Temp);
            break;

            default:
            flag = 1;

        }
    }
}

