#include <stdio.h>

int g(int n);
int f(int n)
{
    if(n <= 0)
        return 1;
    else
        return g(n - 1) * f( n - 2);
}
int g(int n)
{
    if(n <= 0)
        return 2;
    else
        return f(n - 2) + g(n - 3);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("f(%d) = %d\n", n, f(n));
    printf("g(%d) = %d\n", n, g(n));
    return 0;
}