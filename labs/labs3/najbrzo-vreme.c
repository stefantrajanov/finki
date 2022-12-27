//
// Created by Stefan on 11/8/2022.
//
#include <stdio.h>

int main(){

    float first;
    float second;
    float third;

    scanf("%f %f %f", &first, &second, &third);

    if (first <= second && first <= third)
    {
        printf("1");
    }
    if (second <= first && second <= third)
    {
        printf("2");
    }
    if (third <= second && third <= first)
    {
        printf("3");
    }

    return 0;
}