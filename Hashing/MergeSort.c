#include <stdio.h>
#include <stdlib.h>

void Merge(int a[], int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r-m;

    int templeft[left_length];
    int tempright[right_length];

    int i,j,k;

    for ( i = 0; i < left_length; i++)
    {
        templeft[i] = a[l + i];
    }
    for ( j = 0; j < right_length; j++)
    {
        tempright[j] = a[m+1+j];
    }

    for ( i = 0, j = 0, k = l; k<=r; k++ )
    {
        if ((i < left_length && j >= right_length) || templeft[i] <= tempright[j])
        {
            a[k] = templeft[i];
            i++;
        }
        else
        {
            a[k] = tempright[j];
            j++;
        }
    }
}

void MergeSortRecursion(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + (r-l))/2;
        MergeSortRecursion(a,l,m);
        MergeSortRecursion(a, m+1, r);
        Merge(a,l,m,r); 
    }

}

void MergeSort(int a[], int length)
{
    MergeSortRecursion(a, 0, length - 1);
}

void main()
{
    int length = 9;
    int a[] = {1,9,6,7,8,2,3,4,5};
    MergeSort(a,length);
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
}