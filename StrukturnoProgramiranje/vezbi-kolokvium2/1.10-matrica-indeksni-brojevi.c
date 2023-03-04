//
// Created by Stefan on 12/24/2022.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void wtf() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

void printMatrix (int arr[100][100], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int numberOfDigits(int number){
    if (number == 0){return 1;}
    return log10(abs(number))+1;
}

int combineNumbers(int number1, int number2){
    int digitsSecond = numberOfDigits(number2);

    int digits;

    digits = digitsSecond;

    int combinedNumber = (int)(number1 * pow(10, digits)) + number2;

    return combinedNumber;
    // 1 1 == 11
    // 1*10 + 1 == 11

    // 12 12 == 1212
    // 12 * 100 = 1200
    // 1200 + 12 = 1212
}


int isIndexNumber(int combinedNumber, int matrixNumber){
    if (combinedNumber == matrixNumber){
        return 1;
    }
    return 0;
}

int main() {
    wtf();
    //vasiot kod ovde
    FILE * filePointer = fopen("matrica.txt", "r");
    int n; int m;
    fscanf(filePointer, "%d %d\n", &n, &m);

    int arr[120][120];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(filePointer, "%d", &arr[i][j]);
        }
    }
    fclose(filePointer);

    for (int i = 0; i < m; ++i) {
        int counter = 0;
        for (int j = 0; j < n; ++j) {
            int combinedIndexes = combineNumbers(j, i);
            int test = arr[j][i];
//            printf("%d ", combinedIndexes);
            if (isIndexNumber(combinedIndexes, test)){
                counter++;
            }
        }
        printf("%d\n", counter);
    }


    return 0;
}
