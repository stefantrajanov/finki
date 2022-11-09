//
// Created by Stefan on 11/8/2022.
//
#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);

    if (!(number % 3 == 0 || number % 5 == 0)){
        printf("Losh Broj");
        return 0;
    }
    if (number % 3 == 0 && number % 5 == 0){
        printf("Tik - Tak");
        return 0;
    }
    if (number % 3 == 0){
        printf("Tik");
        return 0;
    }
    if (number % 5 == 0){
        printf("Tak");
        return 0;
    }

    return 0;
}