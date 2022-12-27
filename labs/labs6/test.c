//
// Created by Stefan on 12/8/2022.
//
#include <stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    int arr[100];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0){
            arr[i]++;
            printf("%d ", arr[i]);
        }else{
            if (arr[i] < 0){
                arr[i]++;
                printf("%d ", arr[i]);
            }else{
                arr[i]-=1;
                printf("%d ", arr[i]);
            }
        }
    }

    return 0;
}