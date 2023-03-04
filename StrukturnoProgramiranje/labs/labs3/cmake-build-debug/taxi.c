//
// Created by Stefan on 11/8/2022.
//
#include <stdio.h>

int main(){
    int passedKm;
    scanf("%d", &passedKm);
    int price = 80;
    float bill = 0;

    for (int kilometers = 0; kilometers < passedKm; kilometers++) {
        if(kilometers > 5 && kilometers <= 8) {price = 20;}
        if(kilometers > 8) {price = 25;}
        bill += price;
    }

    if(passedKm > 5){
        bill *= 1.20;
    }

    printf("%f", bill);
    return 0;
}