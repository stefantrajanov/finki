//
// Created by Stefan on 12/3/2022.
//
#include <stdio.h>
#include <string.h>
// ne menuvaj ovde
void wtf() {
    FILE *f = fopen("dat.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    // vasiot kod ovde
    FILE * filePointer = fopen("dat.txt", "r");
    char longestString[100];
    int maxLength = 0;

    while (!feof(filePointer)){
        char string[100];
        fgets(string, 100, filePointer);

        int length = (int)strlen(string);
        int counter = 0;

        for (int i = 0; i < length; ++i) {
            if (string[i] >= '0' && string[i] <= '9'){
                counter++;
            }
            if (counter >= 2){
                if(maxLength <= length){
                    maxLength = length;
                    strcpy(longestString, string);
                }
                break;
            }
        }
    }

    int firstNumberIndex;
    for (int i = 0; i < maxLength; ++i) {
        if (longestString[i] >= '0' && longestString[i] <= '9'){
            firstNumberIndex = i;
            break;
        }
    }
    int lastNumberIndex;
    for (int i = maxLength; i; --i) {
        if (longestString[i] >= '0' && longestString[i] <= '9'){
            lastNumberIndex = i;
            break;
        }
    }

    for (int i = firstNumberIndex; i <= lastNumberIndex; ++i) {
        printf("%c", longestString[i]);
    }

    fclose(filePointer);

    return 0;
}