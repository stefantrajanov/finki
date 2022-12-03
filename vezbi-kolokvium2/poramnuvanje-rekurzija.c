//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>

long tuneUp(int number){
    if(number == 0){
        return 0;
    }
    int digit = number % 10;
    if(digit == 9) {
        return (tuneUp(number / 10) + 7) * 10;
    }
    else{
        return (tuneUp(number / 10) + number % 10) * 10;
    }
}

int main(){
    int number;
    int arr[100];

    int index = 0;
    while (scanf("%d", &number)){
        int tunedUpNumber = tuneUp(number) / 10;
        if (!index){
            arr[index] = tunedUpNumber;
            index++;
            continue;
        }
        if (tunedUpNumber > arr[index - 1]){
            arr[index] = tunedUpNumber;
        }
        else{
            for (int i = index; i; --i) {
                if (tunedUpNumber > arr[i - 1]){
                    arr[i] = tunedUpNumber;
                    break;
                }
                int temp = arr[i - 1];
                arr[i - 1] = tunedUpNumber;
                arr[i] = temp;
            } // time complexity is (n(n-1)) / 2
        }
        index++;
    }

    if (index >= 5) {
        for (int i = 0; i < 5; ++i) {
            printf("%d ", arr[i]);
        }
        return 0;
    }

    for (int i = 0; i < index; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}