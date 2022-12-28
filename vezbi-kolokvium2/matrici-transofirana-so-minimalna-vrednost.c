//
// Created by Stefan on 12/18/2022.
//
#include <stdio.h>

void printFile() {
    FILE *f=fopen("matrica.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main (){
    int m,n;
    scanf("%d %d", &m, &n);

    int row;
    int column;
    scanf("%d %d", &row, &column);

    int arr[100][100];
    int flag = 1;
    int min;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
            if (flag){
                flag = 0;
                min = arr[i][j];
            }
            int currentElement = arr[i][j];
            if (min > currentElement){
                min = currentElement;
            }
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            arr[i][j] = min;
        }
    }

//    FILE * filePointer = fopen("matrica.txt", "w");
//
//    int number;
//    int i=0,j=0;
//    while (!feof(filePointer)){
//        number = arr[i][j];
//        fputc(number, filePointer);
//        i++; j++;
//    }
//    fclose(filePointer);
//
//    printFile();
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}