#include <stdio.h>

int main()
{
   
    int arr[10]={1,2,3,-4,5,6,3,4,53,7};
    int n=10;
    int max = arr[0];
    int min = arr[0];
    for (int i =0; i<=n; i++)
    {
        if (arr[i]>max)
            max= arr[i];
        if (arr[i]<min)
            min = arr[i];
    }
    printf("The maximum number is: %d \nThe minimum number is: %d",max, min);
    return 0;
}