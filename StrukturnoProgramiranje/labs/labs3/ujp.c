//
// Created by Stefan on 11/9/2022.
//
#include <stdio.h>

int main(){
    float defaultPercent;       // procent 0
    float percentTwo;           // procent2
    float percentThree;         // procent3

    int floorOne; // prag1
    int floorTwo; // prag2

    int totalMoney; // site pari

    scanf("%f %d %f %d %f %d", &defaultPercent, &floorOne, &percentTwo, &floorTwo, &percentThree, &totalMoney);
    defaultPercent /= 100; percentTwo /= 100; percentThree /= 100; // pretvori gi vo realni procenti

    float taxValue = 0; // vkupniot danok

    if (totalMoney <= floorOne){ // ako parite se pomali od prviot prag
        taxValue += defaultPercent * (float)totalMoney; //  vkupniot danok se ednakvi na procent0 * site pari
    }
    else if (totalMoney > floorOne && totalMoney <= floorTwo){  // ako  vkupniot danok se izmegu prviot prag i vtoriot
        taxValue += defaultPercent * (float)floorOne;           //  vkupniot danok + procent0 * prviot prag
        taxValue += percentTwo * (float)(totalMoney - floorOne); // + procent2 * (site pari - prviot prag) ---> voa e za izrazime kolku kes ima izmegu pragovite
    }
    else{ // ako ne e prvoto i ne e vtoroto mora da bide voa
         taxValue += defaultPercent * (float)floorOne;      //  vkupniot danok + procent0 * prviot prag
         taxValue += percentTwo * (float)(floorTwo - floorOne); // + procent2 * (vtoriot prag - prviot prag)
         taxValue += percentThree * (float)(totalMoney - floorTwo); // + site pari minus vtoriot prag * procent3 ---> za da vidime kolku kes ima ostanato na krajot
    }

    printf("%.2f", taxValue); // ispecti go danokot


    return 0;
}

//10 1000 20 2500 30 3800
//