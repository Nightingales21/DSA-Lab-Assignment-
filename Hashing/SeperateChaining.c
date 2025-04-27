#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int Data;
    struct Node *Next;
};

int HashFunction(int data)
{
    int key;
    key = data % 100;
    return key;
}

void Insert(struct Node *Hash_Table[], int dataset[])
{
    int key;
    struct Node *Head;
    struct Node *Temp;
    for (int i=0; i<100; i++)
    {
        Head = (struct Node *)malloc(sizeof(struct Node ));
        Temp = (struct Node *)malloc(sizeof(struct Node ));
        key = HashFunction(dataset[i]);
        if (Hash_Table[key] == NULL)
        {
           Head->Data = dataset[i];
           Head->Next = NULL;
           Hash_Table[key] = Head;
        }
        else
        {
            Head = Hash_Table[key];
            for (; Head-> Next != NULL; Head = Head->Next);
            Temp->Data = dataset[i];
            Temp->Next = NULL;
            Head->Next = Temp;
        }
    }   
}

void Display(struct Node *Hash_Table[])
{
    struct Node *Head;
    for (int i=0; i<100; i++)
    {
        Head = (struct Node *)malloc(sizeof(struct Node));
        if(Hash_Table[i] == NULL)
        {
            printf("-1\n");
        }
        else
        {
            for (Head = Hash_Table[i]; Head->Next != NULL; Head = Head->Next)
            {
                printf("%d\t", Head->Data);
            }
            printf("\n");
        }
    }
}

void main()
{
    struct Node * Hash_Table[100];
    int dataset[100];
    srand(time(NULL));
    for (int i=0; i<100; i++)
    {
        Hash_Table[i] = NULL;
        dataset[i] = i;
        //dataset[i] = rand() % 100 + 1;
    }
    Insert(Hash_Table, dataset);
    Display(Hash_Table);
}