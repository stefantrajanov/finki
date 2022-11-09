//
// Created by Stefan on 11/8/2022.
//
#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);

    int fiveCounter = 0;
    int temp = number;

    int kolega = 0;
    int counter = 1;

    while(temp != 0){
        int digit = temp % 10;  // 5512 == 2  -- 551 == 1
                                // 6 * 100 + 12 == 612
                                // 6 * 1000 + 612 == 6612
        if (digit == 5){
            kolega += 6 * counter;
            fiveCounter++; // fiveCounter += 1
        }
        else{
            kolega += digit * counter;
        }

        counter *= 10;
        temp /= 10;
    }
    if (fiveCounter < 2){
        printf("Error");
        return 0;
    }

    float razlika = (float)number - (float)kolega;
    if (razlika < 0){
        razlika = -(razlika);
    }

    float procent = 100.0 * (razlika / (float)number);
    printf("%.4f%%", procent);

    return 0;
}