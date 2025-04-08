#include <stdio.h>
#include <stdlib.h>

int Q[15], Visited[5];
int rear = -1, front = 0;

int Seen(int *Visited, int Vertex)
{
    return Visited[Vertex] == 1;
}

void Enqueue(int Q[], int s, int *rear)
{
    Q[++(*rear)] = s;
}

int Dequeue(int Q[], int *front)
{
    return Q[(*front)++];
}

void BFS(int A[5][5], int s)
{
    Enqueue(Q, s, &rear);
    Visited[s] = 1;  

    while (front <= rear)
    {
        int current = Dequeue(Q, &front);
        printf("Visited: %d\n", current);  

        for (int i = 0; i < 5; i++)
        {
            if (A[current][i] && !Seen(Visited, i))  
            {
                Enqueue(Q, i, &rear);  
                Visited[i] = 1;  
            }
        }
    }
}

void main()
{
    int A[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    BFS(A, 4); 
}
