//Да се прочитаат два цели броеви од тастатура и на екран да се испечатат нивните сума и производ.
//
//For example:
//
//Input	Result
//5 6	11
//	    30

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int numberTwo;

    scanf("%d %d", &number, &numberTwo);

    printf("%d\n", number+numberTwo);
    printf("%d", number*numberTwo);
    return 0;
}
