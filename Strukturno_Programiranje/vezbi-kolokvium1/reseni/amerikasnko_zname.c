//
// Created by Stefan on 11/12/2022.
//
#include <stdio.h>

int main(){
    int rows;
    int collums;

    scanf("%d %d", &rows, &collums);

    for (int i = 0; i < rows; ++i) {
        printf("\n");
        for (int j = 0; j < collums; ++j) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    printf(".");
                } else {
                    printf("*");
                }
            }else{
                if (j % 2 == 0) {
                    printf("*");
                } else {
                    printf(".");
                }
            }
        }
    }

    return 0;
}