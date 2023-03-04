//
// Created by Stefan on 11/29/2022.
//
// input: 3
// output:
// 1 1
// 12
// 21
// 123
// 321
#include <stdio.h>

int main (){
    int n;
    scanf("%d", &n);

    int counter = 1;
    for (int i = 0; counter != n + 1; ++i) {
        for (int j = 1; j <= counter; ++j) {
            printf("%d", j);
        }
        printf("\n");
        for (int j = counter; j; --j) {
            printf("%d", j);
        }
        printf("\n");
        counter++;
    }
    return 0;
}