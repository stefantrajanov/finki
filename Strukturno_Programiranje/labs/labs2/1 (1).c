#include <stdio.h>

int main(){

    int number;
    scanf("%d", &number);

    int temp = ((number > (-100)) && (number < 100)) || ((number >= 200) && (number < 300));
    printf("%d", temp);

    return 0;
}