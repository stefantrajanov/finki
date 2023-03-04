//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int main (){

    int m;

    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if(j == 0 || j == m - 1){
                printf("%%");
            }

            if ((j > 0 && j < m - 1) && (i != 0 && i != m - 1)){
                printf(".");
            }

            if ((j != 0 && j != m - 1)){
                if((i == m - 1 || i == 0)) {
                    printf("@");
                }
            }
        }
        printf("\n");
    }

    return 0;
}