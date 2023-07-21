#include <stdio.h>
#include <stdbool.h>

#ifndef MATRIX_TRAVERSAL_H
#define MATRIX_TRAVERSAL_H

#endif //MATRIX_TRAVERSAL_H

#include "defines.h"

void showRow(int [][N], int);

void showCol(int [][N], int);

/**
 * Muestra el contenido de la diagonal perteneciente al escalón inferior especificada por la posición inicial de fila
 * que recibe como parámetro.
 *
 * Si recibe 0 como parámetro, muestra la diagonal principal.
 *
 * @param matrix La matriz
 * @param row La posición inicial de fila.
 */
void showLowerDiag(int [][N], int);

/**
 * Muestra el contenido de la diagonal perteneciente al escalón superior especificada por la posición inicial de columna
 * que recibe como parámetro.
 *
 * Si recibe 0 como parámetro, muestra la diagonal principal.
 *
 * @param matrix La matriz
 * @param col La posición inicial de columna.
 */
void showUpperDiag(int [][N], int);

/**
 * Muestra el contenido de la diagonal invertida perteneciente al escalón inferior especificada por la posición inicial
 * de fila que recibe como parámetro.
 *
 * Si recibe 0 como parámetro, muestra la diagonal principal.
 *
 * @param matrix La matriz
 * @param row La posición inicial de fila.
 */
void showLowerInvertedDiag(int [][N], int);

/**
 * Muestra el contenido de la diagonal invertida perteneciente al escalón superior especificada por la posición inicial
 * de columna que recibe como parámetro.
 *
 * Si recibe N - 1 como parámetro, muestra la diagonal principal.
 *
 * @param matrix La matriz
 * @param col La posición inicial de columna.
 */
void showUpperInvertedDiag(int [][N], int);

void traverseByRow(int [][N]);

void traverseByCol(int [][N]);

/**
 * Muestra diagonal a diagonal el contenido de todas las diagonales que componen al escalón inferior. Si el parámetro
 * booleano es verdadero, la primera diagonal en ser mostrada es la diagonal principal.
 *
 * @param matrix La matriz
 * @param showMainDiag Un valor booleano que indica si la primera diagonal en ser mostrada debería ser la diagonal
 * principal.
 */
void traverseLowerEchelon(int [][N], bool);

/**
 * Muestra diagonal a diagonal el contenido de todas las diagonales que componen al escalón superior. Si el parámetro
 * booleano es verdadero, la primera diagonal en ser mostrada es la diagonal principal.
 *
 * @param matrix La matriz
 * @param showMainDiag Un valor booleano que indica si la primera diagonal en ser mostrada debería ser la diagonal
 * principal.
 */
void traverseUpperEchelon(int [][N], bool);

/**
 * Muestra diagonal a diagonal el contenido de todas las diagonales invertidas que componen al escalón inferior. Si el
 * parámetro booleano es verdadero, la primera diagonal invertida en ser mostrada es la diagonal invertida principal.
 *
 * @param matrix La matriz
 * @param showMainDiag Un valor booleano que indica si la primera diagonal invertida en ser mostrada debería ser la
 * diagonal invertida principal.
 */
void traverseLowerInvertedEchelon(int [][N], bool);

/**
 * Muestra diagonal a diagonal el contenido de todas las diagonales invertidas que componen al escalón superior. Si el
 * parámetro booleano es verdadero, la primera diagonal invertida en ser mostrada es la diagonal invertida principal.
 *
 * @param matrix La matriz
 * @param showMainDiag Un valor booleano que indica si la primera diagonal invertida en ser mostrada debería ser la
 * diagonal invertida principal.
 */
void traverseUpperInvertedEchelon(int [][N], bool);

void showRow(int matrix[][N], int row) {
    fflush(stdout);
    int col;
    for (col = 0; col < N; col++) {
        printf("%3d ", matrix[row][col]);
    }
    printf("\n");
}

void showCol(int matrix[][N], int col) {
    fflush(stdout);
    int row;
    for (row = 0; row < N; row++) {
        printf("%3d ", matrix[row][col]);
    }
    printf("\n");
}

void showLowerDiag(int matrix[][N], int row) {
    fflush(stdout);
    int col = 0;
    while (row < N) {
        printf("%3d ", matrix[row][col]);
        row++;
        col++;
    }
    printf("\n");
}

void showUpperDiag(int matrix[][N], int col) {
    fflush(stdout);
    int row = 0;
    while (col < N) {
        printf("%3d ", matrix[row][col]);
        row++;
        col++;
    }
    printf("\n");
}

void showLowerInvertedDiag(int matrix[][N], int row) {
    fflush(stdout);
    int col = N - 1;
    while (row < N) {
        printf("%3d ", matrix[row][col]);
        row++;
        col--;
    }
    printf("\n");
}

void showUpperInvertedDiag(int matrix[][N], int col) {
    fflush(stdout);
    int row = 0;
    while (col >= 0) {
        printf("%3d ", matrix[row][col]);
        row++;
        col--;
    }
    printf("\n");
}

void traverseByRow(int matrix[][N]) {
    int row;
    for (row = 0; row < N; row++) {
        showRow(matrix, row);
    }
}

void traverseByCol(int matrix[][N]) {
    int col;
    for (col = 0; col < N; col++) {
        showCol(matrix, col);
    }
}

void traverseLowerEchelon(int matrix[][N], bool showMainDiag) {
    int row;
    for (row = showMainDiag ? 0 : 1; row < N; row++) {
        showLowerDiag(matrix, row);
    }
}

void traverseUpperEchelon(int matrix[][N], bool showMainDiag) {
    int col;
    for (col = showMainDiag ? 0 : 1; col < N; col++) {
        showUpperDiag(matrix, col);
    }
}

void traverseLowerInvertedEchelon(int matrix[][N], bool showMainDiag) {
    int row;
    for (row = showMainDiag ? 0 : 1; row < N; row++) {
        showLowerInvertedDiag(matrix, row);
    }
}

void traverseUpperInvertedEchelon(int matrix[][N], bool showMainDiag) {
    int col;
    for (col = showMainDiag ? N - 1 : N - 2; col >= 0; col--) {
        showUpperInvertedDiag(matrix, col);
    }

}