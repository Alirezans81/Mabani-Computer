#include <stdio.h>

int main()
{
    int carsSpeeds[100];
    for (int i = 0; i < 100; i++) {
        scanf("%d", &carsSpeeds[i]);
    }
    
    int miangin = 0;
    for (int i = 0; i < 100; i++) {
        miangin += carsSpeeds[i];
    }
    miangin /= 100;
    
    int countFined = 0;
    for (int i = 0; i < 100; i++) {
        if (carsSpeeds[i] > miangin + 10) countFined++;
    }
    
    printf("%d km/h\n", miangin);
    printf("%d", countFined);

    return 0;
}