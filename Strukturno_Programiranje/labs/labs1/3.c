/*
Од тастатура се внесуваат 5 позитивни цели броеви едно по друго. Да се испечати бројот на непарни броеви кој што се внесени.

For example:

Input	Result
1 2 3 4 5
3
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int counter = 0;

    for (int i = 0; i < 5; i++){
        scanf("%d", &number);
        if (number % 2 != 0){
            counter++;
        }
    }
    printf("%d", counter);

    return 0;
}