#include <stdio.h>

int main()
{
    float hour, minute;
    
    scanf("%f %f", &hour , &minute);
    
    hour= hour*30 + minute/2;
    minute= minute*6;
    
    float result = hour - minute;
    
    if (result < 0) result = -1 * result;
    if (result > 180) result = 360 - result;
    
    printf("%.1f", result);

    return 0;
}