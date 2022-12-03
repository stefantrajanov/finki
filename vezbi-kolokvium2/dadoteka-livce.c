//
// Created by Stefan on 12/2/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ne menuvaj ovde
void wf() {
    FILE *f = fopen("livce.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int convertStringToNumber (char *string){
    int length = (int)strlen(string);
    if (length == 1){
        return *string - '0';
    }

    int convertedNumber = 0;
    for (int i = 0; i < length; ++i) {
        int digit = (int)string[i] - '0';
        convertedNumber = (convertedNumber + digit) * 10;
    }

    convertedNumber /=10;

    return convertedNumber;
}


int main() {
    wf();
    // vasiot kod pocnuva od ovde
    FILE * filePointer = fopen("livce.txt", "r");
    char string[100];


    int bet = 0;
    char highestBetCode[100];

    int highestTip;
    float highestCof = 0;

    int counter = 0;
    float multiplier = 1;

    while(!feof(filePointer)){
        fscanf(filePointer, "%10s", string);
        if (!bet){
            bet = convertStringToNumber(string);
            continue;
        }
        counter++;

        char currentBetCode[100];
        int currentTip;
        float currentCof;

        if (counter == 1){
            strcpy(currentBetCode, string);
        }
        if (counter == 2){
            currentTip = convertStringToNumber(string);
        }
        if (counter == 3){
            currentCof = atof(string);
            multiplier *= currentCof;
            counter = 0;

            if (highestCof < currentCof){
                highestCof = currentCof;
                strcpy(highestBetCode, currentBetCode);
                highestTip = currentTip;
            }
        }
    }
    multiplier *= (float)bet;

    printf("%s %d %.2f\n%.2f", highestBetCode, highestTip, highestCof, multiplier);
    return 0;

}