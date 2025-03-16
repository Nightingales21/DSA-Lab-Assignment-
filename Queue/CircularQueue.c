#include <stdio.h>

#define SIZE 10

void Enqueue(int *Q, int *front, int *rear, int Data)
{
    int nextRear = (*rear + 1) % SIZE;

    if (nextRear == *front && Q[*front] != -1)
    {
        printf("Queue is Full\n");
        return;
    }

    *rear = nextRear;
    Q[*rear] = Data;

    printf("Enqueued %d\n", Data);
}

void Dequeue(int *Q, int *front, int *rear)
{
    if (Q[*front] == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Dequeued %d\n", Q[*front]);
    Q[*front] = -1;

    if (*front == *rear)
    {
        *front = *rear = 0;
    }
    else
    {
        *front = (*front + 1) % SIZE;
    }
}

int isFull(int *Q, int front, int rear)
{
    int nextRear = (rear + 1) % SIZE;

    if (nextRear == front && Q[front] != -1)
    {
        return 1;
    }

    return 0;
}

int isEmpty(int *Q, int front, int rear)
{
    if (front == rear && Q[front] == -1)
    {
        return 1;
    }

    return 0;
}

void PrintQueue(int *Q, int front, int rear)
{
    if (isEmpty(Q, front, rear))
    {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;

    while (1)
    {
        if (Q[i] != -1)
        {
            printf("%d ", Q[i]);
        }

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int Q[SIZE];
    int flag = 0, option, Data;
    int i;
    int front = 0, rear = 0;

    for (i = 0; i < SIZE; i++)
    {
        Q[i] = -1;
    }

    while (flag == 0)
    {
        printf("\nQueues Menu:\n");
        printf("1: Enqueue\n");
        printf("2: Dequeue\n");
        printf("3: Queue Full\n");
        printf("4: Queue Empty\n");
        printf("5: Print Queue\n");
        printf("6: Exit\n");
        printf("Choose Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            printf("Enter Data to Enqueue: ");
            scanf("%d", &Data);
            Enqueue(Q, &front, &rear, Data);
            break;

            case 2:
            Dequeue(Q, &front, &rear);
            break;

            case 3:
            if (isFull(Q, front, rear))
            {
                printf("Queue is Full\n");
            }
            else
            {
                printf("Queue is Not Full\n");
            }
            break;

            case 4:
            if (isEmpty(Q, front, rear))
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is Not Empty\n");
            }
            break;

            case 5:
            PrintQueue(Q, front, rear);
            break;

            case 6:
            flag = 1;
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
