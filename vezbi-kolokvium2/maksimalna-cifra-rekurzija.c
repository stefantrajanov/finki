//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>

int findMaxDigit(int number, int maxDigit){
    if (number == 0){
        return maxDigit;
    }
    if (maxDigit < number % 10){
        maxDigit = number % 10;
        return findMaxDigit(number/10, maxDigit);
    }else{
        return findMaxDigit(number/10,maxDigit);
    }
}

int main(){
    int number;

    while (scanf("%d", &number)){
        printf("%d\n", findMaxDigit(number,0));
    }

    return 0;
}