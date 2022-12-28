//
// Created by Stefan on 12/15/2022.
//
#include <stdio.h>
#include <string.h>

int specialCharCheck(char *sentence){
    int length = (int)strlen(sentence);
    int counter = 0;
    int index;

    for (int i = 0; i < length; ++i) {
        if (
        (sentence[i] >= '!' && sentence[i] <= '/')
        ||
        (sentence[i] >= ':' && sentence[i] <= '@')
        ||
        (sentence[i] >= 92  && sentence[i] <= '_') // 92 = '\'
        ){
            counter++;
            index = i;
        }

        if (counter == 2){
            return 1;
        }
    }

    if (counter == 1){
        if ((length-1) / 2 == index){
            return 1;
        }
    }


    return 0;
}

int checkIfPalindrome(char *sentence){
    int length = (int)strlen(sentence);

    if (length == 1){
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        if (sentence[i] != sentence[length - 1]){
            return 0;
        }
        length--;
    }

    return 1;
}


int main (){
    int n;
    scanf("%d", &n);

    char sentence[100];
    char longestSentence[100];
    int longestLength = 0;

    for (int i = 0; i <= n; ++i) {
        fgets(sentence, 100, stdin);
        int length = (int) strlen(sentence);
        sentence[length - 1] = '\0';
        if (longestLength >= length){
            continue;
        }

        if (!specialCharCheck(sentence)){
            continue;
        }
        if (checkIfPalindrome(sentence)){

            longestLength = length;
            strcpy(longestSentence, sentence);
        }

    }

    if (!longestLength) {
        printf("Nema!");
        return 0;
    }
    printf("%s", longestSentence);

    return 0;
}