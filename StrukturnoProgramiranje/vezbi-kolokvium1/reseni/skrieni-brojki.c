#include <stdio.h>

int main(){

    char hiddenNumber;
    int sum = 0;
    int temp = 0;

    while((hiddenNumber = getchar()) != '!')
    {
        if(hiddenNumber >= '0'&&hiddenNumber <= '9')
        {
            temp = (temp*10) + hiddenNumber - '0';
        }
        else
        {
            sum = sum + temp;
            temp = 0;
        }
    }
    printf("%d", sum + temp);
    return 0;
}