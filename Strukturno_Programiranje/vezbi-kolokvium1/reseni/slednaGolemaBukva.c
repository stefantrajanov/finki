//
// Created by Stefan on 11/28/2022.
//
// input: igraat
// output: igrAat
#include <stdio.h>

int main(){
    char letter;

    scanf(" %c", &letter);
    char lastLetter = letter;

    while (scanf("%c", &letter)){
        if (letter == '.'){
            printf("%c.", lastLetter);
            break;
        }
        if (lastLetter == letter){
            printf("%c", lastLetter - 32);
        }
        else{
            printf("%c", lastLetter);
        }

        lastLetter = letter;
    }

    return 0;
}