//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>
#include <stdlib.h>

int main (){
    int m;
    int n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int leftSum = 0;
        int rightSum = 0;
        for (int j = 0; j < n; ++j) {
            if (j < n/2){
                leftSum += matrix[i][j];
            }
            else{
                rightSum += matrix[i][j];
            }
        }
        if (n % 2 != 0){
            leftSum += matrix[i][n/2];
        }

        int replaceNum = abs(rightSum - leftSum);
        if (n % 2 == 0){
            matrix[i][n/2] = replaceNum;
            matrix[i][(n/2) - 1] = replaceNum;
        }
        else{
            matrix[i][n/2] = replaceNum;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}