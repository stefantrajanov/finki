//
// Created by Stefan on 12/24/2022.
//
#include <stdio.h>
#include <string.h>

void wtf(){
    FILE *f=fopen("input.txt","w");

    int n,i,j;
    char el;
    scanf("%d", &n);

    fprintf(f,"%d\n",n);
    char a = getchar();

    for (i=0; i < n; ++i){
        for (j=0; j < n; ++j){
            el = getchar();
            getchar();
            fprintf(f, "%c  ", el);
        }
        fputc('\n',f);
    }
    fclose(f);

    return;
}

void printMatrix(char arr[100][100], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int checkIfItsTheWord(char matrix[50][50], int n, char *word, int row, int column, int *lastLetterRowPointer, int *lastLetterColumnPointer){
    int wordIndex = 0;
    int flag = 1;
    int length = (int)strlen(word);

    // check the right
    for (int j = column; j < length; ++j) {
        if (matrix[row][j] != word[wordIndex]){
            flag = 0;
            break;
        }
        *lastLetterRowPointer = row;
        *lastLetterColumnPointer = j;
        wordIndex++;
    }
    if (flag){return 1;} else {flag = 1; wordIndex = 0;}

    // check the left
    for (int j = column; wordIndex < length; --j) {
        if (matrix[row][j] != word[wordIndex]){
            flag = 0;
            break;
        }
        *lastLetterRowPointer = row;
        *lastLetterColumnPointer = j;
        wordIndex++;
    }
    if (flag){return 1;} else {flag = 1; wordIndex = 0;}

    // check vertically up
    for (int j = row; wordIndex < length; --j) {
        if (matrix[j][column] != word[wordIndex]){
            flag = 0;
            break;
        }
        *lastLetterRowPointer = j;
        *lastLetterColumnPointer = column;
        wordIndex++;
    }
    if (flag){return 1;} else {flag = 1; wordIndex = 0;}

    // check vertically down
    for (int j = row; wordIndex < length; ++j) {
        if (matrix[j][column] != word[wordIndex]){
            flag = 0;
            break;
        }
        *lastLetterRowPointer = j;
        *lastLetterColumnPointer = column;
        wordIndex++;
    }

    if (flag){return 1;} else {flag = 1; wordIndex = 0;}

    return 0;
}

int main (){
    wtf();
    FILE * filePointer = fopen("input.txt", "r");

    int n;
    fscanf(filePointer, "%d\n", &n);

    char arr[50][50];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(filePointer, " %c", &arr[i][j]);
        }
    }

    char word[100];
    scanf("%100s", word);

    fclose(filePointer);

    int lastLetterRow;
    int lastLetterColumn;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == word[0]){
                if (checkIfItsTheWord(
                        arr,
                        n,
                        word,
                        i,
                        j,
                        &lastLetterRow,
                        &lastLetterColumn))
                {
                    printf("%d, %d -> %d, %d", i,j,lastLetterRow,lastLetterColumn);
                    return 0;
                }
            }
        }
    }

    printf("Not Found");
    // Your code ends here!
    return 0;
}
// if the first element is equal to first LETTER of the word then check left right up down
// code works, only n is not always a single digit
