//
// Created by Stefan on 11/21/2022.
//
#include <stdio.h>

int main(){
    char letter;
    int counter = 0;
    char lastLetter;
    int sequenceCounter = 0;

    while(scanf(" %c", &letter)){
        counter++;
        if (letter < 'a' || letter > 'z'){
            break;
        }
        if (counter == 1){
            lastLetter = letter;
            continue;
        }

        if ((int)letter == (int)lastLetter + 1){
            lastLetter = letter;
            continue;
        }
        sequenceCounter++;

        int letterCounter = 0;
        if (lastLetter < letter) {
            for (int i = lastLetter + 1; i < letter; ++i) {
                printf("%c", i);
                letterCounter++;
            }
        }
        else{
            for (int i =  letter + 1; i < lastLetter; ++i) {
                printf("%c", i);
                letterCounter++;
            }
        }
        //a b c d e f g h i j k l m n o p q r s t u v w x y z
        printf(" %d\n", letterCounter);

        lastLetter = letter;
    }

    printf("%d", sequenceCounter);

    return 0;
}