#include <stdio.h>

int main(){

    int money;
    scanf("%d", &money);

    for (int i = 0; i < 5; ++i) {
        int transaction;
        scanf("%d", &transaction);
        money += transaction;
    }

    printf("%d", money > 0);
    return 0;
}