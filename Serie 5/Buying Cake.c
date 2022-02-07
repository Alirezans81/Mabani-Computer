#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int result = -1;
    int prices[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
        if (prices[i] < result || result == -1) result = prices[i];
    }

    if (k == 2) {
        if (prices[0] < prices[n - 1]) result = prices[0];
        else result = prices[n - 1];
    }
    if (k < 2) {
        for (int i = 0; i < n; i++) {
            if (prices[i] > result) result = prices[i];
        }
    }
    
    if (n == 0 || k == 0) result = 0;
    printf("%d", result);
    
    return 0;
}