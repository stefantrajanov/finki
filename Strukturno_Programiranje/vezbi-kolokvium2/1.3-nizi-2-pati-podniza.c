//
// Created by Stefan on 12/18/2022.
//
#include <stdio.h>
#include <string.h>

int checkForSubString(const char *string, int index){
    char subString[5] = "a1c";
    int subStringIndex = 0;
    for (int i = index; i < index + 3; ++i) {
        if (string[i] != subString[subStringIndex]){
            return 0;
        }

        subStringIndex++;
    }

    return 1;
}

int main (){
    int n;
    scanf("%d", &n);

    char string[100];

    for (int i = 0; i <= n; ++i) {
        fgets(string, 100, stdin);
        int length = (int)strlen(string);
        string[length - 1] = '\0';
        int counter = 0;

        for (int j = 0; j < length; ++j) {
            if (string[j] >= 'A' && string[j] <= 'Z'){
                string[j]+= 32;
            }
        }

        for (int j = 0; j < length; ++j) {
            if (string[j] == 'a'){
//                char test = string[j];
                if (checkForSubString(string,j)){
                    counter++;
                }
            }
        }
        if (counter >= 2){
            printf("%s\n", string);
        }
    }

    return 0;
}