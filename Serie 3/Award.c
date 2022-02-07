#include <stdio.h>

int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) result *= a;
    
    return result;
}

int countDigits(int num) {
    int digits = 0;
    int i = 1;
    while (num % i != num) {
        digits++;
        
        i *= 10;
    }
    
    return digits;
}

int returnScore(int allScore, int questionNumber) {
    int theScore;
    int oneDigit = (allScore % power(10, questionNumber)) - (allScore % power(10, questionNumber - 1));
    if (questionNumber == 1) theScore = allScore % 10;
    else theScore = oneDigit / power(10, questionNumber - 1);
    
    return theScore;
}

int returnChocolate(int score, int questionNumber) {
    int result;
    result = score * power(2, questionNumber);
    
    return result;
}

int returnTotalChocolate(int allScore) {
    int digit = countDigits(allScore);
    int questionNumber = 1;
    int totalChocolate = 0;
    while (digit > 0) {
        totalChocolate += returnChocolate(returnScore(allScore, digit), questionNumber);
        
        questionNumber++;
        digit--;
    }

    return totalChocolate;
}

float returnChocolatesWeight(int totalChocolate) {
    return totalChocolate * 0.02;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int mostChocolate = 0;
    float chocolatesWights = 0;
    for (int i = 0; i < n; i++) {
        int allScore;
        scanf("%d", &allScore);
        
        int choclates = returnTotalChocolate(allScore);
        if (choclates > mostChocolate) mostChocolate = choclates;
        
        chocolatesWights += returnChocolatesWeight(choclates);
    }
    
    printf("%d\n%.2f", mostChocolate, chocolatesWights);
    
    return 0;
}