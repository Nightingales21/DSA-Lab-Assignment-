#include <stdio.h>
#include <stdlib.h>

struct Chair
{
    int Number;
    struct Chair *Next;
}

struct Chair * add(amount, struct Chair *Head, struct Chair Temp)
{
    struct Chair *NN
    for(int i=1;i<=amount; i++)
    {
        if(Head == NULL)
        {
            NN = (struct Chair *)malloc(sizeof(struct Chair *));
            Temp = NN;
            Head = NN; 
            Head->Number = 1;
        }
        else
        {
            Temp->Next = (struct Chair *)malloc(sizeof(struct Chair *));
            Temp = Temp->Next;
            Temp->Data = i;
        }

        if (i=n)
        {
            Temp->Next= Head;
        }
        else
        {
            Temp->Next = NULL;
        }
    }
    return(Head;)
}

int length(struct Chair *Head, struct Chair *Temp)
{
    Temp = Head;
    for (int i=1;Temp->Next!=NULL;Temp =Temp->Next, i++ )
}

void main()
{
    struct Chair *Head = NULL;
    struct Chair *Temp = NULL;
    int amount;

    printf("Enter the amount of Chairs: ");
    scanf("%d, &amount");
    add(amount, Head);
}