//
// Created by Stefan on 11/8/2022.
//
#include <stdio.h>

int main(){

// alternitive
//    int time;
//    int index = 1;
//    scanf("%d", &time);
//    int temp = time;
//    for (int i = 2; i <= 3; ++i) {
//        scanf("%d", &time);
//        if (time < temp){
//            index = i;
//            temp = time;
//        }
//    }
//
//    printf("%d", index);

    int time1, time2, time3;

    scanf("%d %d %d", &time1,&time2,&time3);

    int minIndex;
    if(time1 < time2 && time1 < time3){
        minIndex = 1;
        printf("%d", minIndex);
        return 0;
    }
    if(time2 < time1 && time2 < time3){
        minIndex = 2;
        printf("%d", minIndex);
        return 0;
    }

    minIndex = 3;
    printf("%d", minIndex);
    return 0;
}