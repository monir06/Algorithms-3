#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define MAX_SIZE 1000

int main() {

    unsigned int rows, columns;
    scanf("%d", &rows);
    columns = rows + 1;

    // Check the inputted row and column size
    assert(rows < MAX_SIZE);
    assert(columns < MAX_SIZE);
    double matrix[MAX_SIZE][MAX_SIZE];

    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Now compute a upper matrix
    double pivot, coefficient, swap;
    int k,l,m,flag;
    int temp1, temp2;

    for (i = 0; i < rows; i++) {
        printf("\nRow %d\n------\n", i);

        // Partial Pivotting
        if (matrix[i][i] == 0) {
            flag = 0; // Indicates that we have not found a row to swap

            for (l=i+1; l<rows; l++) {
                if (matrix[l][i] != 0) {
                    flag = 1; // Indicates that we have found a row to swap
                    for (m=i; m<columns; m++) {
                        swap= matrix[l][m];
                        matrix[l][m] = matrix[i][m];
                        matrix[i][m] = swap;
                    }

                    // Print the matrix
                    printf("Pivoting row %d with row %d\n\n", i, l);
                    for (temp1 = 0; temp1 < rows; temp1++) {
                        for (temp2 = 0; temp2 < columns; temp2++) {
                            printf("%lf\t", matrix[temp1][temp2]);
                        }
                        printf("\n");
                    }
                    printf("\n");

                    break;
                }
            }

            if (!flag) {
                printf("Cannot pivot. Exiting");
                exit(1);
            }
        }

        // Define the pivot
        pivot = matrix[i][i];

        // Eliminate
        for (j = i + 1; j < rows; j++) {
            coefficient = matrix[j][i] / pivot;

            matrix[j][i] = 0;
            for (k = i + 1; k < columns; k++) {
                matrix[j][k] -= coefficient * matrix[i][k];
            }

            for (temp1 = 0; temp1 < rows; temp1++) {
                for (temp2 = 0; temp2 < columns; temp2++) {
                    printf("%lf\t", matrix[temp1][temp2]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    // Compute the result
    double result[rows];
    double sum;

    for (i = rows - 1; i >= 0; i--) {
        sum = matrix[i][columns-1];
        for (j = rows - 1; j > i; j--) {
            sum -= matrix[i][j] * result[j];
        }
        result[i] = sum / matrix[i][i];
    }

    for (i = 0; i < rows; i++) {
        printf("\nValue of x[%d] is %lf", i + 1, result[i]);
    }

    return 0;
}
