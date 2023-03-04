//
// Created by Stefan on 11/21/2022.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int side1, side2, side3;
    int sum = 0;
    int indexLargest;

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &side1, &side2, &side3);
        if (side1 < (side2 + side3) && side2 < (side1 + side3) && side3 < (side2 + side1) ){
            printf("Moze\n");
            int temp = (side1+side2+side3);
            if (temp >= sum){
                sum = temp;
                indexLargest = i;
            }
        }
        else{
            printf("Ne moze\n");
        }
    }

    printf("Najgolem perimetar: %d, reden broj %d", sum, indexLargest);
    return 0;
}