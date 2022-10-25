//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>
void printArray(int arr[], int n, int lower, int upper){
    for (int i = 0; i < n; ++i) {
        if(arr[i] >= lower && arr[i] <= upper) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main (){
    int n;
    int arr[1000];
    int droppedCounter = 0;
    int droppedSum = 0;
    int passedCounter = 0;
    int passedSum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] < 50){
            droppedCounter++;
            droppedSum += arr[i];
        }else{
            passedCounter++;
            passedSum += arr[i];
        }
    }
    float averageDropped = (float)droppedSum / (float)droppedCounter;
    printf("Sredna vrednost na padnati %.2f\n", averageDropped);
    printArray(arr, n, 0, 49);


    float averagePassed = (float)passedSum / (float)passedCounter;
    printf("Sredna vrednost na polozeni %.2f\n", averagePassed);
    printArray(arr, n, 50, 100);





    return 0;
}