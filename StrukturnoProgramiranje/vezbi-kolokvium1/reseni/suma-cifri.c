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

int digitSum(int number){
    int sum = 0;
    for (int i = 0; number; ++i) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }

    return sum;
}

int oddDigitSum (int number){
    int sum = 0;
    for (int i = 1; number; ++i) {
        if(i % 2 != 0) {
            int digit = number % 10;
            sum += digit;
        }
        number /= 10;
    }

    return sum;
}

int main (){
    int number;
    int numberTwo;

    scanf("%d %d", &number, &numberTwo);

    if (!isValid(number,numberTwo)){
        printf("Invalid input");
        return 0;
    }

    if (number < numberTwo){
        int temp = number;
        number = numberTwo;
        numberTwo = temp;
    };

    if (oddDigitSum(number) == digitSum(numberTwo)){
        printf("\nista suma");
        return 0;
    }

    printf("NE");
    return 0;
}