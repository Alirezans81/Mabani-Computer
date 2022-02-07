#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int numbers[n];
    int theNumber;
    int result = 0;
    
    for (int i = 0; i < n && result != 1; i++) {
        scanf("%d", &theNumber);
        if (theNumber % 2 != 0) numbers[i] = theNumber;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (numbers[j] == numbers[i] + 2) {
                for (int k = 0; k < n; k++) {
                    if (numbers[k] == numbers[i] + 4) {
                        result = 1;
                        k = n;
                        j = n;
                        i = n;
                    }
                }
            }
        }
    }
    
    printf("%d", result);

    return 0;
}