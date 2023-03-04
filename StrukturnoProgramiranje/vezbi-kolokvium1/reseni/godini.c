//
// Created by Stefan on 11/21/2022.
//
#include <stdio.h>

int main(){
    int date;
    scanf("%d", &date);

    int days = date / 1000000;
    int months = (date / 10000) % 100;
    int year = date % 10000;

    //12 11 2003
    //01 11 2021

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int compareDate;
        scanf("%d", &compareDate);
        int compareDays = compareDate / 1000000;
        int comapareMonths = (compareDate / 10000) % 100;
        int compareYear = compareDate % 10000;

        if (year - compareYear < 18){
            printf("NE");
            continue;
        }
        if ((months - comapareMonths) < 0){
            printf("NE");
            continue;
        }
        if ((days - compareDays) < 0){
            printf("NE");
            continue;
        }

        printf("DA");
    }

    return 0;
}