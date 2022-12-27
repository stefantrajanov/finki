#include <stdio.h>

int isDescending(int number){
    int testDigit = number % 10;
    number /= 10;
    while(number){
        int digit = number % 10;
        if (testDigit >= digit){
            return 0;
        }

        testDigit = digit;
        number /= 10;
    }

    return 1;
}

int main() {
    int number;
    int sum = 0;

    while(scanf("%d", &number)){
        if (isDescending(number)){
            sum += number;
        }
    }
    if (!sum){
        printf("NEMA");
        return 0;
    }

    printf("%d", sum);
    return 0;
}