//
// Created by Stefan on 11/15/2022.
//
#include <stdio.h>

int main(){

    int lower;
    int upper;
    scanf("%d %d", &lower, &upper);

    int sum = 0;
    for (int i = lower; i < upper; ++i) {
        if (i % 3 == 0){
            sum += i;
        }
    }

    printf("%d", sum);
    return 0;
}