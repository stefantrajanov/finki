//
// Created by Stefan on 11/15/2022.
//
#include <stdio.h>

int main(){
    int lower;
    int upper;

    scanf("%d %d", &lower, &upper);

    for (int i = lower + 1; i <= upper; ++i) {
        long product = 1;
        for (int j = 1; j <= i; ++j) {
            product *= j;
        }

        printf("Faktoriel od %d e %ld\n", i, product);
    }

    return 0;
}