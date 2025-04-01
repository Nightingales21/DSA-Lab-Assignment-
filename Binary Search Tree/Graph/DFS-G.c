#include <stdio.h>
#include <stdlib.h>
 

int Seen(int *Visited, int Node)
{
    for (int i = 0; i < 10; i++)
    {
        if (Visited[i] == Node)
        {
            return 1;
        }
    }
    return 0;
}

void DFS(int *A, int *Visited, int pos, int Count)
{
    for (int i = 0; i < 10; i++)
    {
        if ((A[pos][i] == 1) && (!Seen(Visited,i)))
        {
            Visited[Count] = i;
            DFS(A,Visited,i,Count);
        }
    }
}

void main()
{
    int A[10][10] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0}
    };
    int Visited[10];
    int Count = 0;
    while (Count < 10)
    {
        Visited[0] = 0;
        DFS(A,Visited,0,Count);
    }
}