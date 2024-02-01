//
// Created by Stefan on 11/29/2022.
//
#include <stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    printf("*\n");

    int counter = 2;
    for (int i = 1; counter != n + 1; ++i) {
        printf("|");
        for (int j = 0; j < counter; ++j) {
            if (i % 2 == 0){
                printf("*");
            }
            else{
                break;
            }
        }
        if (i % 2 == 0){
            counter++;
        }
        printf("\n");
    }

    return 0;
}