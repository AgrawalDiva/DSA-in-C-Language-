#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n = 3, i;

    // malloc()
    arr = (int*)malloc(n * sizeof(int));
    printf("Using malloc:\n");
    for (i = 0; i < n; i++) arr[i] = i + 1;
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // calloc()
    arr = (int*)calloc(n, sizeof(int));
    printf("Using calloc:\n");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);  // Prints all 0s
    printf("\n");

    // realloc()
    arr = (int*)realloc(arr, 5 * sizeof(int));
    printf("Using realloc (extended to 5 elements):\n");
    for (i = 3; i < 5; i++) arr[i] = i + 1;  // Assign values to new elements
    for (i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // free()
    free(arr);
    printf("Memory freed.\n");

    return 0;
}
