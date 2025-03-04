#include <stdio.h>
#include <stdlib.h>

struct Stack 
{
    int Data;
    struct Stack *Next;
    struct Stack *Prev;
};

struct Stack * push(struct Stack *Top, int i)
{
    struct Stack *Temp;
    int data;
    if (Top == NULL)
    {
        Temp = (struct Stack *)malloc(sizeof(struct Stack));
        printf("Enter data %d:", i+1);
        scanf("%d",&data);
        Temp->Data = data;
        Temp->Next = NULL;
        Temp->Prev = NULL;
        Top = Temp;
    }
    else
    {
        Temp = (struct Stack *)malloc(sizeof(struct Stack));
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

struct Stack * pop(struct Stack *Top)
{
    Top = Top->Next;
    free(Top->Prev);
    Top->Prev = NULL;
    return(Top);
}

void Peek(struct Stack *Top)
{
    printf("the data at Top is: %d", Top->Data);
}

void Print(struct Stack *Top)
{
    struct Stack *Temp = NULL;
    for (Temp = Top; Temp->Next != NULL; Temp=Temp->Next)
    {
        printf("%d\t", Temp->Data);
    }
    printf("%d\t", Temp->Data);
} 

void main()
{
    struct Stack *Top = NULL;
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
