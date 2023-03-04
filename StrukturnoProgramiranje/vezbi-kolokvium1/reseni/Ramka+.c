#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void printMatrix(char arr[100][100], int n, int m){
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%c\t", arr[i][j]);
        }
    }
}

int main (){
    int n;
    int m;
    char arr[100][100];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                arr[i][j] = '+';
            }
            else {
                arr[i][j] = '-';
            }
        }
    }

    printMatrix(arr,n,m);



    return 0;
}
