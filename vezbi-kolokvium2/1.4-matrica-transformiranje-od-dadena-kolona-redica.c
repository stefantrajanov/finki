//
// Created by Stefan on 12/24/2022.
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

void printMatrix (int arr[100][100], int m, int n){
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main (){
    int m; int n;
    scanf("%d %d", &m,&n);

    int transformRow; int transformCol;
    scanf("%d %d", &transformRow,&transformCol);


    int arr[100][100];
    int flag = 1;
    int min;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
            if (flag){ min = arr[i][j]; flag = 0; }

            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }
    }

    for (int i = 0; i < transformRow; ++i) {
        for (int j = 0; j < transformCol; ++j) {
            arr[i][j] = min;
        }
    }

    FILE * filePointer = fopen("matrica.txt", "w");

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fprintf(filePointer, "%d ", arr[i][j]);
        }
        fprintf(filePointer, "%c", '\n');
    }

    fclose(filePointer);
    printFile();
    return 0;
}
