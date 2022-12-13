//
// Created by Stefan on 12/13/2022.
//
// da se promeni znakot na elementite od glavnata dijagonala
#include <stdio.h>

int main(){
    int n;
    int matrix[100][100];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j){
                matrix[i][j]*=(-1);
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}