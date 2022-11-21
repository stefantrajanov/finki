//
// Created by Stefan on 11/12/2022.
//
#include <stdio.h>

int main(){
    int rows;
    int collums;

    scanf("%d %d",&rows, &collums);

    for (int i = 0; i < rows; ++i) {
        printf("\t\n");
        for (int j = 0; j < collums; ++j) {
            if((j > 0 && j < collums - 1) && (i != 0 && i != rows - 1)){
                printf("+");
            }
            else
            {
                printf(".");
            }

        }
    }

    return 0;
}