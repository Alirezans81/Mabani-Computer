#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int amount = 0;
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        scanf ("%d", &amount);
        if (amount > result) result = amount;
    }
    
    printf("%d", result);

    return 0;
}