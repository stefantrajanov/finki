//
// Created by Stefan on 12/1/2022.
//
#include <stdio.h>

int rowOneCounter(int arr[100][100], int n, int m){
    int counter = 0;
    int oneCounter = 0;
    for (int i = 0; i < n; ++i) {
        counter = 0;
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 1){
                counter++;
            }else
            {
                counter = 0;
            }
            if (counter == 3){
                oneCounter++;
                counter = 0;
                break;
            }
        }

    }

    return oneCounter;
}

int colOneCounter(int arr[100][100], int n, int m){
    int counter = 0;
    int oneCounter = 0;
    for (int i = 0; i < m; ++i) {
        counter = 0;
        for (int j = 0; j < n; ++j) {
            int temp = arr[j][i];
            if (temp == 1){
                counter++;
            }else
            {
                counter = 0;
            }
            if (counter == 3){
                oneCounter++;
                counter = 0;
                break;
            }
        }

    }

    return oneCounter;
}

int main (){
    int n;
    int m;
    scanf("%d %d", &n , &m);

    int matrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int rowOnes = rowOneCounter(matrix,n,m);
    int colOnes = colOneCounter(matrix,n,m);

    int oneCounter = rowOnes + colOnes;

    printf("%d", oneCounter);

    return 0;
}