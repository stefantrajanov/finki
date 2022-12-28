//
// Created by Stefan on 12/18/2022.
//
#include <stdio.h>

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
} // pointers to swap

void selectionSort(int *arr, int n){

    for (int i = 0; i < n - 1; ++i) {

        int min = i; // index of the minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]){
                min = j; // finding the minimum element of the array but not the value, its index
            }
        }

        if (min != i){
            swap(&arr[min], &arr[i]);
        }
    }
}

int numberShowsUpEvenTimes(int *arr, int n){
    int counter = 0;
    int lastElement = arr[0];

    for (int i = 0; i < n; ++i) {
        // 5 5 5 5 5
        counter = 0;
        int min = arr[i];
        if (lastElement == min && lastElement != arr[0]){
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (arr[j] == min){
                counter++;
            }
        }
        if (counter % 2 == 0){
            return min;
        }
        lastElement = min;
    }

    return 0;
}

int main (){
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    int result = numberShowsUpEvenTimes(arr, n);
    if (result){
        printf("Najmaliot element koj se pojavuva paren broj pati e %d", result);
    }else{
        printf("Nitu eden element ne se pojavuva paren broj pati!");
    }


    return 0;
}