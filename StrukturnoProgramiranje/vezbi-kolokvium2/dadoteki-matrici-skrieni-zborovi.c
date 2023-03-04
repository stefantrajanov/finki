//
// Created by Stefan on 12/19/2022.
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

int convertStringToNumber(char *number){
    int length = (int)strlen(number);
    number[length - 1] = '\0';
    if (length - 1 == 1){
        return (number[0] - '0');
    }

    int realNumber;
    for (int i = 0; i < length - 1; ++i) {
        int digit = number[i] - '0';
        realNumber = (realNumber + digit) * 10;
    }

    realNumber /= 10;

    return realNumber;
} // problem here

void printMatrix(char matrix[50][50], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkIfItsTheWord(char matrix[50][50], int n, char *word, int row, int column, int *lastLetterRowPointer, int *lastLetterColumnPointer){
    int wordIndex = 0;
    int flag = 1;

    // check the right
    for (int j = column; j < strlen(word); ++j) {
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
    for (int j = column; wordIndex < strlen(word); --j) {
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
    for (int j = row; wordIndex < strlen(word); --j) {
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
    for (int j = row; wordIndex < strlen(word); ++j) {
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

int main(){
    wtf();
    // Your code starts here!
    FILE * filePointer = fopen("input.txt", "r");
    int counter = 0;

    char tempMatrix[5000];
    char nTemp[50];
    char word[50];
    int index = 0;

    while (!feof(filePointer)){
        if (counter == 0){
            fgets(nTemp, 100, filePointer);
            counter++;
            continue;
        }
        tempMatrix[index] = fgetc(filePointer);

        index++;
        counter++;
    }
    fclose(filePointer);
    scanf(" %s", &*word);

    char matrix[50][50];
    int n = convertStringToNumber(nTemp); // problem, N is not always a single digit, check in function
    printf("%d\n", n);

    int tempCounter = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tempMatrix[tempCounter] != ' ' && tempMatrix[tempCounter] != '\n'){
                matrix[i][j] = tempMatrix[tempCounter];
            }else{
                j--;
            }
            tempCounter++;
        }
    }
//    printMatrix(matrix,n);

    int lastLetterRow;
    int lastLetterColumn;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == word[0]){
                if (checkIfItsTheWord(
                          matrix,
                          n,
                          word,
                          i,
                          j,
                          &lastLetterRow,
                          &lastLetterColumn
                          )
                    ){
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