#include <stdio.h>
int main ()
{
    int broj, posledenBroj,cifra, opagjackiBroj,suma=0, temp;
    int flag;

    while(scanf("%d", &broj))
    {
        flag = 1;
        temp=broj;
        posledenBroj=temp%10;
        temp/=10;
        while(temp>0)
        {
            cifra = temp%10;
            if(posledenBroj >= cifra)
            {
                flag = 0;
                break;
            }

            posledenBroj = cifra;
            temp/=10;

        }

        if (flag != 0){
            suma += broj;
        }
    }
    if(suma!=0)
    {
        printf("%d", suma);
    }
    else
    {
        printf("NEMA");
    }


}