#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Chair 
{
    int Number;
    struct Chair *Next;
};


struct Node * Create(struct Chair *Head, int n)
{
    struct Node *Temp;
    int Data;
    for(int i=1; i<=n; i++)
    {
        if (Head == NULL)
        {
            Temp = (struct Node *)malloc(sizeof(struct Node));
            Temp->Number = i;
            Temp->Next = NULL;
            Head = Temp;
        }
        else
        {
            Temp->Next = (struct Node *)malloc(sizeof(struct Node));
            Temp = Temp->Next;
            Temp->Number = i;
        }
        Temp->Next = Head;
    }
    return(Head);
}

// Function to delete a node at a given position
struct Chair *Delete(struct Chair *Head, int pos) {

    struct Chair *Temp = Head, *Prev = NULL;

    if (pos == 1) 
    {
        while (Temp->Next != Head) 
        {
        Temp = Temp->Next;
        Temp->Next = Head->Next;
        free(Head);
        return Temp->Next;
        }
    }

    int count = 1;
    while (count < pos && Temp->Next != Head) {
        Prev = Temp;
        Temp = Temp->Next;
        count++;
    }

    if (count == pos) {
        Prev->Next = Temp->Next;
        free(Temp);
    }
    
    return Head;
}

// Function to delete first or last node
struct Chair *DeleteBegorEnd(struct Chair *Head) {
    if (Head == NULL) return NULL;

    struct Chair *Temp = Head, *Prev = NULL;

    while (Temp->Next != Head) {
        Prev = Temp;
        Temp = Temp->Next;
    }

    if (Prev == NULL) { // Only one node case
        free(Head);
        return NULL;
    }

    Prev->Next = Head;
    free(Temp);
    
    return Head;
}

// Function to print the list
void Print(struct Chair *Head) {
    if (Head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Chair *Temp = Head;
    do {
        printf("%d\t", Temp->Number);
        Temp = Temp->Next;
    } while (Temp != Head);
    printf("\n");
}

int main() {
    struct Chair *Head = NULL;
    int amount;

    printf("Enter the amount of Chairs: ");
    scanf("%d", &amount); 
    Head = Create(Head, amount);

    srand(time(0));

    while (amount > 1) {
        int randomNumber = (rand() % amount) + 1;
        printf("Removing chair at position: %d\n", randomNumber);

        if (randomNumber == 1 || randomNumber == amount) {
            Head = DeleteBegorEnd(Head);
        } else {
            Head = Delete(Head, randomNumber);
        }

        amount--;
        Print(Head);
    }

    printf("Last remaining chair: %d\n", Head->Number);
    free(Head);

    return 0;
}
