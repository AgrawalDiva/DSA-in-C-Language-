#include <stdio.h>
#include <stdlib.h>

int main()
{
    int MAX, front, rear, ch, item;
    printf("Enter number of maximum elements in the queue: ");
    scanf("%d", &MAX);
    int q[MAX]; // Fixed-size array (VLA)
    front = -1;
    rear = -1;

    while (1)
    {
        printf("\n\nMain Menu\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the item you want to enter: ");
            scanf("%d", &item);
            if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front)
            {
                printf("Queue is overflow\n");
                break;
            }
            if (front == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % MAX;
            }
            q[rear] = item;
            break;

        case 2:
            if (front == -1)
            {
                printf("Queue is empty\n");
                break;
            }
            printf("Item deleted from the queue is %d\n", q[front]);
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
            break;

        case 3:
            if (front == -1)
            {
                printf("Queue is empty\n");
                break;
            }
            printf("Elements of queue are: ");
            int i = front;
            while (1)
            {
                printf("%d ", q[i]);
                if (i == rear)
                    break;
                i = (i + 1) % MAX;
            }
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
