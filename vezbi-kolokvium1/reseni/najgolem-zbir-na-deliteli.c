#include <stdio.h>

int main(){
    int number;
    int maxSum = 0;
    int biggest;
    int sum;

    scanf("%d", &number);

    for (int i = 0;  i < number; i++) {
        sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0){
                sum += j;
            }
        }
        if (sum > maxSum){
            maxSum = sum;
            biggest = i;
        }
    }

    printf("%d", biggest);

    return 0;
}