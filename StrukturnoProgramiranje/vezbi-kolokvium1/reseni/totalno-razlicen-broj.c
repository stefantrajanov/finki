//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int main (){
    int upper;
    int number;
    int temp;
    int rememberNum;

    scanf("%d %d", &upper, &number);
    upper--;
    temp = upper;
    rememberNum = number;
    while (1){
        if (upper == 0){
            printf("%d", temp);
            return 0;
        }

        int digit = upper % 10;
        number = rememberNum;
        while(number){
            int compareNumber = number % 10;
            if (digit == compareNumber){
                break;
            }
            number /= 10;
        }
        if (number == 0){
            upper /= 10;
        }
        else{
            //upper-- == #torko
            temp--;
            upper = temp;
        }
    }
    return 0;
}