//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>

float sumMainDiagonal(float matrix[100][100], int n){
    float sum = 0;
    int counter = 0;
    for (int i = 1; counter < n - 1; ++i) {
        for (int j = 0; j <= counter; ++j) {
            sum += matrix[i][j];
        }
        counter++;
    }

    return sum;
}

float sumOppositeDiagonal(float matrix[100][100], int n){
    float sum = 0;
    int counter = n - 1;
    for (int i = 1; counter > 0; ++i) {
        for (int j = counter; j < n; ++j) {
            sum += matrix[i][j];
        }
        counter--;
    }

    return sum;
}

void printMatrix(float matrix[100][100], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    float matrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%f", &matrix[i][j]);
        }
    }

    float sumMain = sumMainDiagonal(matrix, n);
    float sumOpposite = sumOppositeDiagonal(matrix,n);

    float newMatrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j && (i+j) == n - 1){
                newMatrix[i][j] = sumMain + sumOpposite;
            }
            else if (i == j){
                newMatrix[i][j] = sumMain;
            }else if ((i+j)== n - 1){
                newMatrix[i][j] = sumOpposite;
            }else{
                newMatrix[i][j] = 0;
            }
        }
    }

    printMatrix(newMatrix,n);

    return 0;
}