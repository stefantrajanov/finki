#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int isStepen(int num, int cNum, int counter){

    int temp = (int)(pow(num, counter));

    if(temp > cNum){
        return 0;
    }

    if (temp == cNum){
        return 1;
    }

    return isStepen(num,cNum,counter + 1);
}
// num  =  5 //
// cNum = 25 //

int main (){
    int num, compareNum;
    scanf("%d %d", &num ,&compareNum);

    if(isStepen(num, compareNum, 0)){
        printf("Da");
        return 0;
    }

    printf("Ne");
    return 0;
}
