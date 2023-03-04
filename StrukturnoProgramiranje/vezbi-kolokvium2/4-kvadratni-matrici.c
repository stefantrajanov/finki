//
// Created by Stefan on 12/1/2022.
//
#include <stdio.h>

int main (){
    int n;
    int m;
    scanf("%d %d", &n , &m);

    int matrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int i;
    int j;
    scanf("%d %d", &i, &j);

    int sumFirstQuadrant = 0;
    int sumSecondQuadrant = 0;
    int sumThirdQuadrant = 0;
    int sumFourthQuadrant = 0;

    for (int mI = 0; mI < n; ++mI) {
        for (int mJ = 0; mJ < m; ++mJ) {
            if (mJ >= j && mI >= i){
                sumFourthQuadrant+= matrix[mI][mJ];
            }
            if (mJ < j && mI >= i){
                sumThirdQuadrant+= matrix[mI][mJ];
            }
            if (mJ >= j && mI < i){
                sumSecondQuadrant+= matrix[mI][mJ];
            }
            if (mJ < j && mI < i){
                sumFirstQuadrant+= matrix[mI][mJ];
            }
        }
    }
    printf("%d %d %d %d",
           sumSecondQuadrant,
           sumFirstQuadrant,
           sumThirdQuadrant,
           sumFourthQuadrant);

    return 0;
}