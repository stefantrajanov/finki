//
// Created by Stefan on 11/28/2022.
//
#include <stdio.h>

int main(){
    // first
    int x,y;
    // second
    int x1,y1;
    scanf("%d%d%d%d", &x, &y, &x1, &y1);

    // input coordinates;
    int coordinateX;
    int coordinateY;

    for (int i = 0; i < 2; ++i) {
        scanf("%d%d", &coordinateX, &coordinateY);
        if (coordinateX > x && coordinateX < x1){
            if (coordinateY == y || coordinateY == y1){
                printf("DA\n");
                continue;
            }
            printf("NE\n");
            continue;
        } else if (coordinateX == x || coordinateX == x1){
            if (coordinateY >= y && coordinateY <= y1){
                printf("DA\n");
                continue;
            }
            printf("NE\n");
            continue;
        }else{
            printf("NE\n");
        }
    }


    return 0;
}