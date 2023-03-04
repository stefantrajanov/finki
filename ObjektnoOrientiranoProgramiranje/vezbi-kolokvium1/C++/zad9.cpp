//
// Created by Stefan on 3/3/2023.
//
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct {
    char manufacturer[100];
    float monitorSize;
    int isTouch;
    int price;
} Laptop;

typedef struct {
    char name[102];
    char location[150];
    Laptop availableLaptops[100];
    int numberOfLaptops;

} ITStore;

int hasNonZeroDecimals(float num) {
    return (num - floor(num) != 0);
}

void print(ITStore *stores, int n) {
    for (int i = 0; i < n; ++i) {

        printf("%s %s\n", stores[i].name, stores[i].location);
        for (int j = 0; j < stores[i].numberOfLaptops; ++j) {

            if (hasNonZeroDecimals(stores[i].availableLaptops[j].monitorSize)) {
                printf("%s %.1f %d\n", stores[i].availableLaptops[j].manufacturer, stores[i].availableLaptops[j]
                        .monitorSize, stores[i].availableLaptops[j].price);
            } else {
                printf("%s %.0f %d\n", stores[i].availableLaptops[j].manufacturer, stores[i].availableLaptops[j]
                        .monitorSize, stores[i].availableLaptops[j].price);
            }
        }
    }
}


void findLeastExpensive(ITStore *stores, int n) {
    int min = 0;
    char storeName[100];
    char location[100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < stores[i].numberOfLaptops; ++j) {
            if (!min && stores[i].availableLaptops[j].isTouch) {
                min = stores[i].availableLaptops[j].price;
                strcpy(storeName, stores[i].name);
                strcpy(location, stores[i].location);
                continue;
            }

            if (min > stores[i].availableLaptops[j].price && stores[i].availableLaptops[j].isTouch) {
                min = stores[i].availableLaptops[j].price;
                strcpy(storeName, stores[i].name);
                strcpy(location, stores[i].location);
            }
        }
    }

    cout << "Najeftina ponuda ima prodavnicata:\n" << storeName << " " << location << endl;
    cout << "Najniskata cena iznesuva: " << min << endl;
}

int main() {
    ITStore stores[100];
    int n;
    scanf("%d", &n); //broj na IT prodavnici

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (int i = 0; i < n; ++i) {
        cin >> stores[i].name;
        cin >> stores[i].location;
        cin >> stores[i].numberOfLaptops;

        for (int j = 0; j < stores[i].numberOfLaptops; ++j) {
            cin >> stores[i].availableLaptops[j].manufacturer;
            cin >> stores[i].availableLaptops[j].monitorSize;
            cin >> stores[i].availableLaptops[j].isTouch;
            cin >> stores[i].availableLaptops[j].price;
        }
    }


    //pecatenje na site prodavnici




    //povik na glavnata metoda
    print(stores, n);
    findLeastExpensive(stores, n);

    return 0;
}