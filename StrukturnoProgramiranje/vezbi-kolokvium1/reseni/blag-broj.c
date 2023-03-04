
#include <stdio.h>

int main (){
    int lower;
    int upper;
    scanf("%d %d", &lower,&upper);

    for (int i = lower; i <= upper; ++i) {
        int temp = i;
        while(temp){
            int digit = temp % 10;
            if (digit % 2 != 0){
                break;
            }
            temp /= 10;
        }
        if (temp == 0){
            printf("%d", i);
            return 0;
        }
    }

    printf("NE");
    return 0;
}