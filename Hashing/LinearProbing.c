#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int HashFunction(int data)
{
    int key;
    key = data % 100;
    return key;
}

void Insert(int Hash_Table[], int dataset[])
{
    int key;
    for (int i=0; i<100; i++)
    {
        key = HashFunction(dataset[i]);
        while (Hash_Table[key] != -1)
        {
            key++;
            if (key == 100)
            {
                key = 0;
            }
        }
        Hash_Table[key] = dataset[i];
    }
}

void main()
{
    int Hash_Table[100];
    for (int i=0; i<100; i++)
    {
        Hash_Table[i] = -1;
    }
    srand(time(NULL));
    int dataset[100];
    for (int i = 0; i<100; i++)
    {
        dataset[i] = i;
        //dataset[i] = rand() % 100 +1;
    }
    Insert(Hash_Table, dataset);
    for (int i=0; i<100; i++)
    {
        printf("%d\n", Hash_Table[i]);
    }
}