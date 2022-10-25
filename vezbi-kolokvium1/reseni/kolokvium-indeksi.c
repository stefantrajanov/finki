//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int main(){
    int n;
    int arr[1000];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Grupa 1\n");
    for (int i = 0; i < n; ++i) {
        int digit = arr[i] % 10;

        if (digit == 0 || digit == 1 || digit == 2){
            printf("%d ", arr[i]);
        }
    }
    printf("\nGrupa 2\n");
    for (int i = 0; i < n; ++i) {
        int digit = arr[i] % 10;

        if (digit == 3 || digit == 4 || digit == 5){
            printf("%d ", arr[i]);
        }
    }

    printf("\nGrupa 3\n");
    for (int i = 0; i < n; ++i) {
        int digit = arr[i] % 10;

        if (digit == 6 || digit == 7 || digit == 8 || digit == 9){
            printf("%d ", arr[i]);
        }
    }

    return 0;
}