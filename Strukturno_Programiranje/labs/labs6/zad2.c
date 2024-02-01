//
// Created by Stefan on 12/7/2022.
//
#include <stdio.h>

int findNumOfSortedElements(int matrix[100][100], int i, int n){
    int counter = 0;
    int lastElement = matrix[i][0];

    int temp = 1;
    for (int j = 1; j < n; ++j) {
        int currentElement = matrix[i][j];
        if (lastElement < currentElement) {
            temp++;
        }
        else {
            if (counter < temp) {
                counter = temp;
                temp = 1;
            }
        }
        lastElement = currentElement;
    }

    if (counter < temp){
        counter = temp;
    }

    if (counter == 1){
        return 0;
    }

    return counter;
}

int main (){
    int n;
    scanf("%d", &n);

    int matrix[100][100];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int lengthOfSorted = 1;
    for (int i = 0; i < n; ++i) {
        int currentLength = findNumOfSortedElements(matrix, i, n);
        if (lengthOfSorted < currentLength){
            lengthOfSorted = currentLength;
        }
    }

    printf("%d", lengthOfSorted);

    return 0;
}