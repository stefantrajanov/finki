//
// Created by Stefan on 12/3/2022.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();

    char string[100];
    char lastString[100] = "#";
    int arr[100];

    FILE * filePointer = fopen("input.txt", "r");

    while(!feof(filePointer)){
        fgets(string, 100, filePointer);
        if (strcmp(lastString,string) == 0){
            break;
        }
        int arrayLength = 0;
        int flag = 1;
        for (int i = 0; i < strlen(string); ++i) {
            if (string[i] >= '0' && string[i] <= '9'){
                int digit = string[i] - '0';

                if (flag){
                    flag = 0;
                    arr[arrayLength] = digit;
                    arrayLength++;
                    continue;
                }
                if (digit >= arr[arrayLength-1]){
                    arr[arrayLength] = digit;
                }
                else{
                    for (int j = arrayLength; j; --j) {
                        if (digit > arr[j - 1]){
                            arr[j] = digit;
                            break;
                        }
                        int temp = arr[j - 1];
                        arr[j - 1] = digit;
                        arr[j] = temp;
                    }
                }
                arrayLength++;
            }
        }
        printf("%d:", arrayLength);
        for (int i = 0; i < arrayLength; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
        strcpy(lastString, string);
    }

    fclose(filePointer);
    return 0;
}
