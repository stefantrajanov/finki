//
// Created by Stefan on 11/8/2022.
//
#include <stdio.h>

int fiveSwitch(int number){
    int newNumber = 0;
    int counter = 1;
    int fiveCounter = 0;

    while(number){
        int digit = number % 10;
        if (digit == 5){
            newNumber += 6 * counter;
            fiveCounter++;
        }
        else {
            newNumber += digit * counter;
        }
            counter *= 10;
            number /= 10;

    }

    if (fiveCounter < 2){
        return 0;
    }

    return newNumber;
}

int main(){
    int number;
    scanf("%d", &number);

    int switched = fiveSwitch(number);
    if (!switched){
        return 0;
    }
    float diffrence = (float)number - (float)switched;
    if (diffrence < 0){diffrence = -(diffrence);}

    float percent = 100.0 * ((float)diffrence / (float)number) ;
    printf("%.4f%%", percent);


    return 0;
}
