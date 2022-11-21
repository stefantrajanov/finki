//
// Created by Stefan on 11/21/2022.
//
#include <stdio.h>

int digitCounter(int number){
    int counter = 0;
    while (number){
        number /= 10;
        counter++;
    }

    return counter;
}


int main(){
    int requiredDigits;
    scanf("%d", &requiredDigits);

    printf("Dolzini: ");


    int number;
    int counter = 0;

    scanf("%d", &number);
    int lastNumber = number;

    while (scanf("%d", &number)){

        if (digitCounter(number) != requiredDigits){
            if (counter >= 2) {
                printf("%d ", counter);
                counter = 0;
            }
            lastNumber = number;
            continue;
        }

        if (number > lastNumber){
            counter++;
            lastNumber = number;
        }
        else{
            if (counter >= 2) {
                printf("%d ", counter);
                counter = 0;
            }
            lastNumber = number;
        }
    }
    if (counter >= 2) {
        printf("%d", counter);
    }
    return 0;
}
