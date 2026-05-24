    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int a1[100][100];
        int a2[100][100];
        int row1, column1, row2, column2;
        printf("Enter the number of rows in matrix 1: ");
        scanf("%d", &row1);
        printf("Enter the number of columns in matrix 1: ");
        scanf("%d", &column1);

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                printf("Enter a1[%d][%d] element: ", i + 1, j + 1);
                scanf("%d", &a1[i][j]);
            }
        }

        printf("Enter the number of rows in matrix 2: ");
        scanf("%d", &row2);
        printf("Enter the number of columns in matrix 2: ");
        scanf("%d", &column2);

        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < column2; j++) {
                printf("Enter a2[%d][%d] element: ", i + 1, j + 1);
                scanf("%d", &a2[i][j]);
            }
        }

        int ch;
        while (1) {
            printf("\n\nMain Menu\n\n");
            printf("1. Addition\n");
            printf("2. Subtraction\n");
            printf("3. Multiplication\n");
            printf("4. Transpose\n");
            printf("5. Traversal\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &ch);

            switch (ch) {
                case 1: {
                    // Addition
                    if (row1 == row2 && column1 == column2) {
                        int add[100][100];
                        printf("Result of Addition:\n");
                        for (int i = 0; i < row1; i++) {
                            for (int j = 0; j < column1; j++) {
                                add[i][j] = a1[i][j] + a2[i][j];
                                printf("%d ", add[i][j]);
                            }
                            printf("\n");
                        }
                    } else {
                        printf("Addition cannot be performed due to unequal matrix dimensions.\n");
                    }
                    break;
                }

                case 2: {
                    // Subtraction
                    if (row1 == row2 && column1 == column2) {
                        int sub[100][100];
                        printf("Result of Subtraction:\n");
                        for (int i = 0; i < row1; i++) {
                            for (int j = 0; j < column1; j++) {
                                sub[i][j] = a1[i][j] - a2[i][j];
                                printf("%d ", sub[i][j]);
                            }
                            printf("\n");
                        }
                    } else {
                        printf("Subtraction cannot be performed due to unequal matrix dimensions.\n");
                    }
                    break;
                }

                case 3: {
                    // Multiplication
                    if (column1 == row2) {
                        int multi[100][100] = {0};
                        printf("Result of Multiplication:\n");
                        for (int i = 0; i < row1; i++) {
                            for (int j = 0; j < column2; j++) {
                                for (int k = 0; k < column1; k++) {
                                    multi[i][j] += a1[i][k] * a2[k][j];
                                }
                                printf("%d ", multi[i][j]);
                            }
                            printf("\n");
                        }
                    } else {
                        printf("Multiplication cannot be performed due to incompatible matrix dimensions.\n");
                    }
                    break;
                }

                case 4: {
                    // Transpose
                    printf("Transpose of Matrix 1:\n");
                    for (int i = 0; i < column1; i++) {
                        for (int j = 0; j < row1; j++) {
                            printf("%d ", a1[j][i]);
                        }
                        printf("\n");
                    }
                    printf("Transpose of Matrix 2:\n");
                    for (int i = 0; i < column2; i++) {
                        for (int j = 0; j < row2; j++) {
                            printf("%d ", a2[j][i]);
                        }
                        printf("\n");
                    }
                    break;
                }

                case 5: {
                    // Traversal
                    printf("Traversal of Matrix 1:\n");
                    for (int i = 0; i < row1; i++) {
                        for (int j = 0; j < column1; j++) {
                            printf("%d ", a1[i][j]);
                        }
                        printf("\n");
                    }
                    printf("Traversal of Matrix 2:\n");
                    for (int i = 0; i < row2; i++) {
                        for (int j = 0; j < column2; j++) {
                            printf("%d ", a2[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                }

                case 6:
                    // Exit
                    printf("Exiting program.\n");
                    exit(0);

                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }

        return 0;
    }
