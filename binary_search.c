#include <stdio.h>

int main()
{
    int n, ele, pos = -1;

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
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array in ascending order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to be searched: ");
    scanf("%d", &ele);

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            pos = mid + 1;
            break;
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (pos != -1)
    {
        printf("%d is present at position %d\n", ele, pos);
    }
    else
    {
        printf("%d is not present in the array\n", ele);
    }

    return 0;
}
