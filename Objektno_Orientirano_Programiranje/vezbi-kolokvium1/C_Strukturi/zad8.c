#include <stdio.h>
#include <string.h>
#include <math.h>

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
            }else{
                printf("%s %.0f %d\n", stores[i].availableLaptops[j].manufacturer, stores[i].availableLaptops[j]
                        .monitorSize, stores[i].availableLaptops[j].price);
            }
        }
    }
}



void findLeastExpensive(ITStore *stores, int n){
    int min = 0;
    char storeName[100];
    char location[100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < stores[i].numberOfLaptops; ++j) {
            if (!min && stores[i].availableLaptops[j].isTouch){
                min = stores[i].availableLaptops[j].price;
                strcpy(storeName, stores[i].name);
                strcpy(location, stores[i].location);
                continue;
            }

            if (min > stores[i].availableLaptops[j].price && stores[i].availableLaptops[j].isTouch){
                min = stores[i].availableLaptops[j].price;
                strcpy(storeName, stores[i].name);
                strcpy(location, stores[i].location);
            }
        }
    }

    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", storeName, location);
    printf("Najniskata cena iznesuva: %d", min);
}

int main() {
    ITStore stores[100];
    int n;
    scanf("%d", &n); //broj na IT prodavnici

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (int i = 0; i < n; ++i) {
        scanf("%105s", stores[i].name);
        scanf("%s", stores[i].location);
        scanf("%d", &stores[i].numberOfLaptops);

        for (int j = 0; j < stores[i].numberOfLaptops; ++j) {
            scanf("%105s", stores[i].availableLaptops[j].manufacturer);
            scanf("%f", &stores[i].availableLaptops[j].monitorSize);
            scanf("%d", &stores[i].availableLaptops[j].isTouch);
            scanf("%d", &stores[i].availableLaptops[j].price);
        }
    }


    //pecatenje na site prodavnici




    //povik na glavnata metoda
    print(stores,n);
    findLeastExpensive(stores,n);

    return 0;
}