//
// Created by Stefan on 11/29/2022.
//
#include <stdio.h>

int BrojPozitivni(int niza[], int n){
    if (n == 0){
        if (niza[n] > 0){
            return 1;
        }
        return 0;
    }
    if (niza[n] > 0){
        return BrojPozitivni(niza, n - 1) + 1;
    }
    else{
        return BrojPozitivni(niza, n - 1);
    }
}

int main (){
    int n;
    int arr[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("%d", BrojPozitivni(arr, n - 1));

    return 0;
}