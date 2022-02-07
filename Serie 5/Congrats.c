#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int array[n];
    int isLower = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] >= n) isLower = 0;
        sum += array[i];
    }
    
    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] < array[j]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    
    int result = 1;
    if (isLower != 1 || sum % 2 != 0 || (n > 1 && sum > (n * (n - 1)))) result = 0;
    else {
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (array[j] >= 1 && i != j) {
                    count++;
                    array[j] -= 1;
                }
            }
            
            if (count < array[i]) {
                result = 0;
                break;
            }
            
            array[i] = 0;
        }
    }
    
    if (result == 1) printf("YES");
    else printf("NO");

    return 0;
}