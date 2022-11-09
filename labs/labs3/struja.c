#include <stdio.h>

int main() {
//     float price;
//     int usedElec;
//     int bill;
//     if(usedElec < 500) {price = 5.0};
//     if ((usedElec > 500) && (usedElec < 750)) {price = 7.5};
//     if ( ( usedElec > 750 )&& (usedElec < 1050) ) {price = 11.0};
//     if (usedElec > 1050) {price = 13.5};
//
//     out of loop
//
//     if (bill < 7000) {bill *= 1.10};
//     else {bill *= 1.18}



    int usedElec;
    float bill = 0.0;
    float price = 5.0;

    scanf("%d", &usedElec);

    for (int electricity = 0; electricity < usedElec; electricity++) {
//        if(usedElec <= 500) {price = 5;}
        if ( (electricity >= 500) && (electricity < 650) ) {price = 7.5;}
        if ( (electricity >= 650) && (electricity < 850) ) {price = 11.0;}
        if (  electricity >= 850) {price = 13.5;}
        bill += price;
    }

    if (bill <= 7000) {
        bill *= 1.10;
    }
    else {
        bill *= 1.18;
    }

    printf("%.2f", bill);
    return 0;
}
