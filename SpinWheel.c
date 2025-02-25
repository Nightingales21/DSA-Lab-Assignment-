#include <stdio.h>
#include <stdlib.h>


struct Chair
{
    int Number;
    struct Chair *Next;
}; 

struct Chair * add(int amount, struct Chair *Head)
{
    struct Chair *Temp, *NN;
    for (int i = 1; i <= amount; i++)
    {
        NN = (struct Chair *)malloc(sizeof(struct Chair));

        if (NN == NULL)
        {
            printf("Memory allocation failed!\n");
            return Head;
        }

        NN->Number = i;
        NN->Next = NULL;

        if (Head == NULL)
        {
            Head = NN;
            Temp = NN;
        }
        else
        {
            Temp->Next = NN;
            Temp = NN;
        }
    }

    if (Temp != NULL)
    {
        Temp->Next = Head;
    }

    return Head;
}

int length(struct Chair *Head)
{
    if (Head == NULL)
        return 0;

    int count = 1;
    struct Chair *Temp = Head;
    while (Temp->Next != Head)
    {
        count++;
        Temp = Temp->Next;
    }
    return count;
}

void display(struct Chair *Head)
{
    if (Head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Chair *Temp = Head;
    do
    {
        printf("Chair Number: %d\n", Temp->Number);
        Temp = Temp->Next;
    } while (Temp != Head);
}

void main()
{
    struct Chair *Head = NULL;
    int amount;

    printf("Enter the amount of Chairs: ");
    scanf("%d", &amount); 

    Head = add(amount, Head);

    printf("Circular Linked List of Chairs:\n");
    display(Head);

    int randomNumber = (rand() % n) + 1;
    

    
}
