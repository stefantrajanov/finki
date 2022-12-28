//
// Created by Stefan on 12/24/2022.
//
#include <stdio.h>
#include <math.h>

#define MAX 50

void printFile() {

    FILE *f=fopen("output.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

void wtf(){
    FILE *f=fopen("input.txt","w");

    int row,column,i,j;
    float el;
    scanf("%d %d", &row, &column);

    fprintf(f,"%d %d\n",row, column);

    for (i=0; i<row; ++i){
        for (j=0; j<column; ++j){
            scanf("%f", &el);
            fprintf(f, "%.2f ", el);
        }
        fputc('\n',f);
    }
    fclose(f);

    return;
}

float twistedNumber (float arr[100][100], int i, int j, int n, int m){
    int divider = 9;
    if ((i == 0 || i == n-1) && (j == 0 || j == m - 1)){
        divider = 4;
    }else if ( ((i > 0 && i < n - 1) && (j == 0 || j == m - 1))
    || ( (i == 0 && i == n - 1) && (j > 0 && j < m - 1)) ) {
        divider = 6;
    }else{
        divider = 9;
    }

    float sum = (arr[i][j] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j] + arr[i-1][j] + arr[i+1][j+1]+ arr[i-1][j-1] + arr[i-1][j+1]+ arr[i+1][j-1]) / divider;

    return sum;
}

int main(){
    wtf();
    // Your code starts here!
    FILE * filePointer = fopen("input.txt", "r");

    int n; int m;
    fscanf(filePointer,"%d %d\n", &n, &m);

    float arr[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(filePointer, "%f", &arr[i][j]);
        }
    }
    fclose(filePointer);

    int firstRow; int firstColumn;
    int secondRow; int secondColumn;
    scanf("%d %d", &firstRow, &firstColumn);
    scanf("%d %d", &secondRow, &secondColumn);

    float newArr[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i >= firstRow && i <= secondRow && j >= firstColumn && j <= secondColumn){
                newArr[i][j] = twistedNumber(arr, i, j, n, m);
                printf("%.2f ", newArr[i][j]);
            }else{
                newArr[i][j] = arr[i][j];
                printf("%.2f ", arr[i][j]);
            }
        }
        printf("\n");
    }
    // Your code ends here!
//    printFile();

    return 0;
}
