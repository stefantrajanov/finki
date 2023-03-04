//
// Created by Stefan on 11/29/2022.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if (n > 100000){
        return 0;
    }

    int number;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number);
        switch (number % 5) {
            case 0:
                printf("-----"); break;
            case 1:
                printf(".----"); break;
            case 2:
                printf("..---"); break;
            case 3:
                printf("...--"); break;
            case 4:
                printf("....-"); break;
        }
    }
    return 0;
}