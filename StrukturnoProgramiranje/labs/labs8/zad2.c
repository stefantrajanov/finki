//
// Created by Stefan on 12/21/2022.
//
#include <stdio.h>

int reverseNumber(int number){
    int reversedNumber = 0;

    while (number){
        int digit = number % 10;
        reversedNumber = (reversedNumber * 10) + digit;
        number /=10;
    }

    return reversedNumber;
}

int isPalindrome(int number){
    if (reverseNumber(number) == number) {
        return 1;
    }

    return 0;
}

int containsDigit(int number){
    if (!number){
        return 1;
    }
    int digit = number % 10;
    if (digit > 4){
        return 0;
    }
    return containsDigit(number / 10);
}

int main() {
    int lower;
    int upper;
    scanf("%d %d", &lower,&upper);

    for (int number = lower; number < upper; ++number) {
        if (isPalindrome(number) && containsDigit(number)){
            printf("%d\n", number);
        }
    }

    return 0;
}
