//
// Created by Stefan on 12/21/2022.
//
#include <stdio.h>

void printStars(int n){
    if (n == 1){
        printf("*");
        return;
    }
    printf("*");

    return printStars(n-1);
}

void form(int n){
    if (n == 1){
        printf("*");
        return;
    }

    printStars(n);
    printf("\n");

    return form(n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    form(n);
}
