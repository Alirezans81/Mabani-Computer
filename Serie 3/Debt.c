#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    while (a % 10 == 0 && b % 10 == 0 && c % 10 == 0 && n % 10 == 0) {
        a /= 10;
        b /= 10;
        c /= 10;
        n /= 10;
    }
    
    int result = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            int tillNow = (i * a) + (j * b);
            if ((n - tillNow) % c == 0 && (n - tillNow) / c <= z && (n - tillNow) >= 0) {
                result++;
            }
        }
    }
    
    printf("%d", result);
    
    return 0;
}