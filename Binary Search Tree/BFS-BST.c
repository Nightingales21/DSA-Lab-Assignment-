#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Left;
    struct Node *Right;
};

// Simple queue implementation
#define MAX_SIZE 50
int Queue[MAX_SIZE];
int front = -1, rear = -1;

void Enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0; // First element
    rear++;
    Queue[rear] = data;
    printf("Enqueued %d\n", data);
}

int Dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = Queue[front];
    front++;
    return data;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

struct Node *Create(struct Node *Root, int data) {
    struct Node *Temp = (struct Node *)malloc(sizeof(struct Node));
    Temp->Data = data;
    Temp->Left = NULL;
    Temp->Right = NULL;

    if (Root == NULL) {
        return Temp;
    }
    if (data < Root->Data) {
        Root->Left = Create(Root->Left, data);
    } else {
        Root->Right = Create(Root->Right, data);
    }
    return Root;
}

void LevelOrderTraversal(struct Node *Root) {
    if (Root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    Enqueue(Root->Data);
    struct Node *currentQueue[MAX_SIZE]; // Queue for node pointers
    int nodeFront = -1, nodeRear = -1;
    currentQueue[++nodeRear] = Root;

    while (!isEmpty()) {
        int data = Dequeue(); // Dequeue the data
        printf("%d ", data);

        // Get the corresponding node
        struct Node *current = currentQueue[++nodeFront];

        // Enqueue left child
        if (current->Left != NULL) {
            Enqueue(current->Left->Data);
            currentQueue[++nodeRear] = current->Left;
        }

        // Enqueue right child
        if (current->Right != NULL) {
            Enqueue(current->Right->Data);
            currentQueue[++nodeRear] = current->Right;
        }
    }
    printf("\n");
}

void main() {
    struct Node *Root = NULL;
    int option, n, data;

    while (1) {
        printf("\nBinary Search Tree Menu!\n");
        printf("1: Create BST\n");
        printf("2: BFS (Level Order Traversal)\n");
        printf("3: Exit\n");
        printf("Choose option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Number of Nodes: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter Data for Node %d: ", i + 1);
                    scanf("%d", &data);
                    Root = Create(Root, data);
                }
                break;

            case 2:
                printf("Level Order Traversal: ");
                LevelOrderTraversal(Root);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}