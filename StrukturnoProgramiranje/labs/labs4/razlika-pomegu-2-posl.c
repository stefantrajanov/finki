
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int number;

    int max = 0;

    scanf("%d", &number);
    int lastNum = number;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &number);
        int temp = number - lastNum;

        if (abs(temp) > max){
            max = temp;
        }

        lastNum = number;
    }

    printf("%d", max);

    return 0;
}
