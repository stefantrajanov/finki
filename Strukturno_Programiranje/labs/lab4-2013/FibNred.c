#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int getFibNumber(const int *arr, int tier, int i){
    int temp = 0;
    for (int j = 1; j <= tier; j++) {
        temp += arr[i - j];
    }

    return temp;
}

int main (){
    int n;
    int tier;
    int fibNumber;
    int arr[100];

    scanf("%d %d", &n ,&tier);

    for (int i = 0; i < n; ++i) {
        if(i > tier - 1) {
            fibNumber = getFibNumber(arr,tier,i);
            arr[i] = fibNumber;
            printf("%d ", fibNumber);
        } else
        {
            printf("%d ", 1);
            arr[i] = 1;
        }
    }

    return 0;
}
