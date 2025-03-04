#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int Data;
    struct Node *Next;
    struct Node *Prev;
};

struct Node * push(struct Node *Top, int i)
{
    struct Node *Temp;
    int data;
    if (Top == NULL)
    {
        Temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data %d:", i+1);
        scanf("%d",&data);
        Temp->Data = data;
        Temp->Next = NULL;
        Temp->Prev = NULL;
        Top = Temp;
    }
    else
    {
        Temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data); 
        Temp->Data = data;  
        Temp->Next = Top;   
        Top->Prev = Temp;  
        Temp->Prev = NULL;  
        Top = Temp;
    }
    return Top;
}

struct Node * pop(struct Node *Top)
{
    Top = Top->Next;
    free(Top->Prev);
    Top->Prev = NULL;
    return(Top);
}

void Peek(struct Node *Top)
{
    printf("the data at Top is: %d", Top->Data);
}

void Print(struct Node *Top)
{
    struct Node *Temp = NULL;
    for (Temp = Top; Temp->Next != NULL; Temp=Temp->Next)
    {
        printf("%d\t", Temp->Data);
    }
    printf("%d\t", Temp->Data);
} 

void main()
{
    struct Node *Top = NULL;
    int flag = 0, option,j;
    while (flag == 0)
    {
        printf("\nStacks Menu\n");
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Peak\n");
        printf("4: Print Stack(Verification Purposes)\n");
        printf("5:Exit\n");
        printf("Choose Option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the Number of elements to push: ");
                scanf("%d", &j);
                for(int i=0; i<j; i++)
                {
                   Top = push(Top,i);
                }
                break;

            case 2:
                Top = pop(Top);
                break;
            
            case 3:
                Peek(Top);
                break;
            
            case 4:
                Print(Top);
                break;

            case 5:
                flag = 1;
                break;
        };
    }
}