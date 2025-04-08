#include <stdio.h>
#include <stdlib.h>

int Indegree(int A[][])
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            printf("%d\t", A[j][i]);
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

}
