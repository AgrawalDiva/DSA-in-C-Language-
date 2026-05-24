#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int choice, value, position, count;
    struct node *start = NULL, *newNode, *ptr, *prev;

    while (1) {
        printf("\n\nMENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Insert node
            printf("Enter position for insertion: ");
            scanf("%d", &position);

            count = 0;
            ptr = start;
            if (start != NULL) {
                do {
                    count++;
                    ptr = ptr->next;
                } while (ptr != start);
            }

            if (position < 1 || position > count + 1) {
                printf("Invalid insertion position!\n");
            } else {
                printf("Enter data: ");
                scanf("%d", &value);
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->data = value;

                if (position == 1) {
                    // Insert at beginning
                    if (start == NULL) {
                        start = newNode;
                        newNode->next = start;
                    } else {
                        ptr = start;
                        while (ptr->next != start) {
                            ptr = ptr->next;
                        }
                        newNode->next = start;
                        ptr->next = newNode;
                        start = newNode;
                    }
                } else {
                    // Insert at any position
                    ptr = start;
                    for (int i = 1; i < position - 1; i++) {
                        ptr = ptr->next;
                    }
                    newNode->next = ptr->next;
                    ptr->next = newNode;
                }
                printf("Node inserted successfully!\n");
            }
            break;

        case 2:
            // Delete node
            if (start == NULL) {
                printf("List is empty. No deletion possible.\n");
                break;
            }

            printf("Enter position to delete: ");
            scanf("%d", &position);

            count = 0;
            ptr = start;
            do {
                count++;
                ptr = ptr->next;
            } while (ptr != start);

            if (position < 1 || position > count) {
                printf("Invalid deletion position!\n");
            } else {
                if (position == 1) {
                    // Delete first node
                    ptr = start;
                    while (ptr->next != start) {
                        ptr = ptr->next;
                    }
                    if (start->next == start) {
                        free(start);
                        start = NULL;
                    } else {
                        ptr->next = start->next;
                        free(start);
                        start = ptr->next;
                    }
                } else {
                    // Delete at any position
                    prev = start;
                    ptr = start->next;
                    for (int i = 2; i < position; i++) {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                    prev->next = ptr->next;
                    free(ptr);
                }
                printf("Node deleted successfully!\n");
            }
            break;

        case 3:
            // Display circular linked list
            if (start == NULL) {
                printf("List is empty!\n");
            } else {
                ptr = start;
                printf("Circular Linked List: ");
                do {
                    printf("%d -> ", ptr->data);
                    ptr = ptr->next;
                } while (ptr != start);
                printf("(Back to start)\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
