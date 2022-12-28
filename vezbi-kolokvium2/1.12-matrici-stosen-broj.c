//
// Created by Stefan on 12/24/2022.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void wtf() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int checkNumberEqualGroup (int number1, int number2){

    return (number1 % 2 == 0) == (number2 % 2 == 0);
}

int main() {
    wtf();
    //vasiot kod ovde
    FILE * filePointer = fopen("matrica.txt", "r");

    int n; int m;
    fscanf(filePointer, "%d %d\n", &n, &m);

    int arr[100][100];
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        for (int j = 0; j < m; ++j) {
            fscanf(filePointer, "%d", &arr[i][j]);
            if (checkNumberEqualGroup(i+j, arr[i][j])){
                counter++;
            }
        }
        printf("%d: %d\n", i, counter);
    }
    fclose(filePointer);

    return 0;
}
