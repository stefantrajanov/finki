//
// Created by Stefan on 12/27/2022.
//
#include <stdio.h>

void scale(float *arr, int n){
    float max = 0;
    for (int i = 0; i < n; ++i) {
        if (max < arr[i]){
            max = arr[i];
        }
    }

    float quotient = (float)100/max;

    for (int i = 0; i < n; ++i) {
        arr[i] *= quotient;
        printf("%.2f ", arr[i]);
    }
}

int main (){
    int n;
    float arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%f", &arr[i]);
    }
    scale(arr,n);

    return 0;
}