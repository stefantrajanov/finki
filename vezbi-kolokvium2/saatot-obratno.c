//
// Created by Stefan on 11/29/2022.
//
//input: 10 59 59 A 10
//
#include <stdio.h>

int main(){
    int hours;
    int minutes;
    int seconds;
    char typeOfTime;

    scanf("%d %d %d %c",
          &hours,
          &minutes,
          &seconds,
          &typeOfTime);



    if (typeOfTime == 'A'){
        if (hours == 12 && minutes == 0 && seconds == 0){
            printf("%02d:%02d:%02dNOON",hours,minutes,seconds);
        }else {
            printf("%02d:%02d:%02dAM", hours, minutes, seconds);
        }
    }
    else{
        printf("%02d:%02d:%02dPM", hours + 12, minutes, seconds);
    }

    return 0;
}