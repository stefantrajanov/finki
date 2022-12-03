//
// Created by Stefan on 11/29/2022.
//
#include <stdio.h>
#include <math.h>

float unstoppableFraction(float arr[],int n, int counter)
{
    if(counter == n-1)
    {
        if(n == 1)
        {
            return arr[counter];
        }
        return arr[counter];
    }
    return 1/unstoppableFraction(arr,n,counter+1)+arr[counter];
}
int main()
{
    int n;
    scanf("%d",&n);
    float arr[100];
    for(int i = 0;i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("%f", unstoppableFraction(arr,n,0));
    return 0;
}