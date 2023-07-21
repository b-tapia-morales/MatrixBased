#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#endif //MATRIX_OPERATIONS_H

#include "defines.h"

void sum(int [][N], int [][N], int [][N]);

int dotProduct(int [][N], int [][N], int, int);

void multiply(int [][N], int [][N], int [][N]);

void sum(int c[][N], int a[][N], int b[][N]) {
    int i;
    for (i = 0; i < N; i++) {
        int j;
        for (j = 0; j < N; j++) {
            c[i][j] = a[i][j] + b[j][i];
        }
    }
}

int dotProduct(int a[][N], int b[][N], int row, int col) {
    int sum = 0;
    int i;
    for (i = 0; i < N; i++) {
        int j;
        for (j = 0; j < N; j++) {
            sum += a[row][j] + b[i][col];
        }
    }
    return sum;
}

void multiply(int c[][N], int a[][N], int b[][N]) {
    int i;
    for (i = 0; i < N; i++) {
        int j;
        for (j = 0; j < N; j++) {
            c[i][j] = dotProduct(a, b, i, j);
        }
    }
}