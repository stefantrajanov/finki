//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>


int maxDigit(int number){
    int max = 0;
    while(number){
        int digit = number % 10;
        if (digit > max){
            max = digit;
        }
        number /= 10;
    }

    return max;
}

int digitSum(int number){
    int sum = 0;
    while(number){
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }

    return sum;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i == 0){
            printf("%d: %d\n", arr[i], digitSum(arr[i]));
            continue;
        }
        printf("%d: %d\n", arr[i], digitSum(arr[i]) + maxDigit(arr[i-1]));
    }
}


int main(){
    int number;
    int arr[1000];
    int length = 0;

    while(scanf("%d", &number)){
        arr[length] = number;
        length++;
    }

    printArray(arr,length);

    return 0;
}