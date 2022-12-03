//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>

void printMatrix(int matrix[100][100], int m, int n, int equalSum){
    for (int i = 0; i < m; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }
        if (rowSum > equalSum){
            for (int j = 0; j < n; ++j) {
                printf("1 ");
            }
        } else if (rowSum < equalSum){
            for (int j = 0; j < n; ++j) {
                printf("-1 ");
            }
        }
        else
        {
            for (int j = 0; j < n; ++j) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int equalSum;
    int m;
    int n;
    int arr[100][100];
    scanf("%d %d %d", &equalSum, &m, &n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    printMatrix(arr,m,n,equalSum);

    return 0;
}