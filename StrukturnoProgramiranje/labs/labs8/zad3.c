//
// Created by Stefan on 12/19/2022.
//
#include <stdio.h>

int divisibleByK(int number, int k){
    return (number % k == 0);
}

int nextDivisibleByK(int number, int k){
    if (number == k){ number++;}
    if (divisibleByK(number,k)){
        return number;
    }
    return nextDivisibleByK(number+1,k);
}

int main() {

    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);

    for (int i = a; i <= b; i++) {
        printf("%d -> %d\n", i, nextDivisibleByK(i, k));
    }

    return 0;
}