#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Previous;
};

struct Node * Create(struct Node *Head, struct Node *Temp, int n)
{
    int data;
    for (int i=0; i<n;i++)
    {
        if (Head == NULL)
        {
            Temp = (struct Node *)malloc(sizeof(struct Node));
            Temp->Previous = NULL;

            printf("Enter data: %d: ", i+1);
			scanf("%d", &data);
			Temp->Data = data;
            
            Head = Temp;
        }
        else
        {
            Temp->Next = (struct Node *)malloc(sizeof(struct Node));
            Temp->Next->Previous = Temp;
            Temp=Temp->Next;

            printf("Enter data: %d: ", i+1);
			scanf("%d", &data);
			Temp->Data = data;
            
        }
        Temp->Next = NULL;
    }
    return(Head);
}

void Print(struct Node *Head, struct Node *Temp)
{
    for (Temp = Head; Temp->Next!=NULL; Temp = Temp-> Next)
    {
        printf("%d\t",Temp->Data);
    }
}

void main()
{
    int flag = 0, option, n;
    struct Node *Head = NULL;
    struct Node *Temp = NULL;

    while (flag == 0)
    {
        printf("DLL Menu: \n");
        printf("1: Create\n");
        printf("2: Print\n");
        printf("3: Insert Begininng\n");
        printf("4: Insert Middle\n");
        printf("5: Insert End\n");
        printf("6: Delete Begininng\n");
        printf("7: Delete Middle\n");
        printf("8: Delete End\n");
        printf("9: Exit\n");
        printf("Choose Option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            printf("Enter the number of Nodes to Cretae: ");
            scanf("%d",&n);
            Create(Head, Temp, n);
            break;

            case 2:
            Print(Head, Temp);
            break;

        }
    }
}