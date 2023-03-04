//
// Created by Stefan on 10/23/2022.
//
#include <stdio.h>
#include <ctype.h>

int evenSum(int number){
    int sum = 0;

    for (int i = 1; number; i++) {
        if (i % 2 == 0){
            int digit = number % 10;
            sum += digit;
        }

        number /= 10;
    }

    return sum;
};

int oddSum(int number){
    int sum = 0;

    for (int i = 1; number; i++) {
        if (i % 2 != 0){
            int digit = number % 10;
            sum += digit;
        }

        number /= 10;
    }

    return sum;
};

int main(){
    int number;
    int notALetter = scanf("%d", &number);
    int smallEvenSum = number;
    int bigOddSum = number;

    while(1){
        notALetter = scanf("%d", &number);
        if (!notALetter){
            break;
        }

        if (evenSum(number) <= evenSum(smallEvenSum)){
            smallEvenSum = number;

        }

        if (oddSum(number) >= oddSum(bigOddSum)){
            bigOddSum = number;
        }
    }

    printf("%d %d", smallEvenSum, bigOddSum);

    return 0;
}