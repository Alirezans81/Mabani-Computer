#include <stdio.h>

long int a = 0;
long int b = 0;
long int g = 0;

int multiply(int counter) {
    if (counter > 0) {
        long int a2 = (a * 3) + (b * 4);
        long int b2 = (a * 2) + (b * 4);
        long int g2 = (a * 1) + (g * 2);
    
        a += a2;
        b += b2;
        g += g2;
    
        return multiply(counter - 1);
    } else return 0;
}

int main()
{
    scanf("%ld %ld %ld", &a, &b, &g);
    int k;
    scanf("%d", &k);
    
    multiply(k);
    
    printf("%ld\n%ld\n%ld", a, b, g);

    return 0;
}