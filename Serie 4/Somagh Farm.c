#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int condition1 = 0;
    for (int i = 0; i < n; i++) {
        int checkCondition = 1;
        int backup1 = a[0];
        for (int j = 0; j < i; j++) {
            if (a[j] >= backup1) backup1 = a[j];
            else checkCondition = 0;
        }
        int backup2 = a[i] + 1;
        for (int j = i; j < n; j++) {
            if (a[j] < backup2) backup2 = a[j];
            else checkCondition = 0;
        }
        if (checkCondition == 1) condition1 = 1;
    }
    
    int condition2 = 0;
    for (int i = 0; i < n; i++) {
        int checkCondition = 1;
        int backup1 = a[0];
        for (int j = 0; j < i; j++) {
            if (a[j] <= backup1) backup1 = a[j];
            else checkCondition = 0;
        }
        int backup2 = a[i] - 1;
        for (int j = i; j < n; j++) {
            if (a[j] > backup2) backup2 = a[j];
            else checkCondition = 0;
        }
        if (checkCondition == 1) condition2 = 1;
    }
    
    if (condition1 == 1 || condition2 == 1) printf("Yes");
    else printf("No");

    return 0;
}