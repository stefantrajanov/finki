//
// Created by Stefan on 12/2/2022.
//
#include <stdio.h>
#include <string.h>
#define MAX 100

//ne menuvaj!
void wtf() {
    FILE *f = fopen("broevi.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int power(int base, int power){
    int product = 1;
    for (int i = 0; i < power; ++i) {
        product *= base;
    }

    return product;
}

int convertStringToNumber(char *string){
    int length = strlen(string);
    if (length == 1){
        return (*string - '0');
    };
    int number = 0;
    for (int i = 0; i < length; ++i) {
        int digit = (int)string[i] - '0';
        number = (number + digit) * 10;
    }
    number /= 10;

    return number;
}

int main()
{
    wtf();
    // vashiot kod ovde
    FILE *filePointer = fopen("broevi.txt", "r");
    char number[MAX];
    int range;
    int newLineFlag = 1;
    int counter = 0;

    int maxDigit = 0;
    int maxDigitNumber;


    while(!feof(filePointer)){
        fscanf(filePointer, "%100s", number);
        int length = (int)strlen(number);
        int realNumber = convertStringToNumber(number);

        if (newLineFlag){
            newLineFlag = 0;
            range = realNumber;
            continue;
        }
        int temp = realNumber / power(10,length-1);

        if (maxDigit < temp){
            maxDigit = temp;
            maxDigitNumber = realNumber;
        }

        counter++;
        if (counter == range){
            newLineFlag = 1;
            counter = 0;
            maxDigit = 0;
            printf("%d\n", maxDigitNumber);
        }
    }

    fclose(filePointer);
    return 0;
}