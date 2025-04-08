#include <stdio.h>
#include <stdlib.h>

int Q[15], Visited[9];
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

void BFS(int A[9][9], int s)
{
    Enqueue(Q, s, &rear);
    Visited[s] = 1;  

    while (front <= rear)
    {
        int current = Dequeue(Q, &front);
        printf("Visited: %d\n", current);  

        for (int i = 0; i < 9; i++)
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
    int A[9][9] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0},  // Node 0
        {1, 0, 1, 0, 1, 0, 0, 0, 0},  // Node 1
        {0, 1, 0, 0, 0, 0, 0, 0, 0},  // Node 2
        {1, 0, 0, 0, 1, 0, 1, 0, 0},  // Node 3
        {0, 1, 0, 1, 0, 1, 0, 0, 0},  // Node 4
        {0, 0, 0, 0, 1, 0, 0, 1, 0},  // Node 5
        {0, 0, 0, 1, 0, 0, 0, 1, 0},  // Node 6
        {0, 0, 0, 0, 0, 1, 1, 0, 1},  // Node 7
        {0, 0, 0, 0, 0, 0, 0, 1, 0}   // Node 8
      };
      

    BFS(A, 0); 
}
