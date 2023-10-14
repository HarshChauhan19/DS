#include <stdio.h>

int main() {
    int row1, col1, row2, col2;

    // Input dimensions of the first matrix
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &col1);

    // Input dimensions of the second matrix
    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &col2);

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    // Declare two matrices
    int matrix1[row1][col1];
    int matrix2[row2][col2];
    int result[row1][col2];

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Initialize the result matrix with zeros
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Display the result matrix
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
