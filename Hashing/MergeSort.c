#include <stdio.h>
#include <stdlib.h>

void Split(int A[], int size)
{
    int l[size/2], r[size/2];
    int mid = size/2;
    for (int i = 0; i < mid; i++)
    {
        l[i] = A[i];
        printf("%d\t", l[i]);
    }
    printf("\n");
    for (int j = mid; j < size; j++)
    {
        r[j] = A[j];
        printf("%d\t", r[j]);
    }

}

int * MergeSort(int A[])
{
    
}

void main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int *A = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &A[i]);
    }
    Split(A, size);
}