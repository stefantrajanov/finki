//
// Created by Stefan on 12/7/2022.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int compareNumber;
    scanf("%d", &compareNumber);

    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= compareNumber){
            index = i;
            break;
        }
    }

    for (int i = index; i < n; ++i) {
        if (arr[i] < compareNumber){
            int tempIndex = i;
            while (tempIndex != index){
                int temp = arr[tempIndex-1];
                arr[tempIndex-1] = arr[tempIndex];
                arr[tempIndex] = temp;
                tempIndex--;
            }
            index++;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

//    int newArray[100];
//    int counter = 0;
//    for (int i = 0; i < n; ++i) {
//        if (arr[i] < compareNumber){
//            newArray[counter] = arr[i];
//            printf("%d ", newArray[counter]);
//            counter++;
//        }
//    }
//
//    for (int i = 0; i < n; ++i) {
//        if (arr[i] >= compareNumber){
//            newArray[counter] = arr[i];
//            printf("%d ", newArray[counter]);
//            counter++;
//        }
//    }

    return 0;
}