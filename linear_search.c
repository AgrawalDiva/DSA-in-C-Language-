#include <stdio.h>

int main()
{
    int n, ele, pos, num = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &ele);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            num = 1;
            pos = i + 1;
            break;
        }
    }

    if (num == 1)
    {
        printf("%d is present at position %d\n", ele, pos);
    }
    else
    {
        printf("%d is not present in the array\n", ele);
    }

    return 0;
}
