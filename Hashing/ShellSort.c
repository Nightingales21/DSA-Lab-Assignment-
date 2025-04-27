#include <stdio.h>
#include <stdlib.h>

void Swap(int a[],int i,int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void ShellSortRecursion(int a[],int i,int  j,int gap)
{
    if (a[i] > a[j])
        {
            Swap(a,i,j);
            if ((i - gap) > 0)
            {
               Swap(a,(i-gap),(j-gap));
            }
        }
    
}

void ShellSort(int a[], int length, int gap)
{
    if (gap > 0)
    {
        int i,j;
        for (i=0, j=0+gap; j < length; i=i+gap, j=j+gap)
        {
            ShellSortRecursion(a,i,j,gap);
        }
        ShellSort(a,length, gap/2);
    }
}

void main()
{
    int length = 9;
    int a[] = {1,3,5,7,2,4,6,8,9};
    int gap = length / 2;
    ShellSort(a,length,gap);
    for (int i = 0; i<length; i++)
    {
        printf("%d\t", a[i]);
    }
}