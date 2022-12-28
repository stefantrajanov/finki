//
// Created by Stefan on 12/2/2022.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int checkIfVowel(char letter){
    if (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'u' || letter == 'i'){
        return 1;
    }
    return 0;
}

int main() {
    writeToFile();
    char letter;

    // Vasiot kod zapocnuva od tuka
    FILE *filePointer = fopen("text.txt", "r");

    int flag = 1;
    char lastLetter;
    int counter = 0;

    while (!feof(filePointer)){
        letter = fgetc(filePointer);
        if (letter < 'Z' && letter >= 'A'){letter += 32;}
        if (flag){ flag = 0; lastLetter = letter;
            continue;}


        if (checkIfVowel(lastLetter) && checkIfVowel(letter)){
            printf("%c%c\n", lastLetter, letter);
            counter++;
        }
        lastLetter = letter;
    }

    printf("%d", counter);
    fclose(filePointer);

    return 0;
}
