//
// Created by Stefan on 12/28/2022.
//
#include <stdio.h>

int money(int n){
    if (n == 5 || n == 2 || n == 1 || !n){
        return 1;
    }

    if (n > 5){
        return money(n - 5) + 1;
    }else{
        return money(n - 2) + 1;
    }

}

int main (){
    int n;
    scanf("%d", &n);
    printf("%d", money(n));
    return 0;
}