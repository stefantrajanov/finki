#include<stdio.h>
int divisibleByK(int n, int k)
{
    if(n%k == 0) {
        return 1;
    }
    return 0;
}
int nextDivisibleByK(int n, int k)
{
    if(divisibleByK(n, k)) {10
        return n;
    }
    return nextDivisibleByK(n+1, k);
}
int main()
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    for(int i=a;i<=b;i++)
    {
        printf("%d -> %d\n", i, nextDivisibleByK(i+1 ,k));
    }
    return 0;
}