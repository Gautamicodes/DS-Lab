#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    // Input matrix sizes
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    int A[20][20], B[20][20], C[20][20];

    // Input first matrix
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input second matrix
    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int choice;
    printf("\nChoose operation:");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Transpose of First Matrix");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            if (r1 == r2 && c1 == c2) {
                printf("\nAddition Result:\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        C[i][j] = A[i][j] + B[i][j];
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Addition not possible!\n");
            }
            break;

        case 2: // Subtraction
            if (r1 == r2 && c1 == c2) {
                printf("\nSubtraction Result:\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        C[i][j] = A[i][j] - B[i][j];
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Subtraction not possible!\n");
            }
            break;

        case 3: // Multiplication
            if (c1 == r2) {
                printf("\nMultiplication Result:\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        C[i][j] = 0;
                        for (int k = 0; k < c1; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Multiplication not possible!\n");
            }
            break;

        case 4: // Transpose
            printf("\nTranspose of First Matrix:\n");
            for (int i = 0; i < c1; i++) {
                for (int j = 0; j < r1; j++) {
                    printf("%d ", A[j][i]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
