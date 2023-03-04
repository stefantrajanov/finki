//
// Created by Stefan on 12/1/2022.
//
#include <stdio.h>

int sumValidNum(int *arr, int *index, int *n){
    int sum = 0;
    for (int i = *index; i < *n; ++i) {
        sum += arr[i];
    }

    return sum;
}


int main(){
    int n;
    int arr[100];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int index;
    scanf("%d", &index);

    int *pointerArr = &*arr;
    int *pointerIndex = &index;
    int *pointerN = &n;
    printf("%d", sumValidNum(pointerArr, &index, &n));

//    printf("%d", sumValidNum(pointerArr, *pointerIndex, *pointerN));
//    neznam kako e po taman

    return 0;
}
