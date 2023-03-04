//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int main(){
    int sum;
    int number;
    int numberTwo;
    int trueCounter = 0;
    int counter = 0;

    scanf("%d", &sum);

    scanf("%d %d", &number, &numberTwo);



    while (number || numberTwo){

        if(sum == (number + numberTwo)){
            trueCounter++;

        }

        counter++;
        scanf("%d %d", &number, &numberTwo);
    }

    float percent = ((float)trueCounter / (float)counter) * 100;

    printf("Vnesovte %d parovi od broevi chij zbir e %d\n"
           "Procentot na parovi so zbir %d e %.2f%%", trueCounter, sum, sum, percent);

    return 0;
}