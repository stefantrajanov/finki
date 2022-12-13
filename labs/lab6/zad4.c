//
// Created by Stefan on 12/7/2022.
//
#include <stdio.h>

int arrayCheck (const int *arr, int n, int evenStart){
    // 1 2 3 4 5 6 7 8 9
    // 0 1 0 1 0 1 0 1 0

    // 0 1 2 3 4 5 6 7 8
    // 1 0 1 0 1 0 1 0 1

    // 0 ne paren
    // 1 paren

    int start;
    if (evenStart == 1){
        start = 0; // treba da pocne so neparen
    }else{
        start = 1; // treba da pocne so paren
    }

    int startCheck = (arr[0] % 2 == 0); // ako prviot element e sprotivno od start togi return 0;
    if (startCheck != start){
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int elementValue = (arr[i] % 2 == 0);
        // ako e paren elementValue = 1;
        // ako ne e elementValue = 0;
        if (i % 2 == 0){
            // sekoj paren indeks treba da e == start
            if (elementValue != start){
                return 0;
            }// sekoj neparen index treba da e != start
        }else{
            if (elementValue == start){
                return 0;
            }
        }
    }

    return 1;
}

int main (){
    int n;
    int evenOrOddStart;

    scanf("%d %d", &n, &evenOrOddStart);

    int arr[100];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    if (arrayCheck(arr, n, evenOrOddStart)){
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        return 0;
    }

    printf("-1");
    return 0;
}