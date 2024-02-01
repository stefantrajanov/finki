//
// Created by Stefan on 10/25/2022.
//
#include <stdio.h>

int Tic(int number){
    if (number < 10){
        return 0;
    }

    int index = 1;

    while(number){
        int digit = number % 10;

        if (index % 2 != 0){
            if (!(digit < 5)){
                return 0;
            }
        }
        else{
            if ( !(digit >= 5) ){
                return 0;
            }
        }

        index++;
        number /= 10;
    }

    return 1;
}

int Tac(int number){
    if (number < 10){
        return 0;
    }
    int index = 1;

    while(number){
        int digit = number % 10;

        if (index % 2 != 0){
            if (!(digit >= 5)){
                return 0;
            }
        }
        else{
            if (!(digit < 5)){
                return 0;
            }
        }

        index++;
        number /= 10;
    }

    return 1;
}

int ticTac(int tic, int tac){
    if (tic || tac){
        return 1;
    }
    return 0;
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
}


int main(){
    int number;
    int temp;
    int arr[100];
    int length = 0;

    temp = scanf("%d", &number);
    while(temp){
        if (ticTac(Tic(number), Tac(number))){
            arr[length] = number;
            length++;
        }
        temp = scanf("%d", &number);
    }

    printArray(arr, length);

    return 0;
}