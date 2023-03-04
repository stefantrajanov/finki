#include <stdio.h>
#include <string.h>


typedef struct {
    char code[50];
    int price;
    int availableProducts;

} Product;

typedef struct {
    char name[50];
    int numberOfOrders;
    Product products[100];
    int howManyProductsOrdered[100];
} Order;


void swap(Product *p1, Product *p2) {
    Product temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void selectionSort(Product *products, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (strcmp(products[i].code, products[i + 1].code) > 0) {
                swap(&products[i], &products[i + 1]);
            }
        }
    }
}


void printFaktura(Order order) {
    printf("Faktura za %s\n", order.name);

    for (int i = 0; i < order.numberOfOrders; ++i) {
        if (order.products[i].availableProducts < order.howManyProductsOrdered[i]) {
            printf("Fakturata ne moze da se izgotvi");
            return;
        }
    }

    int total = 0;
    for (int i = 0; i < order.numberOfOrders; ++i) {
        int currentSum = 0;
        currentSum = order.products[i].price * order.howManyProductsOrdered[i];

        printf("%s %d %d %d\n", order.products[i].code, order.products[i].price, order.howManyProductsOrdered[i],
               currentSum);

        total += currentSum;
    }

    printf("Vkupnata suma na fakturata e %d", total);

}

int main() {

    Order narachka;

    // внеси го името лицето кое ја прави нарачката
    scanf("%100s", narachka.name);
    // внеси го бројот на порачани производи во нарачката
    scanf("%d", &narachka.numberOfOrders);

    int i;
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.numberOfOrders; ++i) {
        // внеси код
        scanf("%100s", narachka.products[i].code);
        // внеси единицчна цена
        scanf("%d", &narachka.products[i].price);
        // внеси број на производи во магацин
        scanf("%d", &narachka.products[i].availableProducts);
    }
    //за секој производ се внесува колку такви производи се порачани во нарачката
    int j;
    for (j = 0; j < narachka.numberOfOrders; ++j) {
        //се внесува број на производи во нарачката
        scanf("%d", &narachka.howManyProductsOrdered[j]);
    }



    // повик на функцијата pecatiFaktura
    selectionSort(narachka.products, narachka.numberOfOrders);
    printFaktura(narachka);

    return 0;
}