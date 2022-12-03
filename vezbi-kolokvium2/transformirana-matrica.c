//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>

void printMatrix(int matrix[100][100], int n){
    for (int i = 0; i < n*2; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main (){
    int n;
    scanf("%d", &n);
    int m = n*2;


    int matrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int newMatrix[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    int tempRow = 0;
    int tempItem = n;
    for (int i = n; i < m; ++i) {
        tempItem = n;
        for (int j = 0; j < n; ++j) {
            newMatrix[i][j] = matrix[tempRow][tempItem];
            tempItem++;
        }
        tempRow++;
    }
    printMatrix(newMatrix,n);

    return 0;
}