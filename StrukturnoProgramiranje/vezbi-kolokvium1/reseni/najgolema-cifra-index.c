//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int maxIndex(int number){
    int i = 0;
    int tempIndex;
    int max = 0;
    while(number){
        int digit = number % 10;
        if (digit > max){
            max = digit;
            tempIndex = i;
        }
        i++;
        number /= 10;
    }

    return tempIndex;
}

int main(){
    int number;
    int temp;
    int counter0 = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;

    temp = scanf("%d", &number);
    while(temp){
        if (maxIndex(number) == 0){counter0++;}
        if (maxIndex(number) == 1){counter1++;}
        if (maxIndex(number) == 2){counter2++;}
        if (maxIndex(number) == 3){counter3++;}
        if (maxIndex(number) == 4){counter4++;}

        temp = scanf("%d", &number);
    }

    printf("0: %d\n", counter0);
    printf("1: %d\n", counter1);
    printf("2: %d\n", counter2);
    printf("3: %d\n", counter3);
    printf("4: %d\n", counter4);


    return 0;
}