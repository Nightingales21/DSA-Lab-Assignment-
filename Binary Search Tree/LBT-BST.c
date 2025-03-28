#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int Data;
    struct Node *Left;
    struct Node *Right;
};


struct Node *Create(struct Node *Root, int data)
{
    struct Node *Temp = (struct Node *)malloc(sizeof(struct Node));
    Temp->Data = data;
    Temp->Left = NULL;
    Temp->Right = NULL;

    if (Root == NULL)
    {
        return Temp;
    }
    
    if (Root->Data > data)
        Root->Left = Create(Root->Left, data);
    else
        Root->Right = Create(Root->Right, data);

    return Root;
}


void Enqueue(struct Node* Q[], struct Node* node, int *rear)
{
    Q[(*rear)++] = node;
}

struct Node* Dequeue(struct Node* Q[], int *front)
{
    return Q[(*front)++];
}

int isEmpty(int front, int rear)
{
    return front == rear;
}


void LBT(struct Node *Root)
{
    if (Root == NULL) return;

    struct Node* Q[50]; 
    int front = 0, rear = 0; 

    
    Enqueue(Q, Root, &rear);

    while (!isEmpty(front, rear))
    {
        struct Node* current = Dequeue(Q, &front);
        printf("%d ", current->Data);

        if (current->Left)
            Enqueue(Q, current->Left, &rear);
        
        if (current->Right)
            Enqueue(Q, current->Right, &rear);
    }
}


int main()
{
    struct Node *Root = NULL;
    int n, data;

    printf("Number of Nodes in BST: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Data for Node %d: ", i + 1);
        scanf("%d", &data);
        Root = Create(Root, data);
    }

    printf("\nLevel-Order Traversal: ");
    LBT(Root);
    printf("\n");

    return 0;
}
