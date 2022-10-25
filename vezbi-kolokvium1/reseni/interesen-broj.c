
#include <stdio.h>

int reverseNum(int number){
    int temp = 0;
    int counter = 0;
    while(number){
        int digit = number % 10;
        temp += digit;
        temp *= 10;
        number /= 10;
        counter++;
    }

    temp += counter;
    return temp;
}


int main (){
    int number;

    scanf("%d", &number);

    if (number < 9){
        printf("Brojot ne e validen");
        return 0;
    }

    for (int i = number - 1;  i; i--) {
        int reversedNumber = reverseNum(i);
        int numOfDigit = reversedNumber % 10;
        reversedNumber /= 10;

        if (reversedNumber % numOfDigit == 0){
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}