#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Find Minimum\n4. Find Maximum\n5. Delete\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter value to insert: ");
            scanf("%d", &value);
            newnode->data = value;
            newnode->left = newnode->right = NULL;

            if (root == NULL) {
                root = newnode;
            } else {
                struct node *curr = root, *parent = NULL;
                while (curr != NULL) {
                    parent = curr;
                    if (value < curr->data)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                if (value < parent->data)
                    parent->left = newnode;
                else
                    parent->right = newnode;
            }
        }

        else if (choice == 2) {
            printf("Enter value to search: ");
            scanf("%d", &value);
            struct node *curr = root;
            int found = 0;
            while (curr != NULL) {
                if (value == curr->data) {
                    found = 1;
                    break;
                } else if (value < curr->data) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
            if (found)
                printf("%d found in BST\n", value);
            else
                printf("%d not found in BST\n", value);
        }

        else if (choice == 3) {
            if (root == NULL) {
                printf("Tree is empty\n");
            } else {
                struct node *curr = root;
                while (curr->left != NULL)
                    curr = curr->left;
                printf("Minimum value = %d\n", curr->data);
            }
        }

        else if (choice == 4) {
            if (root == NULL) {
                printf("Tree is empty\n");
            } else {
                struct node *curr = root;
                while (curr->right != NULL)
                    curr = curr->right;
                printf("Maximum value = %d\n", curr->data);
            }
        }

        else if (choice == 5) {
            printf("Enter value to delete: ");
            scanf("%d", &value);
            struct node *curr = root, *parent = NULL;

            while (curr != NULL && curr->data != value) {
                parent = curr;
                if (value < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }

            if (curr == NULL) {
                printf("Value not found in BST\n");
                continue;
            }

            if (curr->left == NULL && curr->right == NULL) {
                if (parent == NULL)
                    root = NULL;
                else if (parent->left == curr)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                free(curr);
            }

            else if (curr->left == NULL || curr->right == NULL) {
                struct node *child = (curr->left != NULL) ? curr->left : curr->right;
                if (parent == NULL)
                    root = child;
                else if (parent->left == curr)
                    parent->left = child;
                else
                    parent->right = child;
                free(curr);
            }

            else {
                struct node *succ = curr->right, *succParent = curr;
                while (succ->left != NULL) {
                    succParent = succ;
                    succ = succ->left;
                }
                curr->data = succ->data;
                if (succParent->left == succ)
                    succParent->left = succ->right;
                else
                    succParent->right = succ->right;
                free(succ);
            }

            printf("Deleted %d from BST\n", value);
        }

        else if (choice == 6) {
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
1