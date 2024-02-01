//
// Created by Stefan on 10/23/2022.
//

#include <stdio.h>

int isValid(int number, int number2){
    if (number <= 0 || number2 <= 0){
        return 0;
    }
    return 1;
}

int main(){

    int number;
    int numberTwo;

    scanf("%d %d", &number, &numberTwo);

    if (!isValid(number,numberTwo)){
        printf("Invalid input");

        return 0;
    }

    if(numberTwo > number){
        int temp = number;
        number = numberTwo;
        numberTwo = temp;
    };

    for (int i = 1; number; i++) {
        if (i % 2 == 0){
            int digit = number % 10;
            int secondNumDigit = numberTwo % 10;
            if (digit != secondNumDigit){
                printf("NE");
                return 0;
            }
            numberTwo /= 10;
        }
        number /= 10;
    }

    printf("PAREN");
    return 0;
}