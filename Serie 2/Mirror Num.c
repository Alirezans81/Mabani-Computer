#include <stdio.h>

int main()
{
    long int n;
    scanf("%ld", &n);
    
    long int t = 0;
    long int i = 1;
    do {
        if (n != 0) t++;
        
        i *= 10;
    } while (n % i != n);
    
    int numbers[t];
    
    i = 10;
    for (int j = 0; j < t; j++) {
        
        if ( j == 0) {
            numbers[j] = n % 10;   
        }else {
            numbers[j] = ((n % i) - (n % (i / 10))) / (i / 10);
        }
        
        i *= 10;
    }

    int result = 1;
    long int r1 = 0, r2 = t - 1;
    while (r1 <= r2) {
        if (numbers[r1] != numbers[r2]) result = 0;
    
        r1++;
        r2--;
    }
    
    if (result == 1) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}