//
// Created by Stefan on 12/3/2022.
//
#include <stdio.h>
#include <string.h>
// ne menuvaj ovde
void wtf() {
    FILE *f = fopen("podatoci.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int findCharIndex(char *string, char symbol){
    int length = (int)strlen(string);

    for (int i = 0; i < length; ++i) {
        if (string[i] == symbol){
            return i;
        }
    }

    return 0;
}

int main() {
    wtf();
    char ignoreFirstSpace;
    char firstSymbol;
    char secondSymbol;
    scanf("%c%c%c", &ignoreFirstSpace, &firstSymbol, &secondSymbol);

    FILE * filePointer = fopen("podatoci.txt", "r");
    char string[100];

    char lastString[100] = "#";

    while (!feof(filePointer)){
        fgets(string, 100, filePointer);
        int firstSymbolIndex = findCharIndex(string, firstSymbol);
        int length = (int)strlen(string);

        if (strcmp(lastString,string) == 0){
            break;
        }

        for (int i = firstSymbolIndex + 1; i < length; ++i) {
            if (string[i] == secondSymbol){
                break;
            }
            printf("%c", string[i]);
        }

        printf("\n");
        strcpy(lastString,string);
    }

    fclose(filePointer);
    return 0;
}