#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct node
    {
        int data;
        struct node *left;
        struct node *right;
    };

    struct node *root = NULL, *temp, *newNode;
    int choice, data, ch;

    while (1)
    {
        printf("\n1. Insert Node\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d", &newNode->data);
            newNode->left = NULL;
            newNode->right = NULL;

            if (root == NULL)
            {
                root = newNode;
            }
            else
            {
                temp = root;
                while (1)
                {
                    printf("Enter 1 to insert to left of %d, 2 to insert to right of %d: ", temp->data, temp->data);
                    scanf("%d", &ch);
                    if (ch == 1)
                    {
                        if (temp->left == NULL)
                        {
                            temp->left = newNode;
                            break;
                        }
                        else
                        {
                            temp = temp->left;
                        }
                    }
                    else if (ch == 2)
                    {
                        if (temp->right == NULL)
                        {
                            temp->right = newNode;
                            break;
                        }
                        else
                        {
                            temp = temp->right;
                        }
                    }
                    else
                    {
                        printf("Invalid input\n");
                    }
                }
            }
        }
        else if (choice == 2)
        {
            printf("Preorder Traversal: ");
            struct node *stack[100];
            int top = -1;
            struct node *curr = root;
            while (curr != NULL || top != -1)
            {
                while (curr != NULL)
                {
                    printf("%d ", curr->data);
                    stack[++top] = curr;
                    curr = curr->left;
                }
                curr = stack[top--];
                curr = curr->right;
            }
            printf("\n");
        }
        else if (choice == 3)
        {
            printf("Inorder Traversal: ");
            struct node *stack[100];
            int top = -1;
            struct node *curr = root;
            while (curr != NULL || top != -1)
            {
                while (curr != NULL)
                {
                    stack[++top] = curr;
                    curr = curr->left;
                }
                curr = stack[top--];
                printf("%d ", curr->data);
                curr = curr->right;
            }
            printf("\n");
        }
        else if (choice == 4)
        {
            printf("Postorder Traversal: ");
            struct node *stack1[100], *stack2[100];
            int top1 = -1, top2 = -1;
            struct node *curr = root;

            if (curr != NULL)
                stack1[++top1] = curr;

            while (top1 != -1)
            {
                curr = stack1[top1--];
                stack2[++top2] = curr;
                if (curr->left)
                    stack1[++top1] = curr->left;
                if (curr->right)
                    stack1[++top1] = curr->right;
            }

            while (top2 != -1)
            {
                printf("%d ", stack2[top2--]->data);
            }
            printf("\n");
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
