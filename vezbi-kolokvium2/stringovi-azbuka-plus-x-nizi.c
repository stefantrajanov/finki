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

int main(){
    int n;
    int shift;
    scanf("%d %d", &n, &shift);
    char sentence[100];
    int length = 0;
    char flag = 1;

    for (int j = 0; j < n; ++j) {
        length = 0;
        flag = 1;
        for (int i = 0; flag != '\n'; ++i) {
            scanf("%s", &*sentence); // grabs string (word)
            scanf("%c", &flag); // grabs the thing next to the word, most likely blank space or \n
            length = strlen(sentence);
            printSentence(sentence,length,shift);
            printf(" ");
        }
        printf("\n");
//        if (flag){ flag = 0; continue;}
    }


//a b c d e f g h i j k l m n o p q r s t u v w x y z
// shift = 10;
// s == c
//
    return 0;
}