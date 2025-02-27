#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Chair 
{
    int Number;
    struct Chair *Next;
};


struct Chair * Create(struct Chair *Head, int n)
{
    struct Chair *Temp;
    int Data;
    for(int i=1; i<=n; i++)
    {
        if (Head == NULL)
        {
            Temp = (struct Chair *)malloc(sizeof(struct Chair));
            Temp->Number = i;
            Temp->Next = NULL;
            Head = Temp;
        }
        else
        {
            Temp->Next = (struct Chair *)malloc(sizeof(struct Chair));
            Temp = Temp->Next;
            Temp->Number = i;
        }
        Temp->Next = Head;
    }
    return(Head);
}

struct Chair * Delete (struct Chair *Head, struct Chair *temp, int pos)
{
    temp = Head;
    struct Chair *tnext;
    tnext = temp -> Next;
    for(int i=1; i +1 != pos; i++,temp = temp->Next, tnext = tnext->Next);
    temp->Next = tnext->Next;
    return(Head);
}

struct Chair * DeleteBeg (struct Chair *Head,struct Chair *temp)
{
   
    for(temp = Head; temp->Next != Head; temp = temp->Next);
    Head = Head->Next;
    temp->Next = Head;
    return(Head);
}

struct Chair * DeleteEnd(struct Chair *Head,struct Chair *temp)
{
    struct Chair *tnext = NULL;
    for(temp = Head, tnext = temp->Next; tnext->Next != Head; temp = temp->Next, tnext = tnext->Next);
    temp->Next = Head;
    free(tnext);
    return(Head);
}

struct Chair * Print (struct Chair *Head,struct Chair *temp, int n)
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

int main() {
    struct Chair *Head = NULL;
    struct Chair *Temp = NULL;
    int amount;

    printf("Enter the amount of Chairs: ");
    scanf("%d", &amount); 
    Head = Create(Head, amount);

    while (amount > 1)
    {
        srand(time(0));
        int randomNumber = (rand() % (amount - 0 + 1)) + 0;
        if (randomNumber == 0)
        {
            DeleteBeg(Head, Temp);
        }
        else if (randomNumber == amount)
        {
            DeleteEnd(Head, Temp);
        }
        else
        {
            Delete(Head, Temp, randomNumber);
        }
        amount--;
        Print(Head, Temp, amount);
    }
    
}
