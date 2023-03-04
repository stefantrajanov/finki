/*Да се напише програма која за петцифрен број внесен од стандарден влез ќе ја пресмета сумата на цифрите на парните и непарните позиции соодветно.

Напомена: Последната цифра во бројот се наоѓа на 0-та позиција. 

Појаснување: За бројот 54321 цифрата на 0-та позиција е 1, додека цифрата на 4-та позиција е 5.*/

/*Input	Result
  54321
  Sumata na cifrite na parnite pozicii e 9
  Sumata na cifrite na neparnite pozicii e 6 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int evenSum = 0;
    int oddSum = 0;

    scanf("%d", &number);

    int index = 0;
    while(number){
        int digit = number % 10;
        if (index % 2 == 0){
            evenSum += digit;
        }
        else{
            oddSum += digit;
        }

        index++;
        number /= 10;
    }

    printf("Sumata na cifrite na parnite pozicii e %d\n", evenSum);
    printf("Sumata na cifrite na neparnite pozicii e %d", oddSum);
    return 0;
}
