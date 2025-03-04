#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create(struct node *head, struct node *tail, int n)
{
    struct node *temp;
    int i;
    int value;

    printf("\n");

    for (i = 0; i < n; i++) 
    {
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &value);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) 
        {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void print_from_head(struct node *head)
{
    struct node *temp;

    for (temp = head; temp != NULL; temp = temp->next) 
    {
        printf("%d\n", temp->data);
    }
}

void print_from_tail(struct node *tail)
{
    struct node *temp;

    for (temp = tail; temp != NULL; temp = temp->prev) 
    {
        printf("%d\n", temp->data);
    }
}

struct node *insert_front(struct node *head, int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = value;
    newNode->next = head;

    if (head != NULL) 
    {
        head->prev = newNode;
    }

    head = newNode;

    return head;
}

struct node *insert_middle(struct node *head, int position, int value)
{
    int count;
    struct node *temp;
    struct node *newNode;

    count = 1;
    temp = head;

    while (count < position - 1 && temp->next != NULL) 
    {
        temp = temp->next;
        count += 1;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) 
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}

struct node *insert_end(struct node *tail, int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = tail;
    newNode->data = value;
    newNode->next = NULL;

    if (tail != NULL) 
    {
        tail->next = newNode;
    }

    tail = newNode;

    return tail;
}

struct node *delete_front(struct node *head)
{
    if (head == NULL) 
    {
        return NULL;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL) 
    {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

struct node *delete_middle(struct node *head, int value)
{
    struct node *temp;

    for (temp = head; temp != NULL; temp = temp->next) 
    {
        if (temp->data == value) 
        {
            if (temp->prev != NULL) 
            {
                temp->prev->next = temp->next;
            } 
            else 
            {
                head = temp->next;
            }

            if (temp->next != NULL) 
            {
                temp->next->prev = temp->prev;
            }

            free(temp);
            break;
        }
    }

    return head;
}

struct node *delete_end(struct node *tail)
{
    if (tail == NULL) 
    {
        return NULL;
    }

    struct node *temp = tail;
    tail = tail->prev;

    if (tail != NULL) 
    {
        tail->next = NULL;
    }

    free(temp);
    return tail;
}

int main()
{
    int option;
    int value;
    int n;
    int position;

    struct node *head;
    struct node *tail;

    head = NULL;
    tail = NULL;

    int running;
    running = 1;

    while (running != 0) 
    {
        printf("\n\n1. Enter list\n");
        printf("2. Print list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert in middle\n");
        printf("5. Insert at end\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete in middle\n");
        printf("8. Delete from end\n");
        printf("9. Exit\n");
        printf("\nEnter choice: ");

        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);
                head = create(head, tail, n);
                break;

            case 2:
                printf("\nThrough head: \n");
                print_from_head(head);
                printf("\nThrough tail: \n");
                print_from_tail(tail);
                break;

            case 3:
                printf("Enter new node value: ");
                scanf("%d", &value);
                head = insert_front(head, value);
                break;

            case 4:
                printf("Enter new node value: ");
                scanf("%d", &value);
                printf("Enter new node position: ");
                scanf("%d", &position);
                head = insert_middle(head, position, value);
                break;

            case 5:
                printf("Enter new node value: ");
                scanf("%d", &value);
                tail = insert_end(tail, value);
                break;

            case 6:
                head = delete_front(head);
                break;

            case 7:
                printf("Enter node data: ");
                scanf("%d", &value);
                head = delete_middle(head, value);
                break;

            case 8:
                tail = delete_end(tail);
                break;

            case 9:
                running = 0;
                break;
        }
    }

    return 0;
}
