//
// Created by Stefan on 12/7/2022.
//
#include <stdio.h>
#include <math.h>

int combineNums(int number1, int number2){

    int combinedNumber = (number1*10) + number2;
    return combinedNumber;
};

int checkIfPrimeNumber(int number){

    for (int i = 2; i < sqrt(number); ++i) {
        if (number % i == 0){
            return 0;
        }
    }

    return 1;
}

int main (){
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int lastElement;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0){
            lastElement = arr[i];
            if (n % 2 != 0 && i == n - 1) {
               int combinedNumber = arr[i];
                if (checkIfPrimeNumber(combinedNumber)) {
                    printf("brojot %d e prost\n", combinedNumber);
                } else {
                    printf("brojot %d NE e prost\n", combinedNumber);
                }

            }
        }else {
            int currentElement = arr[i];
            int combinedNumber = combineNums(lastElement, currentElement);

            if (checkIfPrimeNumber(combinedNumber)) {
                printf("brojot %d e prost\n", combinedNumber);
            } else {
                printf("brojot %d NE e prost\n", combinedNumber);
            }

        }
    }

    return 0;
}