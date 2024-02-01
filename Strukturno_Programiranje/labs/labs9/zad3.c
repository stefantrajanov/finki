//
// Created by Stefan on 12/28/2022.
//
#include <stdio.h>

void swap(int *this, int *with){
    int temp = *this;
    *this = *with;
    *with = temp;
}

void sort(int *x, int *y, int *z){
    if (*y < *x)
        swap(x, y);

    if (*z < *y)
    {
        swap(y, z);
        if (*y < *x)
            swap(y, x);
    }

    swap(z,x);
}


int main (){

    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    sort(&a, &b, &c);

    printf("%d %d %d", a, b, c);

    return 0;
}