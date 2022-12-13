//
// Created by Stefan on 12/7/2022.
//
#include <stdio.h>

int main (){
    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (i % 2 != 0){
            arr[i]+=1;
            printf("%d ", arr[i]);
        }else{
            arr[i]-=1;
            printf("%d ", arr[i]);
        }
    }

    return 0;
}