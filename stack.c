#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, ch, item, top = -1;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    
    int a[n]; // Stack array
    for (int i = 0; i < n; i++) {
        a[i] = 0; // Initialize stack with zeros
    }

    while (1) {
        printf("\nMAIN MENU\n1. PUSH\n2. POP\n3. SHOW\n4. EXIT\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: // PUSH operation
            if (top == n - 1) {
                printf("Stack Overflow!\n");
            } else {
                printf("Enter the item: ");
                scanf("%d", &item);
                top++;
                a[top] = item;
            }
            break;

        case 2: // POP operation
            if (top == -1) {
                printf("Stack Underflow!\n");
            } else {
                printf("The popped item is %d\n", a[top]);
                a[top] = 0; // Reset the popped position
                top--;
            }
            break;

        case 3: // SHOW stack elements
            if (top == -1) {
                printf("Stack is empty.\n");
            } else {
                printf("Stack elements: ");
                for (int i = 0; i <= top; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
            }
            break;

        case 4: // Exit condition
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
