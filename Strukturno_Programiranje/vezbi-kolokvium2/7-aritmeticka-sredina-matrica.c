//
// Created by Stefan on 12/1/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int matrix[100][100];

    for (int i = 0; i < n; ++i) {
        float sum = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
            sum += (float)matrix[i][j];
        }
        float average = sum / (float)m;
        float value = (-5);
        int mostDistant;
        for (int j = 0; j < m; ++j) {
            if(value < fabsf(average - (float)matrix[i][j])){
                value = fabsf(average - (float)matrix[i][j]);
                mostDistant = matrix[i][j];
            }
        }
        printf("%d ", mostDistant);
    }

    return 0;
}