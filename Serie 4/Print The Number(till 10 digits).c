#include <stdio.h>

long long power(long long a, long long b) {
    long long result = 1;
    
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    
    return result;
}

long countDigits(long long theNumber) {
    long result = 0;
    
    long long i = 10;
    while (theNumber % i != theNumber) {
        result++;
        i *= 10;
    }
    result++;
    
    return result;
}

int main()
{
    long long theNumber = 0;
    scanf("%lld", &theNumber);
    
    long long digits = countDigits(theNumber);
    long long figuresArray[digits];
    for (long long i = 0; i < digits; i++) {
        int theFigure = (theNumber % power(10, digits - i)) - (theNumber % power(10, digits - i - 1));
        theFigure /= power(10, digits - i - 1);
        
        figuresArray[i] = theFigure;
    }
    
    for (long long i = 0; i < digits; i++) {
        printf("%lld: ", figuresArray[i]);
        
        for (long long j = 0; j < figuresArray[i]; j++) {
            printf("%lld", figuresArray[i]);
        }
        
        printf("\n");
    }

    return 0;
}