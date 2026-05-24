#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sp[100][100];
    int row, column;
    
    // Input for matrix dimensions
    printf("Enter the number of rows of sparse matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns of sparse matrix: ");
    scanf("%d", &column);
    printf("\n");

    // Input elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &sp[i][j]);
        }
    }

    // Printing the matrix
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%4d", sp[i][j]);
        }
        printf("\n");
    }

    // Counting zero and non-zero elements
    int countz = 0, countnz = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (sp[i][j] == 0)
                countz++;
            else
                countnz++;
        }
    }

    // Check if matrix is sparse
    if (countz > countnz) {
        printf("\nThe matrix is a sparse matrix.\n");

        // Convert to triplet form
        int tri[countnz][3]; // Only store nonzero elements
        int k = 0;

        printf("\nTriplet Representation (Row, Column, Value):\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (sp[i][j] != 0) {
                    tri[k][0] = i;
                    tri[k][1] = j;
                    tri[k][2] = sp[i][j];
                    printf("%d %d %d\n", tri[k][0], tri[k][1], tri[k][2]);
                    k++;
                }
            }
        }
    } else {
        printf("\nThe matrix is not a sparse matrix.\n");
    }

    return 0;
}
