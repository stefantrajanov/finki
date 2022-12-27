//
// Created by Stefan on 12/13/2022.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n % 2 != 0){
        printf("GRESKA");
        return 0;
    }
    int arr[100][100];

    int sumCorners = 0;
    int sumBetweenCorners = 0;
    int sumInside = 0;
    int sumBetweenCornersVertical = 0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);

            if ((j == 0 || j == n - 1) && (i == 0 || i == n - 1) ){
                sumCorners += arr[i][j];
            }else if((i == 0 || i == n - 1) && (j > 0 && j < n - 1)){
                sumBetweenCorners += arr[i][j];
            }
            else if ((j > 0 && j < n - 1) && (i != 0 && i != n - 1)){
                sumInside += arr[i][j];
            }else{
                sumBetweenCornersVertical += arr[i][j];
            }
        }
    }

    printf("%d %d\n%d %d", sumCorners, sumBetweenCorners, sumBetweenCornersVertical, sumInside);

    return 0;
}