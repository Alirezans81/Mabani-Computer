#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    int theArray[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &theArray[i][j]);
        }
    }
    
    int answerArray[n];
    for (int i = 0; i < n; i++) {
        answerArray[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answerArray[i] += theArray[i][j];
        }
    }
    
    int answerFinalArray[n];
    for (int i = 0; i < n; i++) {
        answerFinalArray[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        int isAlreadyIn = 0;
        for (int j = 0; j < n; j++) {
            if (answerArray[i] == answerFinalArray[j]) isAlreadyIn = 1;
        }
        if (isAlreadyIn == 0) answerFinalArray[i] = answerArray[i];
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (answerFinalArray[i] >= 0) result++;
    }
    
    printf("%d", result);
    
    return 0;
}