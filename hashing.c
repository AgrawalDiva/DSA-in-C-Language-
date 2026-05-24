#include <stdio.h>

int main()
{
    int size, choice, i, key, pos, found, h[100];
    
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
        h[i] = -1;

    printf("\nChoose Hashing Technique:\n1. Linear Probing\n2. Quadratic Probing\nEnter your choice: ");
    scanf("%d", &choice);

    int n;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    if (choice == 1)
    {
        printf("\nUsing Linear Probing:\n");
        for (i = 0; i < n; i++)
        {
            printf("Enter key to insert: ");
            scanf("%d", &key);
            pos = key % size;

            while (h[pos] != -1)
                pos = (pos + 1) % size;

            h[pos] = key;
        }
    }
    else if (choice == 2)
    {
        printf("\nUsing Quadratic Probing:\n");
        for (i = 0; i < n; i++)
        {
            printf("Enter key to insert: ");
            scanf("%d", &key);
            int j = 0;
            pos = key % size;
            while (h[(pos + j * j) % size] != -1)
                j++;
            h[(pos + j * j) % size] = key;
        }
    }
    else
    {
        printf("Invalid choice!\n");
        return 0;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < size; i++)
        printf("Index %d: %d\n", i, h[i]);

    return 0;
}
    