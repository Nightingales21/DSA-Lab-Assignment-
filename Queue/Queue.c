#include <stdio.h>

void Enqueue(int *Q, int Data)
{
    int i;
    for (i = 0; i < 10 && Q[i] != -1; i++);
    if (i < 10)
    {
        Q[i] = Data;
        printf("Enqueued %d\n", Data);
    }
}

void Dequeue(int *Q)
{
    int i;
    printf("Dequeued %d\n", Q[0]);
    for (i = 0; i < 9; i++)
    {
        Q[i] = Q[i + 1];
    }
    Q[9] = -1;
}

int isFull(int *Q)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (Q[i] == -1)
        {
            return 0;
        }
    }
    return 1;
}

int isEmpty(int *Q)
{
    if (Q[0] == -1)
    {
        return 1;
    }
    return 0;
}

void PrintQueue(int *Q)
{
    int i;
    for (i = 0; i < 10 && Q[i] != -1; i++)
    {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main()
{
    int Q[10];
    int flag = 0, option, Data;
    int i;

    for (i = 0; i < 10; i++)
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
            Enqueue(Q, Data);
            break;

            case 2:
            Dequeue(Q);
            break;

            case 3:
            if (isFull(Q))
            {
                printf("Queue is Full\n");
            }
            else
            {
                printf("Queue is Not Full\n");
            }
            break;

            case 4:
            if (isEmpty(Q))
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is Not Empty\n");
            }
            break;

            case 5:
            PrintQueue(Q);
            break;

            case 6:
            flag = 1;
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
