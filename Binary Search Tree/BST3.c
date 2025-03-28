#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int Data;
    struct Node *Left;
    struct Node *Right;
};


struct Node* Create(struct Node *Root, int data)
{
    if (Root == NULL)
    {
        struct Node* Temp = (struct Node*)malloc(sizeof(struct Node));
        Temp->Data = data;
        Temp->Left = NULL;
        Temp->Right = NULL;
        return Temp;
    }

    if (data < Root->Data)
        Root->Left = Create(Root->Left, data);
    else
        Root->Right = Create(Root->Right, data);

    return Root;
}


struct Node* Search(struct Node* Root, int key)
{
    if (Root == NULL || Root->Data == key)
        return Root;

    if (key < Root->Data)
        return Search(Root->Left, key);
    else
        return Search(Root->Right, key);
}


int Height(struct Node* node)
{
    if (node == NULL)
        return 0;
    
    int leftHeight = Height(node->Left);
    int rightHeight = Height(node->Right);

    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}


int BalanceFactor(struct Node* node)
{
    if (node == NULL)
        return 0;

    return Height(node->Left) - Height(node->Right);
}


struct Node* InOrderPredecessor(struct Node* node)
{
    if (node == NULL || node->Left == NULL)
        return NULL;
    
    struct Node* pred = node->Left;
    while (pred->Right != NULL)
        pred = pred->Right;
    
    return pred;
}


struct Node* InOrderSuccessor(struct Node* node)
{
    if (node == NULL || node->Right == NULL)
        return NULL;

    struct Node* succ = node->Right;
    while (succ->Left != NULL)
        succ = succ->Left;
    
    return succ;
}


int main()
{
    struct Node *Root = NULL;
    int n, data, key;

    
    printf("Number of Nodes in BST: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Data for Node %d: ", i + 1);
        scanf("%d", &data);
        Root = Create(Root, data);
    }

    
    printf("\nEnter the node value to search: ");
    scanf("%d", &key);

    struct Node* found = Search(Root, key);
    if (found)
    {
        printf("Node %d found in BST.\n", key);

        
        int nodeHeight = Height(found) - 1;  
        printf("Height of Node %d: %d\n", key, nodeHeight);

        
        int bf = BalanceFactor(found);
        printf("Balance Factor: %d\n", bf);

        
        struct Node* pred = InOrderPredecessor(found);
        if (pred)
            printf("In-Order Predecessor: %d\n", pred->Data);
        else
            printf("No In-Order Predecessor (Node is the first element in inorder).\n");

        
        struct Node* succ = InOrderSuccessor(found);
        if (succ)
            printf("In-Order Successor: %d\n", succ->Data);
        else
            printf("No In-Order Successor (Node is the last element in inorder).\n");
    }
    else
    {
        printf("Node %d not found in BST.\n", key);
    }

    return 0;
}
