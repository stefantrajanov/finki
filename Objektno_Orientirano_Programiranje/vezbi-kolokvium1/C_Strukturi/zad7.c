//
// Created by Stefan on 3/2/2023.
//
#include <stdio.h>
#include <string.h>

typedef struct {
    char rideName[105];
    int rideTime;
    float price;
    int hasStudentDiscount;

} Ride;

typedef struct {
    char name[105];
    char location[105];
    Ride rides[105];
    int numberOfRides;

} FunPark;

void printDetails(FunPark *funPark, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s %s\n", funPark[i].name, funPark[i].location);

        for (int j = 0; j < funPark[i].numberOfRides; ++j) {
            printf("%s %d %.2f\n", funPark[i].rides[j].rideName, funPark[i].rides[j].rideTime, funPark[i].rides[j]
            .price);
        }
    }
}

void bestPark(FunPark *funPark, int n) {
    int maxRidesIndex;
    int counterMax = 0;
    int maxTime = 0;
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        int currentTime = 0;
        for (int j = 0; j < funPark[i].numberOfRides; ++j) {
            if (funPark[i].rides[j].hasStudentDiscount){
                counter++;
            }
            currentTime += funPark[i].rides[j].rideTime;
        }
        if (counterMax < counter){
            counterMax = counter;
            maxRidesIndex = i;
            maxTime = currentTime;
        } else if (counterMax == counter){
            if (maxTime < currentTime){
                maxTime = currentTime;
                counterMax = counter;
                maxRidesIndex = i;
            }
        }
    }

    printf("Najdobar park: %s %s", funPark[maxRidesIndex].name, funPark[maxRidesIndex].location);
}

int main() {
    int i, j, n, broj;
    //kreiraj niza od maksimum 100 zabavni parkovi
    FunPark funPark[100];
    scanf("%d", &n);
    //citanje na podatocite
    for (i = 0; i < n; i++) {
        //ime na festivalot
        scanf("%s", funPark[i].name);
        //mesto
        scanf("%s", funPark[i].location);
        //broj na filmovi
        scanf("%d", &funPark[i].numberOfRides);

        for (j = 0; j < funPark[i].numberOfRides; j++) {
            scanf("%s", funPark[i].rides[j].rideName);            /* Ime na filmot */
            scanf("%d", &funPark[i].rides[j].rideTime);        /* Vremetraenje   */
            scanf("%f", &funPark[i].rides[j].price);    /* Cena */
            scanf("%d", &funPark[i].rides[j].hasStudentDiscount);    /* Popust */

        }


    }
    printDetails(funPark, n);
    bestPark(funPark, n);

    return 0;
}
