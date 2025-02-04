#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int Data;
	struct Node *Next;	
};

struct Node * create(struct Node *Head, struct Node *temp, int n)
{
	int data;
	for (int i=0; i<n; i++)
	{
		if (Head == NULL)
		{

			temp=(struct Node *)malloc(sizeof(struct Node));
			printf("Enter data: %d: ", i+1);
			scanf("%d", &data);

			temp->Data = data;
			Head = temp;
		}
		else
		{
			temp->Next = (struct Node *)malloc(sizeof(struct Node));
			temp = temp->Next;
			printf("Enter data: %d: ", i+1);
			scanf("%d", &data);
			temp->Data = data;
		}
		temp->Next = NULL;
	}
	return (Head);
}

void print(struct Node *Head)
{
	printf("The following are the data:\n");
	while (Head != NULL)
	{
		printf("%d\t", Head->Data);
		Head = Head->Next;
	}
}

struct Node * Insert(struct Node *Head, struct Node *temp, int pos, int data)
{
	struct Node *nn;
	int c = 1;
	for (temp=Head;c<pos;temp = temp->Next)
	{
		c++;
	}
	nn = (struct Node *)malloc(sizeof(struct Node *));
	nn->Data = data;
	nn->Next = temp->Next;
	temp->Next = nn;

}

struct Node * InsertEnd(struct Node *Head, struct Node *temp, int data)
{
	struct Node *nn;
	nn = (struct Node *) malloc(sizeof(struct Node ));
	nn->Data = data;
	nn->Next = NULL;
	for(temp=Head;temp->Next != NULL; temp = temp->Next);
	temp->Next = nn;
	return(Head);
}

struct Node * InsertBeg(struct Node *Head, int data)
{
	struct Node *nn;
	nn = (struct Node *) malloc(sizeof(struct Node ));
	nn->Data = data;
	nn->Next = Head;
	Head = nn;
	return (Head);
}
void main()
{
	struct Node *Head = NULL;
	struct Node *temp;
	int n, data, pos;

	printf("Enter n: ");
	scanf("%d", &n);
	Head = create(Head, temp, n);

	print(Head);
	printf("\n");

	printf("Enter the position and data to insert: ");
	scanf("%d", &data);
	scanf("%d",&pos);

	printf("\n"); 
	Insert(Head,temp, pos, 	data);
	print(Head);

	printf("\n");
	InsertEnd(Head,temp, data);
	print(Head);	

	printf("\n");
	Head = InsertBeg(Head, data);
	print(Head);
printf("Hello");

}	

