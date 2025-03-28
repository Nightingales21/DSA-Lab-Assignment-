#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};


int getHeight(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  
    return newNode;
}


int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}


struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    
    x->right = y;
    y->left = T2;

    
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));

    return x;
}


struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    
    y->left = x;
    x->right = T2;

    
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));

    return y;
}


struct Node* insertAVL(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertAVL(root->left, data);
    else if (data > root->data)
        root->right = insertAVL(root->right, data);
    else
        return root;  

    
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

    
    int balance = getBalanceFactor(root);

    
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; 
}


void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct Node* root = NULL;

    int choice, num1, num2, num3;

    printf("Choose a test case (1-5):\n");
    printf("1. LL Rotation\n2. RR Rotation\n3. LR Rotation\n4. RL Rotation\n5. No Rotation\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            num1 = 30, num2 = 20, num3 = 10;
            break;
        case 2: 
            num1 = 10, num2 = 20, num3 = 30;
            break;
        case 3: 
            num1 = 30, num2 = 10, num3 = 20;
            break;
        case 4: 
            num1 = 10, num2 = 30, num3 = 20;
            break;
        case 5: 
            num1 = 10, num2 = 20, num3 = 15;
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nInserting: %d %d %d\n", num1, num2, num3);

    root = insertAVL(root, num1);
    root = insertAVL(root, num2);
    root = insertAVL(root, num3);

    printf("Balanced AVL Tree (Inorder Traversal): ");
    inorder(root);
    printf("\n");

    return 0;
}
