//
// Created by Stefan on 12/13/2022.
//
#include <stdio.h>

int main (){
    int n;
    scanf("%d", &n);

    int matrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
            if (i > j && i + j >= n){
                matrix[i][j]*=(-1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}