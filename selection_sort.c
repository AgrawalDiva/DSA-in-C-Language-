#include <stdio.h>

int main()
{
    int n, temp, min, max;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("\nArray in ascending order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }

    printf("\nArray in descending order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
