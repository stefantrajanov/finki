//
// Created by Stefan on 12/19/2022.
//
#include <stdio.h>
#include <string.h>

int wordCount (char *str){
    int length = (int)strlen(str);

    int counter = 0;
    int trueCounter = 0;
    for (int i = 0; i < length; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            counter++;
        }else{
            if (counter <= 3 && counter >= 1){
                trueCounter++;
            }
            counter = 0;
        }
    }

    return trueCounter;
}

int main(){
    char sentence[100];

    char maxSentence[100];
    int flag = 1;
    int max = 0;
    while (fgets(sentence, 100, stdin)){
        int length = (int)strlen(sentence);
        sentence[length-1] = '\0';

        int words = wordCount(sentence);

        if (max < words){
            max = words;
            strcpy(maxSentence,sentence);
        }
    }
    printf("%d: %s", max, maxSentence);

    return 0;
}