#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int transformNum(int num){
    int sum = 0;
    for (int i = 1; num; i++) {
        if (i % 2 == 0) {
            int digit = num % 10;
            sum += pow(3, digit);
        }
        num /= 10;
    }
    return sum;
}

void printArray(int arr[], int n) {

    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

}

int main (){

    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[i] = transformNum(arr[i]);
    }

    printArray(arr,n);
    return 0;
}
