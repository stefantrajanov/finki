//
// Created by Stefan on 10/23/2022.
//

#include <stdio.h>

int evenSum(int number){
    int sum = 0;

    while(number){
        int digit = number % 10;

        if (digit % 2 == 0){
            sum += digit;
        }

        number /= 10;
    }

    return sum;
}

int oddSum(int number){
    int sum = 0;

    while(number){
        int digit = number % 10;

        if (digit % 2 != 0){
            sum += digit;
        }

        number /= 10;
    }

    return sum;
}

int main() {
    int number;
    int notALetter = 1;
    int evenCounter = 0;
    int oddCounter = 0;

    while(1){
        notALetter = scanf("%d", &number);
        if (!notALetter){
            break;
        }

        printf(" %d\n", evenSum(number));
        if (evenSum(number) > 5){
            evenCounter++;
        }
        printf(" %d\n", oddSum(number));
        if (oddSum(number) <= 5){
            oddCounter++;
        }
    }

    printf("Broevi so zbir pogolem od 5: %d\n", evenCounter);
    printf("Broevi so zbir pomal ili ednakov od 5: %d", oddCounter);
    return 0;
}