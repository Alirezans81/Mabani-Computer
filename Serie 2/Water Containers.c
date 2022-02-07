#include <stdio.h>

int main()
{
    float a, b, c;
    float vs[3];
    float ma = 0;
    
    scanf("%f %f %f", &a, &b, &c);
    
    vs[0] = a;
    vs[1] = b;
    vs[2] = c;
    
    for (int i = 0; i < 3; i++) {
        ma += vs[i];
    }
    ma /= 3;
    
    float forth;
    int deposit = 0, withdraw = 0;
    for (int i = 0; i < 3; i++) {
        float addition = vs[i] - ma;
        forth += addition;
        if (addition > 0) withdraw++;
        if (addition < 0) deposit++;
    }
    
    int difference = deposit - withdraw;
    int result = 0;
    if (deposit != 0 && withdraw != 0) {
        if (difference >= 0) result = difference + 1;
        if (difference < 0) result = ((difference * -1) + 1);
    }
    printf("%d", result);
    
    return 0;
}