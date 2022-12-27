//
// Created by Stefan on 12/15/2022.
//
#include <stdio.h>

int main (){
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int matrix[100][100];
    int vtorMatrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &vtorMatrix[i][j]);
        }
    }

    int counter = 0;
    int index = 0;
    int flag = 1;
    for (int i = 0; index < m; ++i) {

        for (int j = 0; j < n; ++j) {
            int elementPrva = matrix[j][index];
            int elementVtora = vtorMatrix[j][i];

            if (elementPrva != elementVtora){
                flag = 1;
                break;
            }
            flag = 0;
        }
        if (!flag){
            counter++;
        }
        if (i == m - 1){
            i = 0;
            index++;
        }
    }

    printf("%d", counter);

    return 0;
}