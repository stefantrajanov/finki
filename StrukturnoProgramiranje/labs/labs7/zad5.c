//
// Created by Stefan on 12/14/2022.
//
#include <stdio.h>

int findMax(int arr[100][100], int n, int m, int currentColumn){
    int max = 0;

    for (int j = 0; j < n; ++j) {
        if (max < arr[j][currentColumn]){
            max = arr[j][currentColumn];
        }
    }


    return max;
}

int findMin(int arr[100][100], int n, int m, int currentColumn){
    int min;
    int flag = 1;

    for (int j = 0; j < n; ++j) {
        if (flag){
            min = arr[j][currentColumn];
            flag = 0;
        }
        if (min > arr[j][currentColumn]){
            min = arr[j][currentColumn];
        }
    }


    return min;
}

int main (){
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int arr[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            float max = findMax(arr, n, m, j);
            float min = findMin(arr, n, m, j);

            float first = arr[i][j] - min;
            float second = max - min;

            float result = first / second;

            printf("%3.2f ", result);
        }
        printf("\n");
    }

    return 0;
}