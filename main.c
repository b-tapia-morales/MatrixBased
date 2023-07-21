#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "defines.h"
#include "matrix_traversal.h"
#include "matrix_operations.h"

void pause();

void drawLine(int);

void displayWithPadding(int [][N], int);

void display(int [][N]);

void fillBackwards(int [][N], int, int, int, int *);

void fillDownwards(int [][N], int, int, int, int *);

void fillForwards(int [][N], int, int, int, int *);

void fillUpwards(int [][N], int, int, int, int *);

void clockwiseSpiral(int [][N]);

void counterClockwiseSpiral(int [][N]);

void pause() {
    fflush(stdin);
    fflush(stdout);
    printf("Presione enter para continuar...");
    getchar();
    printf("\n");
}

void drawLine(int padding) {
    int i;
    for (i = 0; i < N; i++) {
        printf("+--");
        int j;
        for (j = 0; j < padding; j++) {
            printf("-");
        }
    }
    printf("+\n");
}

void displayWithPadding(int matrix[][N], int padding) {
    fflush(stdout);
    drawLine(padding);
    int i;
    for (i = 0; i < N; i++) {
        fflush(stdout);
        int j;
        for (j = 0; j < N; j++) {
            printf("| %*d ", padding, matrix[i][j]);
        }
        printf("|\n");
        drawLine(padding);
    }
    printf("\n");
}

void display(int matrix[][N]) {
    displayWithPadding(matrix, PAD);
}

void fillBackwards(int matrix[][N], int i, int start, int stop, int *counter) {
    int j;
    for (j = start; j > stop; j--) {
        matrix[i][j] = (*counter)--;
    }
}

void fillDownwards(int matrix[][N], int j, int start, int stop, int *counter) {
    int i;
    for (i = start; i < stop; i++) {
        matrix[i][j] = (*counter)--;
    }
}

void fillForwards(int matrix[][N], int i, int start, int stop, int *counter) {
    int j;
    for (j = start; j < stop; j++) {
        matrix[i][j] = (*counter)--;
    }
}

void fillUpwards(int matrix[][N], int j, int start, int stop, int *counter) {
    int i;
    for (i = start; i > stop; i--) {
        matrix[i][j] = (*counter)--;
    }
}

void clockwiseSpiral(int matrix[][N]) {
    int counter = N * N;
    int i;
    for (i = 1; i <= N - 2; i++) {
        fillBackwards(matrix, i - 1, N - i, i - 1, &counter);
        fillDownwards(matrix, i - 1, i - 1, N - i, &counter);
        fillForwards(matrix, N - i, i - 1, N - i, &counter);
        fillUpwards(matrix, N - i, N - i, i - 1, &counter);
    }
    matrix[(N - 1) / 2][(N - 1) / 2] = 1;
}

void counterClockwiseSpiral(int matrix[][N]) {
    int counter = N * N;
    int i;
    for (i = 1; i <= N - 2; i++) {
        fillBackwards(matrix, N - i, N - i, i - 1, &counter);
        fillUpwards(matrix, i - 1, N - i, i - 1, &counter);
        fillForwards(matrix, i - 1, i - 1, N - i, &counter);
        fillDownwards(matrix, N - i, i - 1, N - i, &counter);
    }
    matrix[(N - 1) / 2][(N - 1) / 2] = 1;
}

int main() {
    assert((N >= 3 && N <= 31 && N % 2 == 1) && "The size must be an even number in the range [3, 31]");
    int a[N][N] = {0};
    clockwiseSpiral(a);
    display(a);
    pause();
    traverseByRow(a);
    pause();
    traverseByCol(a);
    pause();
    traverseLowerEchelon(a, true);
    pause();
    traverseUpperEchelon(a, true);
    pause();
    traverseLowerInvertedEchelon(a, true);
    pause();
    traverseUpperInvertedEchelon(a, true);
    pause();
    int b[N][N] = {0}, c[N][N] = {0};
    counterClockwiseSpiral(b);
    display(b);
    pause();
    sum(c, a, b);
    displayWithPadding(c, WIDE_PAD);
    pause();
    multiply(c, a, b);
    displayWithPadding(c, WIDE_PAD);
    pause();
    return 0;
}
