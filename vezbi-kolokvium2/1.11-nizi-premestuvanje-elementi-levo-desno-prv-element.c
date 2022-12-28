//
// Created by Stefan on 12/19/2022.
//
#include <stdio.h>
#include <stdlib.h>

void elementShift (int *arr, int n, int *zeroElements){
    // if first num positive go right else go left first num spaces
    // 1 2 3 4 5
    // 1 shift
    // 0 1 2 3 4
    int tempArray[100];

    for (int i = 0; i < 100; ++i) {
        tempArray[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        tempArray[i] = arr[i];
    }

    int shift = arr[0];

    if (abs(shift) > n){
        for (int i = 0; i < n; ++i) {
            arr[i] = 0;
        }
    }
    else {

        for (int i = 0; i < n; ++i) {
            if (i < shift) {
                arr[i] = 0;
            } else {
                arr[i] = tempArray[i - shift];
            }
        }
    }

    int flag = 1;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0){
            flag = 0;
        }
    }
    if (flag){*zeroElements += 1;}

    for (int j = 0; j < n; ++j) {
        printf("%d ", arr[j]);
    }
}

int main(){
    int m;
    scanf("%d", &m);

    int arr[100];
    int zeroElementsPointer = 0;
    int n;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
        }
        elementShift(arr,n, &zeroElementsPointer);
        printf("\n");
    }

    printf("%d", zeroElementsPointer);

    return 0;
}