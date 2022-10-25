//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int convertToDecimal(char hex){
    int value;
    if (hex == ' ' || hex == '\n'){
        return 0;
    }
    if (hex >= '0' && hex <= '9'){
        value = hex - 48;
    }
    else if (hex >= 'a' && hex <= 'f'){
        value = hex - 97 + 10;
    }
    else if (hex >= 'A' && hex <= 'F'){
        value = hex - 65 + 10;
    }

    return value;
}

int main(){
    char hex;
    int sum = 0;

    hex = getchar();
    while (hex != '.'){
       int decimal = convertToDecimal(hex);
       sum += decimal;
       hex = getchar();
    }
    if (sum % 16 == 0){
        int digit = sum % 10;
        int digit2 = (sum/10) % 10;

        if (digit == 6 && digit2 == 1){
            printf("Poln pogodok");
            return 0;
        }

        printf("Pogodok");
        return 0;
    }

    printf("%d", sum);
    return 0;
}
