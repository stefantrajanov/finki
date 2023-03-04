//
// Created by Stefan on 12/13/2022.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] < 0 ){
                int sum = arr[i-1][j] + arr[i+1][j] + arr[i][j + 1] + arr[i][j - 1];
                arr[i][j] = sum;
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}