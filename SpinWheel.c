#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int Number;
    struct Node *Next;
};

struct Node * Create(struct Node *Head, int n)
{
    struct Node *Temp;
    int Data;
    for(int i=1; i<=n; i++)
    {
        if (Head == NULL)
        {
            Temp = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter Number %d: ", i);
            scanf("\n%d",&Data);
            Temp->Number = Data;
            Temp->Next = NULL;
            Head = Temp;
        }
        else
        {
            Temp->Next = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter Number %d: ", i);
            scanf("\n%d",&Data);
            Temp = Temp->Next;
            Temp->Number = Data;
        }
        Temp->Next = Head;
    }
    return(Head);
}

void Display(struct Node *Head,struct Node *Temp, int n)
{
    Temp=Head;
    for (int i=0; i<n; Temp=Temp->Next, i++);
    printf("The data after %d iterations is: %d", n, Temp->Number);

}

void main()
{
    struct Node *Head = NULL;
    struct Node *Temp = NULL;
    int n;

    printf("Enter the Number of Nodes to create: ");
    scanf("%d", &n);
    Head = Create(Head, n);

    srand(time(0));
    int randomNumber = (rand() % (100 - 0 + 1)) + 0;
    Display(Head,Temp,randomNumber);

}