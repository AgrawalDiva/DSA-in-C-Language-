#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

int main()
{
    struct node *ptr, *nn, *temp;
    int ch, item;

    while (1)
    {
        printf("\nMAIN MENU\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            // enqueue
            nn = (struct node *)malloc(sizeof(struct node));
            if (nn == NULL)
            {
                printf("Memory allocation failed!\n");
                break;
            }
            printf("\nEnter the item: ");
            scanf("%d", &item);
            nn->data = item;
            nn->link = NULL;

            if (start == NULL)
            {
                start = nn;
            }
            else
            {
                ptr = start;
                while (ptr->link != NULL)
                {
                    ptr = ptr->link;
                }
                ptr->link = nn;
            }
            break;

        case 2:
            // dequeue
            if (start == NULL)
            {
                printf("\nQueue is empty! Underflow condition.\n");
            }
            else
            {
                ptr = start;
                printf("\nITEM DELETED = %d\n", ptr->data);
                start = start->link;
                free(ptr);
            }
            break;

        case 3:
            // show
            if (start == NULL)
            {
                printf("\nQueue is empty!\n");
            }
            else
            {
                ptr = start;
                printf("\nQueue Elements:\n");
                while (ptr != NULL)
                {
                    printf("%d\n", ptr->data);
                    ptr = ptr->link;
                }
            }
            break;

        case 4:
            // exit
            exit(0);

        default:
            printf("\nInvalid operation! Please enter a valid choice.\n");
        }
    }

    return 0;
}
