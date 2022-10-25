//
// Created by Stefan on 10/25/2022.

// Полесно решение: на непарен и парен индекс смени го знакот
// Касно ми текна, ама и вака бива, тоа е.
// На следната со цик-цак е решено со парен и непарен
#include <stdio.h>

int ticTac (int number){
    if (number < 10){
        return 0;
    }
    while(number){
        int digit = number % 10;
        int digitTwo = (number / 10) % 10;
        int digitThree = (number / 100) % 10;

        if (digitThree) {
            if (!((digit < digitTwo && digitTwo > digitThree) || (digit > digitTwo && digitTwo < digitThree))) {
                return 0;
            }
        }else{
            if (digit > digitTwo || digit < digitTwo){
                return 1;
            }
            return 0;
        }
        number /= 10;
    }

    return 1;
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
}


int main(){
    int number;
    int temp;
    int arr[100];
    int length = 0;

    temp = scanf("%d", &number);
    while(temp){
        if (ticTac(number)){
            arr[length] = number;
            length++;
        }
        temp = scanf("%d", &number);
    }

    printArray(arr, length);

    return 0;
}