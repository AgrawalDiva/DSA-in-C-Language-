#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *start = NULL;

int main() {
    struct node *ptr, *nn, *save;
    int ch, item, pos;
    int cnt = 0;
    while (1) {
        printf("\n\nMENU \n1.Insert at the beginning\n2.Insert at the end\n3.Insert at any position\n4.Deletion\n5.Traversal\n6.Exit\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            // Insert at beginning
            printf("Enter the item: ");
            scanf("%d", &item);
            nn = (struct node *)malloc(sizeof(struct node));
            nn->info = item;
            nn->link = start;
            start = nn;
            break;

        case 2:
            // Insert at end
            printf("Enter the item: ");
            scanf("%d", &item);
            nn = (struct node *)malloc(sizeof(struct node));
            nn->info = item;
            nn->link = NULL;
            if (start == NULL) {
                start = nn;
            } else {
                ptr = start;
                while (ptr->link != NULL) {
                    ptr = ptr->link;
                }
                ptr->link = nn;
            }
            break;

        case 3:
            // Insert at any position
            printf("Enter the item: ");
            scanf("%d", &item);
            printf("Enter the position: ");
            scanf("%d", &pos);

            if (pos < 1) {
                printf("Invalid position!");
                break;
            }

            nn = (struct node *)malloc(sizeof(struct node));
            nn->info = item;

            if (pos == 1) {
                nn->link = start;
                start = nn;
            } else {
                ptr = start;
                for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
                    ptr = ptr->link;
                }
                if (ptr == NULL) {
                    printf("Invalid position!\n");
                } else {
                    nn->link = ptr->link;
                    ptr->link = nn;
                }
            }
            break;

        case 4:
            // Deletion at any position
            if (start == NULL) {
                printf("Not possible, list is empty\n");
                break;
            }
            ptr = start;
            cnt = 0;
            while (ptr != NULL) {
                cnt++;
                ptr = ptr->link;
            }
            printf("%d\n",cnt);

            
            printf("Enter the position of deletion: ");
            scanf("%d", &pos);

            
            if (pos < 1 || pos > cnt) {
                printf("Invalid position!\n");
                break;
            }

            if (pos == 1) {
                ptr = start;
                start = start->link;
                free(ptr);
            } else {
                save = start;
                ptr = start->link;
                for (int i = 2; i < pos && ptr != NULL; i++) {
                    save = ptr;
                    ptr = ptr->link;
                }
                if (ptr != NULL) {
                    save->link = ptr->link;
                    free(ptr);
                }
            }
            break;

        case 5:
            // Traversal
            if (start == NULL) {
                printf("List is empty!\n");
                break;
            }
            ptr = start;
            printf("Linked List Elements: ");
            while (ptr != NULL) {
                printf("%d -> ", ptr->info);
                ptr = ptr->link;
            }
            printf("NULL\n");
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
