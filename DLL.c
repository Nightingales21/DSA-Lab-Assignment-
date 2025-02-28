#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int Data;
    struct Node *Next;
    struct Node *Previous;
};

struct Node *Create(struct Node *Head, struct Node *Tail, int n) 
{
    struct Node *Temp = NULL;
    int data;

    for (int i = 0; i < n; i++) 
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);

        newNode->Data = data;
        newNode->Next = NULL;
        newNode->Previous = NULL;

        if (Head == NULL) 
        {  
            Head = newNode;
            Tail = newNode;
        } 
        else 
        {
            Tail->Next = newNode;
            newNode->Previous = Tail;
            Tail = newNode;
        }
    }
    return Head;  
}

void Print(struct Node *Head) 
{
    struct Node *Temp = Head;

    printf("Doubly Linked List: ");
    while (Temp != NULL) 
    {
        printf("%d ", Temp->Data);
        Temp = Temp->Next;
    }
    printf("\n");
}

struct Node * InsertBeg(struct Node *Head)
{
    struct Node *Temp = NULL;
    int data;
    Temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &data);
    Temp->Previous = NULL;
    Temp->Data=data;
    Temp->Next = Head;
    Head->Previous = Temp;
    Head = Temp;
    return Head;
}

struct Node *Insert(struct Node *Head, int pos) 
{
    struct Node *NN = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    int data;
    scanf("%d", &data);
    NN->Data = data;
    NN->Next = NULL;
    NN->Previous = NULL;

    for (i = 0; Temp != NULL && i < pos - 1; i++) 
    {
        Temp = Temp->Next;
    }

    NN->Next = Temp->Next;
    NN->Previous = Temp;
    

    Temp->Next = NN;

    return Head;
}


int main() {
    int flag = 0, option, n;
    struct Node *Head = NULL;
    struct Node *Tail = NULL;

    while (flag == 0) {
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

        switch (option) {
            case 1:
                printf("Enter the number of Nodes to Create: ");
                scanf("%d", &n);
                Head = Create(Head, Tail, n);  
                break;

            case 2:
                Print(Head);
                break;

            case 3:
               Head = InsertBeg(Head);
                break;

            case 4:
                
                printf("Enter position: ");
                int pos;
                scanf("%d", &pos);
                Head = Insert(Head, pos);
                break;

            case 9:
                flag = 1;
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Option! Try again.\n");
        }
    }
    return 0;
}
