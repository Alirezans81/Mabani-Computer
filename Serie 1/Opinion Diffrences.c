#include <stdio.h>

int main() {
    
    int m1, d1 ,m2 ,d2;
    
    scanf("%d %d", &m1, &d1);
    scanf("%d %d", &m2, &d2);
    
    int first_passed_days;
    int second_passed_days;
    
    if (m1 > 6) {
        first_passed_days = 6*31 + (m1 - 7)*30;
    } else {
        first_passed_days = (m1 - 1)*31;
    }
    first_passed_days += d1;
    
    if (m2 > 6) {
        second_passed_days = 6*31 + (m2 - 7)*30;
    } else {
        second_passed_days = (m2 - 1)*31;
    }
    second_passed_days += d2;
    
    int result = first_passed_days - second_passed_days;
    
    if (result < 0) {
        result = -1*result;
    }
    
    printf("%d", result);
    
    return 0;
}