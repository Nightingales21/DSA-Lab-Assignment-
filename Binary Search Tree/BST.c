#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int Data;
    struct Node *Left;
    struct Node *Right;
};

struct Node * Create(struct Node *Root, int data)
{
    struct Node *Temp = NULL;
    Temp = (struct Node *)malloc(sizeof(struct Node));
    if (Root == NULL)
    {
        Temp->Data = data;
        Temp->Left = NULL;
        Temp->Right = NULL;
        Root = Temp;
    }
    else
    {
        if (Root->Data > data)
        {
            Root->Left = Create(Root->Left,data);
        }
        else
        {
            Root->Right = Create(Root->Right,data);
        }
    }
    return(Root);
}

void PreOrder(struct Node *Root)
{
    printf("%d\t", Root->Data);
    if (Root->Left != NULL)
    {
        PreOrder(Root->Left);
    }
    if (Root->Right != NULL)
    {
        PreOrder(Root->Right);
    }
}

void InOrder(struct Node *Root)
{
    if (Root->Left != NULL)
    {
        InOrder(Root->Left);
    }
    printf("%d\t", Root->Data);
    if (Root->Right != NULL)
    {
        InOrder(Root->Right);
    }
}

void PostOrder(struct Node *Root)
{
    if (Root->Left != NULL)
    {
        PostOrder(Root->Left);
    }
    if (Root->Right != NULL)
    {
        PostOrder(Root->Right);
    } 
    printf("%d\t", Root->Data);
}

void main()
{
    struct Node *Root = NULL;
    int flag = 0, option,n, data;
    while (flag == 0)
    {
        printf("\nBinary Search Tree Menu!\n");
        printf("1: Create BST\n");
        printf("2: Print Pre Order\n");
        printf("3: Print In Order\n");
        printf("4: Print Post Order\n");
        printf("Choose Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            printf("Number of Nodes: ");
            scanf("%d", &n);
            for (int i=0; i<n; i++ )
            {
                printf("Enter Data for Node %d: ", i+1);
                scanf("%d", &data);
                Root = Create(Root, data);
            }
            break;

            case 2:
            PreOrder(Root);
            break;

            case 3:
            InOrder(Root);
            break;

            case 4:
            PostOrder(Root);
            break;

        }

    }
}