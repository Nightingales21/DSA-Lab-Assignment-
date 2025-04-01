#include <stdio.h>
#include <stdlib.h>
 
int Seen(int *Visited, int Vertex)
{
    for (int i = 0; i < 5; i++)
    {
        if (Visited[i] == Vertex)
        {
            return 1;
        }
    }
    return 0;
}

void DFS(int A[5][5], int *Visited, int pos, int *Count)
{
    int i;
    Visited[*Count] = pos;
    (*Count)++;
    printf("%d ", pos);
    for (i = 0; i < 5; i++)
    {
        if ((A[pos][i] == 1) && (!Seen(Visited,i)))
        {
            DFS(A,Visited,i,Count);
        }
    }
}

void main()
{
    int A[5][5] = {
        {0,1,1,0,0},
        {1,0,1,0,0},
        {1,1,0,1,0},
        {0,0,1,0,1},
        {0,0,0,1,0}

    };
    int Visited[5];
    int Count = 0;
    DFS(A,Visited,0,&Count);
}