//
// Created by Stefan on 11/29/2022.
//
#include <stdio.h>

int sortedNumber(int number){
    int lastDigit = number % 10;
    number /= 10;

    while (number){
        int digit = number % 10;
        if (lastDigit < digit){
            return 0;
        }
        lastDigit = digit;
        number /= 10;
    }

    return 1;
}

int main(){
    int n;
    scanf("%d", &n);

    int number;
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number);
        if (sortedNumber(number)){
            printf("%d\n", number);
            sum += number;
            counter++;
        }
    }
    printf("%d\n%d", sum, counter);
    return 0;
}