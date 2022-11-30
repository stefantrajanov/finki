//
// Created by Stefan on 11/28/2022.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int numberOfSeasons;
        scanf("%d", &numberOfSeasons);

        switch (numberOfSeasons % 4) {
            case 0:
                printf("leto"); break;
            case 1:
                printf("esen"); break;
            case 2:
                printf("zima"); break;
            case 3:
                printf("prolet"); break;
        }
    }

    return 0;
}