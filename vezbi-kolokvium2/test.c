//
// Created by Stefan on 11/30/2022.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// caesar's cypher;
void printSentence(char sentence[100], int length, int shift){
    for (int i = 0; i < length; ++i) {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {

            if (sentence[i] >= 'a' && sentence [i] <= 'z'){
                int temp = (sentence[i] + shift - 97) % 26 + 97;
                printf("%c", temp);
            }
            else{
                int temp = (sentence[i] + shift - 65) % 26 + 65;
                printf("%c", temp);
            }
        }
        else{
            printf("%c", sentence[i]);
        }
    }
}

// printing array function
void printArray(int arr[100][100], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int temp = arr[j][i];
            printf("%d ", temp);
        }

        printf("\n");
    }
}

// convert string to number function from file or anything.
int convertStringToNumber(char *string){
    int length = strlen(string);
    if (length == 1){
        return (*string - '0');
    };
    int number = 0;
    for (int i = 0; i < length; ++i) {
        int digit = (int)string[i] - '0';
        number = (number + digit) * 10;
    }
    number /= 10;

    return number;
}

int power(int base, int power){
    int product = 1;
    for (int i = 0; i < power; ++i) {
        product *= base;
    }

    return product;
}

void print_ASCI_code(int length){
    char code = 0;

    for (int i = 0; i < length; ++i) {
        printf("%c ", code);
        code++;
    }
}

// bubble sort layout
int bubbleSort(int flag, int arrayLength, char *string, int *arr, int digit){
    if (flag){
        flag = 0;
        arr[arrayLength] = digit;
        arrayLength++;
    }
    if (digit >= arr[arrayLength-1]){
        arr[arrayLength] = digit;
    }
    else{
        for (int j = arrayLength; j; --j) {
            if (digit > arr[j - 1]){
                arr[j] = digit;
                break;
            }
            int temp = arr[j - 1];
            arr[j - 1] = digit;
            arr[j] = temp;
        }
    }
    arrayLength++;

    return 0
}

/// DONT DELETE UPPER CODE
int main(){
    print_ASCI_code(127);
    return 0;
}