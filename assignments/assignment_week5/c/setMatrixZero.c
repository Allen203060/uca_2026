#include <stdio.h>

void setZeroes(int matrix[31][31], int m, int n) {
    int firstRowZero = 0, firstColZero = 0;

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(int matrix[31][31], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // int matrix[31][31] = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1}
    // };

    int matrix[31][31] = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5}
    };
    int m = 3, n = 3;

    setZeroes(matrix, m, n);

    printf("Output:\n");
    printMatrix(matrix, m, n);

    return 0;
}