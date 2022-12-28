//
// Created by Stefan on 12/19/2022.
//
#include <stdio.h>

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void shiftElements(int *arr, int n){
    int switchIndex = n;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0){
            switchIndex = i;
            break;
        }
    }

    for (int i = switchIndex; i < n; ++i) {
        if (arr[i] >= 0){
            int temp = i;
            while (temp != switchIndex){
                swap(&arr[temp], &arr[temp-1]);
                temp--;
            }
            switchIndex++;
        }
    }
}


int main (){
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    shiftElements(arr,n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}