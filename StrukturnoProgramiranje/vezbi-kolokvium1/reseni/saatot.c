//
// Created by Stefan on 11/28/2022.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int hours;
    int minutes;
    int seconds;
    scanf("%d %d %d", &hours, &minutes, &seconds);
    if (hours == 12 && minutes == 0 && seconds == 0) {
        printf("%02d:%02d:%02dNOON", hours, minutes, seconds);
        return 0;
    }

    if (hours < 13){
        printf("%02d:%02d:%02dAM", abs(hours - 12),minutes,seconds);
    }
    else{
        printf("%02d:%02d:%02dPM", abs(hours - 12), minutes, seconds);
    }

    return 0;
}